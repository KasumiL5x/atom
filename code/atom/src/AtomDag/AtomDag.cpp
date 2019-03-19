#include "AtomDag.hpp"
#include <maya/MItDag.h>
#include <maya/MDagPath.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MEventMessage.h>
#include <maya/MItDependencyNodes.h>
#include "Nodes/Mesh.hpp"
#include "Nodes/Camera.hpp"
#include "Nodes/Light.hpp"
#include "Nodes/Texture.hpp"
#include "Nodes/Material.hpp"
#include "Nodes/Utility.hpp"
#include "Nodes/Annotation.hpp"
#include "Nodes/Curve.hpp"
#include "../MTLog.hpp"

using namespace atom;
using namespace atom::dag;

AtomDag::AtomDag() : initialized_(false), root_(nullptr), nodeAddedCbId_(0), nodeRemovedCbId_(0), nodeAddedIdleCbId_(0), connectionCbId_(0), childAddedCbId_(0) {
}

AtomDag::~AtomDag() {
	uninitialize();
}

bool AtomDag::initialize() {
	if( initialized_ ) {
		return false;
	}

	// populate ignore lists
	ignoreNames_.insert("|groundPlane_transform");
	ignoreNames_.insert("|top");
	ignoreNames_.insert("|front");
	ignoreNames_.insert("|side");
	ignoreNames_.insert("initialParticleSE");
	ignoreNames_.insert("|shaderBallGeom1");
	ignoreNames_.insert("|shaderBallGeom1|shaderBallGeomShape1");
	ignoreNames_.insert("|shaderBallCamera1");
	ignoreNames_.insert("|shaderBallCamera1|shaderBallCameraShape1");
	ignoreNames_.insert("|MayaMtlView_FillLight1"); // i have no clue what this is
	ignoreNames_.insert("|MayaMtlView_RimLight1"); // see above
	ignoreNames_.insert("|MayaMtlView_KeyLight1"); // and again
	ignoreTypes_.insert(MFn::kSelectionListOperator);
	ignoreTypes_.insert(MFn::kObjectTypeFilter);
	ignoreTypes_.insert(MFn::kObjectMultiFilter);
	ignoreTypes_.insert(MFn::kObjectRenderFilter);
	ignoreTypes_.insert(MFn::kNodeGraphEditorBookmarks);

	// callbacks
	nodeAddedCbId_ = MDGMessage::addNodeAddedCallback([](MObject& node,void *clientData){
		reinterpret_cast<AtomDag*>(clientData)->MayaNodeAddedCallback(node);
	}, kDefaultNodeType, this);
	nodeRemovedCbId_ = MDGMessage::addNodeRemovedCallback([](MObject& node, void* clientData){
		reinterpret_cast<AtomDag*>(clientData)->MayaNodeRemovedCallback(node);
	}, kDefaultNodeType, this);
	connectionCbId_ = MDGMessage::addConnectionCallback([](MPlug& srcPlug, MPlug& destPlug, bool made, void* clientData){
		reinterpret_cast<AtomDag*>(clientData)->MayaConnectionCallback(srcPlug, destPlug, made);
	}, this);
	childAddedCbId_ = MDagMessage::addChildAddedCallback([](MDagPath& child, MDagPath& parent, void* clientData){
		reinterpret_cast<AtomDag*>(clientData)->MayaChildAddedCallback(child, parent);
	}, this);

	initialized_ = true;
	rebuild(RebuildCause::Initialized);

	return true;
}

void AtomDag::uninitialize() {
	if( !initialized_ ) {
		return;
	}

	if( childAddedCbId_ != 0 ) {
		MDagMessage::removeCallback(childAddedCbId_);
		childAddedCbId_ = 0;
	}
	if( connectionCbId_ != 0 ) {
		MDGMessage::removeCallback(connectionCbId_);
		connectionCbId_ = 0;
	}
	if( nodeRemovedCbId_ != 0 ) {
		MDGMessage::removeCallback(nodeRemovedCbId_);
		nodeRemovedCbId_ = 0;
	}
	if( nodeAddedCbId_ != 0 ) {
		MDGMessage::removeCallback(nodeAddedCbId_);
		nodeAddedCbId_ = 0;
	}

	clear();
	initialized_ = false;
}

void AtomDag::clear() {
	if( !initialized_ ) {
		return;
	}

	std::unique_lock<std::mutex> nodesLock(nodesMutex_);
	std::unique_lock<std::mutex> addedLock(nodesAddedToProcessMutex_);

	objectNodeMap_.clear();
	allCurves_.clear();
	allAnnotations_.clear();
	allUtilities_.clear();
	allLights_.clear();
	allCameras_.clear();
	allMeshes_.clear();
	allXforms_.clear();
	allNodes_.clear();
	nodesAddedToProcess_.clear();
	root_ = nullptr;
}

void AtomDag::rebuild( RebuildCause cause ) {
	if( !initialized_ ) {
		return;
	}

	clear();
	createRoot();
	processNode(root_);

	// process all textures and materials
	MItDependencyNodes it(MFn::kFileTexture); // textures
	while( !it.isDone() ) { createNode(it.thisNode()); it.next(); }
	it.reset(MFn::kShadingEngine); // materials
	while( !it.isDone() ) { createNode(it.thisNode()); it.next(); }

	// process all intermediate nodes - there is no MFn tying them that doesn't
	// capture most of the scene, so process one by one.  make sure this list
	// matches that in the createNode function.
	// primitive builders
	it.reset(MFn::kPolyCube);
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	it.reset(MFn::kPolySphere);
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	it.reset(MFn::kPolyCylinder);
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	it.reset(MFn::kPolyCone);
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	it.reset(MFn::kPolyPipe);
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	it.reset(MFn::kPolyMesh); // poly plane
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	it.reset(MFn::kPolyTorus);
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	it.reset(MFn::kPolyPyramid);
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	// mesh editing
	it.reset(MFn::kPolyNormal);
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	it.reset(MFn::kPolyNormalPerVertex);
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	it.reset(MFn::kPolySoftEdge);
	while(!it.isDone()){createNode(it.thisNode());it.next();}
	it.reset(MFn::kPolyExtrudeFacet);
	while(!it.isDone()){createNode(it.thisNode());it.next();}

	// rebuild callbacks
	for( const auto& cb : rebuildCallbacks_ ) {
		cb(cause);
	}
}

void AtomDag::print( int indent ) {
	if( !initialized_ ) {
		return;
	}
	MTLog::instance()->log("--AtomDag Debug Print--\n");
	printInternal(root_, 0, indent);
}

std::shared_ptr<Node> AtomDag::findNodeByName( const std::string& name ) {
	std::unique_lock<std::mutex> lock(nodesMutex_);
	const auto& existing = std::find_if(std::begin(allNodes_), std::end(allNodes_), [&](const std::shared_ptr<Node>& node) {
		return strcmp(name.c_str(), node->name().c_str())==0;
	});
	return (allNodes_.end() != existing) ? *existing : nullptr;
}

std::shared_ptr<Node> AtomDag::findNodeByObject( const MObjectHandle& object ) {
	std::unique_lock<std::mutex> lock(nodesMutex_);
	const auto& existing = std::find_if(std::begin(objectNodeMap_), std::end(objectNodeMap_), [&](const std::unordered_map<MObjectHandle, std::shared_ptr<Node>, MObjectHandleHasher>::value_type& it) {
		return object == it.first.object();		
	});
	return (objectNodeMap_.end() != existing) ? existing->second : nullptr;
}

void AtomDag::forAllNodes( ForAllFunc func ) {
	std::unique_lock<std::mutex> lock(nodesMutex_);
	std::for_each(std::begin(allNodes_), std::end(allNodes_), func);
}

void AtomDag::addRebuildWatcher( const OnRebuild& func ) {
	rebuildCallbacks_.push_back(func);
}

void AtomDag::addNodeAddedWatcher( const OnNodeAdded& func ) {
	nodeAddedCallbacks_.push_back(func);
}

void AtomDag::addNodeRemovedWatcher( const OnNodeRemoved& func ) {
	nodeRemovedCallbacks_.push_back(func);
}

void AtomDag::createRoot() {
	MObject object = MItDag().root();
	MDagPath path; MFnDagNode(object).getPath(path);
	auto test = shared_from_this();
	root_ = std::make_shared<Xform>(shared_from_this(), object, path);
	allNodes_.insert(root_);
	allXforms_.insert(root_);
}

void AtomDag::processNode( const std::shared_ptr<Xform>& node ) {
	MFnDagNode mayaXform(node->mayaObject());
	for( unsigned int i = 0; i < mayaXform.childCount(); ++i ) {
		auto childObject = mayaXform.child(i);
		const auto childNode = createNode(childObject);
		if( nullptr == childNode ) {
			continue;
		}
		if( DagType::Xform == childNode->type() ) {
			node->addChild(std::static_pointer_cast<Xform>(childNode));
			processNode(std::static_pointer_cast<Xform>(childNode));
		} else {
			node->addComponent(childNode);
		}
	}
}

std::shared_ptr<Node> AtomDag::createNode( MObject& object ) {
	// if the same object's node exists, ignore it.
	// this can happen with, for example, mesh instances.
	// an iterator over scene kMesh objects will return all
	// instances as separate iterations, and there's no way to
	// check which is the root easily.  they will all share the
	// same mobject, so this is a bit of a hack for it.
	const auto& existingObject = findNodeByObject(object);
	if( existingObject != nullptr ) {
		MFnDagNode dagNode(object);
		MDagPath dagPath; dagNode.getPath(dagPath);
		const std::string name = object.hasFn(MFn::kDagNode) ? dagPath.fullPathName().asChar() : MFnDependencyNode(object).name().asChar();
		MTLog::instance()->log("Ignoring " + name + " because it was instanced.\n");
		return existingObject;
	}

	MFnDagNode dagNode(object);
	if( dagNode.isIntermediateObject() ) { // ignore intermediates and instances other than the root instance
		return nullptr;
	}

	// get name from either dag node or dep node
	MDagPath dagPath; dagNode.getPath(dagPath);
	const std::string name = object.hasFn(MFn::kDagNode) ? dagPath.fullPathName().asChar() : MFnDependencyNode(object).name().asChar();

	// ignore by name and type
	if( shouldIgnoreName(name) || shouldIgnoreType(object.apiType()) ) {
		return nullptr;
	}

	switch( object.apiType() ) {
		case MFn::kTransform: {
			const auto node = std::make_shared<Xform>(shared_from_this(), object, dagPath);
			addNode(node);
			return node;
		}

		case MFn::kMesh: {
			const auto node = std::make_shared<Mesh>(shared_from_this(), object, dagPath);
			addNode(node);
			return node;
		}

		case MFn::kCamera: {
			const auto node = std::make_shared<Camera>(shared_from_this(), object, dagPath);
			addNode(node);
			return node;
		}

		case MFn::kAmbientLight:
		case MFn::kDirectionalLight:
		case MFn::kSpotLight:
		case MFn::kPointLight: {
			const auto node = std::make_shared<Light>(shared_from_this(), object, dagPath);
			addNode(node);
			return node;
		}

		case MFn::kFileTexture: {
			const auto node = std::make_shared<Texture>(shared_from_this(), object, dagPath);
			addNode(node);
			return node;
		}

		case MFn::kShadingEngine: {
			const auto node = std::make_shared<Material>(shared_from_this(), object, dagPath);
			addNode(node);
			return node;
		}

		case MFn::kAnnotation: {
			const auto node = std::make_shared<Annotation>(shared_from_this(), object, dagPath);
			addNode(node);
			return node;
		}

		case MFn::kNurbsCurve: {
			const auto node = std::make_shared<Curve>(shared_from_this(), object, dagPath);
			addNode(node);
			return node;
		}

		case MFn::kPolyCube:
		case MFn::kPolySphere:
		case MFn::kPolyCylinder:
		case MFn::kPolyCone:
		case MFn::kPolyPipe:
		case MFn::kPolyMesh: // polyPlane
		case MFn::kPolyTorus:
		case MFn::kPolyPyramid:
		case MFn::kPolyMergeVert:
		case MFn::kPolyNormal:
		case MFn::kPolyNormalPerVertex:
		case MFn::kPolySoftEdge:
		case MFn::kPolyExtrudeFacet:
		case MFn::kPolyCloseBorder: // fill hole
		case MFn::kPolyBridgeEdge: // bridge
		case MFn::kPolyBevel:
		case MFn::kPolyCut: {
			const auto node = std::make_shared<Utility>(shared_from_this(), object, dagPath);
			node->sendInitial(); // can't use shared_from_this in constructor as no strong ptr exists, so send initial in a separate function
			addNode(node);
			return node;
		}
	}

	return nullptr;
}

bool AtomDag::shouldIgnoreName( const std::string& name ) {
	return ignoreNames_.end() != std::find(std::begin(ignoreNames_), std::end(ignoreNames_), name);
}

bool AtomDag::shouldIgnoreType( MFn::Type type ) {
	return ignoreTypes_.end() != std::find(std::begin(ignoreTypes_), std::end(ignoreTypes_), type);
}

void AtomDag::addNode( const std::shared_ptr<Node>& node ) {
	std::unique_lock<std::mutex> lock(nodesMutex_);
	allNodes_.insert(node);
	objectNodeMap_[node->mayaObject()] = node;

	switch( node->type() ) {
		case DagType::Xform: { allXforms_.insert(node); break; }
		case DagType::Mesh: { allMeshes_.insert(node); break; }
		case DagType::Camera: { allCameras_.insert(node); break; }
		case DagType::Light: { allLights_.insert(node); break; }
		case DagType::Texture: { allTextures_.insert(node); break; }
		case DagType::Material: { allMaterials_.insert(node); break; }
		case DagType::Utility: { allUtilities_.insert(node); break; }
		case DagType::Annotation: { allAnnotations_.insert(node); break; }
		case DagType::Curve: { allCurves_.insert(node); break; }
	}
}

void AtomDag::printInternal( const std::shared_ptr<Xform>& node, int indent, int increment ) {
	std::string output;
	for( int i = 0; i < indent; ++i ) { output += "-"; }
	output += node->name();
	output += "(" + DagTypeToString(node->type());
	output += "children: " + std::to_string(node->children().size());
	output += ", components: " + std::to_string(node->components().size());
	output += ")\n";
	MTLog::instance()->log(output);

	for( const auto& comp : node->components() ) {
		std::string childOutput;
		for( int i = 0; i < indent+increment; ++i ) { childOutput += "-"; }
		childOutput += comp->name();
		childOutput += "(" + DagTypeToString(comp->type());
		childOutput += ")\n";
		MTLog::instance()->log(childOutput);
	}

	for( const auto& child : node->children() ) {
		printInternal(child, indent+increment, increment);
	}
}

void AtomDag::MayaNodeAddedCallback( MObject& node ) {
	// append the current node to the list of nodes to be processed
	std::unique_lock<std::mutex> lock(nodesAddedToProcessMutex_);
	nodesAddedToProcess_.push_back(node);

	// add a callback for when maya is next considered idle.  this is because some objects are not fully
	// configured at this stage (e.g. meshes that are intermediate don't have their flags set yet), and
	// therefore cannot be processed properly at this stage.  waiting until the next idle guarantees
	// they are initialized.  this callback will wait until the idle event to process all queued objects.
	if( 0 == nodeAddedIdleCbId_ ) {
		nodeAddedIdleCbId_ = MEventMessage::addEventCallback("idle", [](void* clientData) {
			reinterpret_cast<AtomDag*>(clientData)->MayaNodeAddedIdleCallback();
		}, this);
	}
}

void AtomDag::MayaNodeRemovedCallback( MObject& node ) {
	if( shouldIgnoreType(node.apiType()) ) {
		return;
	}

	const auto nodePtr = findNodeByObject(node);
	if( nullptr == nodePtr ) {
		const std::string name = node.hasFn(MFn::kDagNode) ? MFnDagNode(node).fullPathName().asChar() : MFnDependencyNode(node).name().asChar();
		MTLog::instance()->log("Tried to remove node but couldn't find it: " + name + "\n");
		return;
	}

	std::unique_lock<std::mutex> lock(nodesMutex_);

	//
	// todo: optimize below by storing links in the objects
	//

	// remove as xform
	if( nodePtr->type() == DagType::Xform ) {
		const auto nodeXformPtr = std::static_pointer_cast<Xform>(nodePtr);
		for( const auto& xform : allXforms_ ) {
			const auto xformPtr = std::static_pointer_cast<Xform>(xform);
			if( xformPtr->containsChild(nodeXformPtr) ) {
				xformPtr->removeChild(nodeXformPtr);
			}
		}
	}

	// remove as component
	if( nodePtr->type() == DagType::Annotation || nodePtr->type() == DagType::Camera || nodePtr->type() == DagType::Light || nodePtr->type() == DagType::Mesh ) {
		for( const auto& xform : allXforms_ ) {
			const auto xformPtr = std::static_pointer_cast<Xform>(xform);
			if( xformPtr->containsComponent(nodePtr) ) {
				xformPtr->removeComponent(nodePtr);
			}
		}
	}

	// remove from obj map
	objectNodeMap_.erase(nodePtr->mayaObject());

	// remove from appropriate list
	allNodes_.erase(nodePtr);
	switch( nodePtr->type() ) {
		case DagType::Xform: { allXforms_.erase(nodePtr); break; }
		case DagType::Mesh: { allMeshes_.erase(nodePtr); break; }
		case DagType::Camera: { allCameras_.erase(nodePtr); break; }
		case DagType::Light: { allLights_.erase(nodePtr); break; }
		case DagType::Texture: { allTextures_.erase(nodePtr); break; }
		case DagType::Material: { allMaterials_.erase(nodePtr); break; }
		case DagType::Utility: { allUtilities_.erase(nodePtr); break; }
		case DagType::Annotation: { allAnnotations_.erase(nodePtr); break; }
		case DagType::Curve: { allCurves_.erase(nodePtr); break; }
	}

	// utilities aren't sent to the clients
	if( DagType::Utility == nodePtr->type() ) {
		return;
	}

	// call node removed callbacks
	for( const auto& cb : nodeRemovedCallbacks_ ) {
		cb(nodePtr);
	}
}

void AtomDag::MayaNodeAddedIdleCallback() {
	std::unique_lock<std::mutex> lock(nodesAddedToProcessMutex_);

	for( auto& object : nodesAddedToProcess_ ) {

		if( shouldIgnoreType(object.apiType()) ) {
			continue;
		}
		const std::string name = object.hasFn(MFn::kDagNode) ? MFnDagNode(object).fullPathName().asChar() : MFnDependencyNode(object).name().asChar();

		if( findNodeByName(name) != nullptr ) {
			MTLog::instance()->log("Tried to add a new node but it already exists: " + name + "\n");
			continue;
		}

		if( object.hasFn(MFn::kDagNode) && name[0] != '|' ) {
			MTLog::instance()->log("Tried to add a new DAG node but it wasn't prefixed with |: " + name + "\n");
			continue;
		}

		const auto node = createNode(object);
		if( nullptr == node ) {
			continue;
		}

		if( object.hasFn(MFn::kTransform) && DagType::Xform == node->type() ) {
			// todo: loop through children - see if I have them and add them
			//       this is cuz maya calls child/parent added/removed before adding the node...
			const MFnTransform objAsXform(object);
			for( unsigned int i = 0; i < objAsXform.childCount(); ++i ) {
				const auto childNode = findNodeByObject(objAsXform.child(i));
				if( nullptr == childNode ) {
					continue;
				}
				if( DagType::Xform == childNode->type() ) {
					std::static_pointer_cast<Xform>(node)->addChild(std::static_pointer_cast<Xform>(childNode));
					childNode->forceUpdateName();
					//MTLog::instance()->log("Child added during node added: " + node->internalName() + "=>" + childNode->internalName() + "\n");
				} else {
					std::static_pointer_cast<Xform>(node)->addComponent(childNode);
					childNode->forceUpdateName();
					//MTLog::instance()->log("Component added during node added: " + node->internalName() + "=>" + childNode->internalName() + "\n");
				}
			}
		}

		if( object.hasFn(MFn::kDagNode) ) { // node is in dag, so find its parent and hook a brotha' up
			const MFnDagNode dagNode(node->dagPath());
			const std::string parentName = MFnDagNode(dagNode.parent(0)).fullPathName().asChar();
			const auto parentNode = findNodeByName(parentName);
			if( nullptr == parentNode ) {
				if( DagType::Xform == node->type() ) { // no parent is expected for child xforms of the root
					root_->addChild(std::static_pointer_cast<Xform>(node));
				} else { // but is an error for other node types
					MTLog::instance()->log("Tried to add node but couldn't find parent: " + name + "=>" + parentName + "\n");
				}
			} else {
				if( DagType::Xform == node->type() ) {
					std::static_pointer_cast<Xform>(parentNode)->addChild(std::static_pointer_cast<Xform>(node));
				} else {
					std::static_pointer_cast<Xform>(parentNode)->addComponent(node);
				}
			}
		} else { // node is not in dag, so add it to the special list
			//MTLog::instance()->log("Node is not in DAG; todo! " + node->internalName() + "\n");
		}

		// call the node added callback only if it's not a utility (as we don't send those)
		if( node->type() != DagType::Utility ) {
			for( const auto& cb : nodeAddedCallbacks_ ) {
				cb(node);
			}
		}
	}
	nodesAddedToProcess_.clear();

	// must remove!
	MEventMessage::removeCallback(nodeAddedIdleCbId_);
	nodeAddedIdleCbId_ = 0;
}

void AtomDag::MayaConnectionCallback( MPlug& srcPlug, MPlug& destPlug, bool made ) {
		// detect shader applied to mesh
		if( made && MFn::kMesh == srcPlug.node().apiType() && MFn::kShadingEngine == destPlug.node().apiType() ) {
			const char* meshName = MFnDagNode(srcPlug.node()).fullPathName().asChar(); // ensure this is the same as how ADagMesh gets its name.
			const auto adagNode = findNodeByName(meshName);
			if( nullptr == adagNode ) {
				return;
			}
			const auto meshNode = std::static_pointer_cast<Mesh>(adagNode);
			meshNode->notifyExternalChange(DagCallback::kMeshMaterialChanged, nullptr);
		}
}

void AtomDag::MayaChildAddedCallback( const MDagPath& child, const MDagPath& parent ) {
	const auto& childNode = findNodeByObject(child.node());
	if( nullptr == childNode ) {
		//MTLog::instance()->log("Tried to add a child but couldn't find child: " + std::string(child.fullPathName().asChar()) + "\n");
		return;
	}

	const auto& parentNode = (root_->mayaObject() == parent.node()) ? root_ : findNodeByObject(parent.node());
	if( nullptr == parentNode ) {
		//MTLog::instance()->log("Tried to add a child but couldn't find parent: " + std::string(parent.fullPathName().asChar()) + "\n");
		return;
	}
	if( DagType::Xform != parentNode->type() ) {
		MTLog::instance()->log("Tried to add child but parent wasn't an xform: " + std::string(parent.fullPathName().asChar()) + "\n");
		return;
	}

	if( DagType::Xform == childNode->type() ) {
		std::static_pointer_cast<Xform>(parentNode)->addChild(std::static_pointer_cast<Xform>(childNode));
		childNode->forceUpdateName();
		//MTLog::instance()->log("Child added: " + parentNode->internalName() + "=>" + childNode->internalName() + "\n");
	} else {
		std::static_pointer_cast<Xform>(parentNode)->addComponent(childNode);
		childNode->forceUpdateName();
		//MTLog::instance()->log("Child component: " + parentNode->internalName() + "=>" + childNode->internalName() + "\n");
	}
}