#include "Utility.hpp"
#include <maya/MFnDependencyNode.h>
#include <maya/MPlugArray.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnComponentListData.h>
#include <maya/MFnSingleIndexedComponent.h>
#include "../AtomDag.hpp"
#include "Mesh.hpp"
#include "../../MTLog.hpp"

using namespace atom::dag;

Utility::Utility( const std::shared_ptr<AtomDag>& atomdag, MObject& object, MDagPath& path ) : Node(atomdag, object, path), dagNode_(nullptr) {
	type_ = DagType::Utility;
	dagNodeEvent_.set();
}

void Utility::sendInitial() {
	dagNodeEvent_.waitOne();
	if( updateInternalLink() ) {
		sendBasedOnNodeType();
	}
	dagNodeEvent_.set();
}

Utility::~Utility() {
}

std::set<int> Utility::getComponentIndices() {
	std::unique_lock<std::mutex> lock(cachedComponentIndicesMutex_);
	return cachedComponentIndices_;
}

std::set<int> Utility::getComponentIndicesInternal() const {
	std::set<int> componentIndices;
	const auto inputComponents = MFnDependencyNode(mayaObject_).findPlug("inputComponents");
	MObject icData; inputComponents.getValue(icData);
	MFnComponentListData componentsList(icData);
	for( unsigned int i = 0; i < componentsList.length(); ++i ) {
		const auto component = componentsList[i];
		if( !component.hasFn(MFn::kSingleIndexedComponent) ) {
			throw;
		}
		MFnSingleIndexedComponent single(component);
		MIntArray elements;
		single.getElements(elements);
		for( unsigned int j = 0; j < elements.length(); ++j ) {
			componentIndices.insert(elements[j]);
		}
	}
	return componentIndices;
}

std::string Utility::getOutputNodeName() const {
	// traces from this node's output plug until it finds a mesh, assuming that
	// following nodes also use the same output naming convention.  will eventually
	// terminate and return "" if no output was found.
	MPlug currentPlug = MFnDependencyNode(mayaObject_).findPlug("output");
	while( true ) {
		const std::string currentPlugName = currentPlug.name().asChar();
		MPlugArray destinations;
		currentPlug.connectedTo(destinations, true, true); // todo: fix
		MObject nextPlugToTry = MObject::kNullObj;
		for( unsigned int i = 0; i < destinations.length(); ++i ) {
			if( !destinations[i].node().hasFn(MFn::kMesh) ) {
				nextPlugToTry = destinations[i].node();
				continue;
			}
			const std::string meshName = MFnDagNode(destinations[i].node()).fullPathName().asChar();
			if( meshName.empty() ) {
				continue;
			}
			return meshName.substr(0, meshName.find_last_of('.'));
		}
		if( nextPlugToTry != MObject::kNullObj ) {
			currentPlug = MFnDependencyNode(nextPlugToTry).findPlug("output");
		} else {
			break; // no output connections
		}
	}
	return "";
}

bool Utility::updateInternalLink() {
	const std::string outputNodeName = getOutputNodeName();
	if( nullptr == dagNode_ || strcmp(outputNodeName.c_str(), dagNode_->name().c_str()) != 0 ) {
		dagNode_ = adag_->findNodeByName(outputNodeName);
	}
	return (dagNode_ != nullptr) && (DagType::Mesh==dagNode_->type());
}

void Utility::sendBasedOnNodeType() {
	if( nullptr == dagNode_ ) {
		return;
	}

	switch( mayaObject_.apiType() ) {
		case MFn::kPolyCube:
		case MFn::kPolySphere:
		case MFn::kPolyCylinder:
		case MFn::kPolyCone:
		case MFn::kPolyPipe:
		case MFn::kPolyMesh:
		case MFn::kPolyTorus:
		case MFn::kPolyPyramid:
		case MFn::kPolyCloseBorder:
		case MFn::kPolyBridgeEdge:
		case MFn::kPolyBevel:
		case MFn::kPolyCut:
		case MFn::kPolyNormalPerVertex:
		case MFn::kPolyMergeVert:
		case MFn::kPolyExtrudeFacet: {
			std::static_pointer_cast<Mesh>(dagNode_)->notifyExternalChange(DagCallback::kMeshGeometryChanged, shared_from_this());
			break;
		}
		case MFn::kPolySoftEdge:
		case MFn::kPolyNormal: {
			const auto componentIndices = getComponentIndicesInternal();
			if( !componentIndices.empty() ) {
				std::unique_lock<std::mutex> lock(cachedComponentIndicesMutex_);
				cachedComponentIndices_.insert(std::begin(componentIndices), std::end(componentIndices));
			}
			break;
		}

		default: {
			MTLog::instance()->log("Utility::sendBasedOnNodeType didn't handle a case.\n");
			break;
		}
	}
}

std::string Utility::getNameInternal() const {
	return MFnDependencyNode(mayaObject_).name().asChar();
}

void Utility::OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) {
	if( !((msg & MNodeMessage::kAttributeSet || msg & MNodeMessage::kOtherPlugSet) && (msg & MNodeMessage::kIncomingDirection)) ) {
		return;
	}

	dagNodeEvent_.waitOne();
	if( updateInternalLink() ) {
		sendBasedOnNodeType();
	}
	dagNodeEvent_.set();
}

void Utility::OnPlugDirtied( MObject& node, MPlug& plug ) {
}

void Utility::justBeforeNotify() {
	dagNodeEvent_.waitOne();
	if( dagNode_ != nullptr && DagType::Mesh == dagNode_->type() ) {
		std::unique_lock<std::mutex> compLock(cachedComponentIndicesMutex_);
		if( !cachedComponentIndices_.empty() ) {
			std::static_pointer_cast<Mesh>(dagNode_)->notifyExternalChange(DagCallback::kMeshPointsChanged, shared_from_this());
		}
	}
	dagNodeEvent_.set();
}

void Utility::justAfterNotify() {
	std::unique_lock<std::mutex> compLock(cachedComponentIndicesMutex_);
	cachedComponentIndices_.clear();
}