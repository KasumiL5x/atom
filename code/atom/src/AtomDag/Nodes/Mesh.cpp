#include "Mesh.hpp"
#include "Xform.hpp"
#include <maya/MStringArray.h>
#include <maya/MFnMesh.h>
#include <maya/MItMeshFaceVertex.h>
#include <maya/MGlobal.h>
#include <maya/MSelectionList.h>
#include <maya/MItGeometry.h>
#include "../../MTLog.hpp"

using namespace atom::dag;

Mesh::Mesh( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path ) : Node(adag, object, path),
	isMeshDirty_(true) {
	type_ = DagType::Mesh;
	meshDirtyEvent_.set();
}

Mesh::~Mesh() {
}

void Mesh::notifyExternalChange( DagCallback type, std::shared_ptr<Node> instigator ) {
	addChange(type, instigator);
	meshDirtyEvent_.waitOne();
	isMeshDirty_ = true;
	meshDirtyEvent_.set();
}

std::string Mesh::getMaterialName() const {
	MFnMesh mesh(dagPath_);
	// retrieve all polygon->shading ground connections (although we only care about the first one)
	MObjectArray shaders;
	MIntArray indices;
	mesh.getConnectedShaders(0, shaders, indices);
	if( !shaders.length() ) {
		return ""; // no shading group assignments
	}

	// trace the surfaceShader plug from the shading group
	MFnDependencyNode shadingGroup(shaders[0]);
	return shadingGroup.name().asChar();
}

void Mesh::lockMeshData() {
	meshDirtyEvent_.waitOne();
	meshDirtyEvent_.reset();
	rebuildMeshData();
}

void Mesh::unlockMeshData() {
	meshDirtyEvent_.set();
}

const MStringArray& Mesh::getUVSetNames() const {
	return uvSetNames_;
}

const std::vector<int>& Mesh::getVertexIndices() const {
	return vertexIndex_;
}

const std::vector<int>& Mesh::getVertexMayaIndices() const {
	return vertexMayaIndex_;
}

const std::vector<MPoint>& Mesh::getVertexPositions() const {
	return vertexPosition_;
}

const std::vector<MFloatVector>& Mesh::getVertexNormals() const {
	return vertexNormal_;
}

const std::vector<std::vector<std::pair<float, float>>>& Mesh::getVertexTexcoords() const {
	return vertexTexcoord_;
}

const std::vector<std::vector<int>>& Mesh::getVertexTexcoordIndices() const {
	return vertexTexcoordIndices_;
}

const std::vector<MFloatVectorArray>& Mesh::getVertexTangents() const {
	return vertexTangent_;
}

const std::vector<MFloatVectorArray>& Mesh::getVertexBinormals() const {
	return vertexBinormal_;
}

const MStringArray& Mesh::getColorSetNames() const {
	return colorSetNames_;
}

const std::vector<MColorArray>& Mesh::getVertexColors() const {
	return vertexColors_;
}

const MIntArray& Mesh::getIndices() const {
	return indices_;
}

std::set<int> Mesh::getVertexIndicesChanged() {
	std::unique_lock<std::mutex> lock(vertexIndicesChangedMutex_);
	return vertexIndicesChanged_;
}

void Mesh::rebuildMeshData() {
	if( !isMeshDirty_ ) {
		return;
	}
	isMeshDirty_ = false;

	const MFnMesh mesh(dagPath_); // dag path will fail to get data correctly

	// clear existing data
	uvSetNames_.clear();
	vertexIndex_.clear();
	vertexMayaIndex_.clear();
	vertexPosition_.clear();
	vertexNormal_.clear();
	vertexTexcoord_.clear();
	vertexTexcoordIndices_.clear();
	vertexTangent_.clear();
	vertexBinormal_.clear();
	colorSetNames_.clear();
	vertexColors_.clear();
	indices_.clear();

	// uv set names
	mesh.getUVSetNames(uvSetNames_);
	// color set names
	mesh.getColorSetNames(colorSetNames_);

	// get all face vertices
	int physicalIndex = 0;
	MItMeshFaceVertex it(dagPath_);
	while( !it.isDone() ) {
		// physical index
		vertexIndex_.push_back(physicalIndex++);
		// maya vertex index
		vertexMayaIndex_.push_back(it.vertId());
		// position
		vertexPosition_.push_back(it.position(MSpace::kObject));
		// normal
		MVector nrm; it.getNormal(nrm, MSpace::kObject); vertexNormal_.push_back(nrm);
		// texcoord/tangent/binormal
		vertexTexcoord_.push_back(std::vector<std::pair<float, float>>()); auto& tex = vertexTexcoord_.back();
		vertexTexcoordIndices_.push_back(std::vector<int>()); auto& texIdx = vertexTexcoordIndices_.back();
		vertexTangent_.push_back(MFloatVectorArray()); auto& tan = vertexTangent_.back();
		vertexBinormal_.push_back(MFloatVectorArray()); auto& bin = vertexBinormal_.back();
		for( unsigned int i = 0; i < uvSetNames_.length(); ++i ) {
			if( it.hasUVs(uvSetNames_[i]) ) {
				//float2 uv; it.getUV(uv, &uvSetNames_[i]); tex.push_back({uv[0], uv[1]});
				int uvIndex; it.getUVIndex(uvIndex, &uvSetNames_[i]); texIdx.push_back(uvIndex);
				float texU, texV; mesh.getUV(uvIndex, texU, texV, &uvSetNames_[i]); tex.push_back({texU, texV});
				//tex.push_back({texcoordUs_[i][uvIndex], texcoordVs_[i][uvIndex]});
				tan.append(it.getTangent(MSpace::kObject, &uvSetNames_[i]));
				bin.append(it.getBinormal(MSpace::kObject, &uvSetNames_[i]));
			} else {
				tex.push_back({0.0f, 0.0f});
				texIdx.push_back(-1);
				tan.append(MFloatVector(0.0f, 0.0f, 0.0f));
				bin.append(MFloatVector(0.0f, 0.0f, 0.0f));
			}
		}
		// colors
		const MColor FALLBACK_COLOR(0.0f, 0.0f, 0.0f, 1.0f);
		vertexColors_.push_back(MColorArray()); auto& clr = vertexColors_.back();
		for( unsigned int i = 0; i < colorSetNames_.length(); ++i ) {
			if( it.hasColor() ) {
				int colorIndex; it.getColorIndex(colorIndex, &colorSetNames_[i]);
				if( -1 == colorIndex ) { // can happen if exists but not applied
					clr.append(FALLBACK_COLOR);
				} else {
					MColor mayaColor; it.getColor(mayaColor, &colorSetNames_[i]);
					clr.append(mayaColor);
				}
			} else {
				clr.append(FALLBACK_COLOR);
			}
		}

		it.next();
	}

	// indices
	MIntArray mia1;
	mesh.getTriangleOffsets(mia1, indices_);
}

std::string Mesh::getNameInternal() const {
	return dagPath_.fullPathName().asChar();
}

void Mesh::OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) {
	if( !((msg & MNodeMessage::kAttributeSet) && (msg & MNodeMessage::kIncomingDirection)) ) {
		return;
	}

	const std::string info = plug.info().asChar();

	const std::string plugName = plug.partialName().asChar();

	if( strcmp(plugName.c_str(), "o")==0 ) {
		addChange(DagCallback::kMeshGeometryChanged, nullptr);
		meshDirtyEvent_.waitOne();
		isMeshDirty_ = true;
		meshDirtyEvent_.set();
	}

	if( plugName.find("pt[") != std::string::npos ) {
		const auto openBracket = plugName.find_last_of('[');
		const auto closeBracket = plugName.find_last_of(']');
		const std::string numStr = plugName.substr(openBracket+1, closeBracket - openBracket - 1);
		std::unique_lock<std::mutex> lock(vertexIndicesChangedMutex_);
		vertexIndicesChanged_.insert(std::atoi(numStr.c_str()));
		justDirty();
		meshDirtyEvent_.waitOne();
		isMeshDirty_ = true;
		meshDirtyEvent_.set();
	}

	if( strcmp(plugName.c_str(), "pv")==0 ) { // uvPivot/pv
		MSelectionList sel;
		MGlobal::getActiveSelectionList(sel);
		bool inserted = false;
		if( sel.length() > 0 ) {
			MDagPath theDagPath;
			MObject theComponents;
			sel.getDagPath(0, theDagPath, theComponents);
			if( !theComponents.isNull() ) {
				MItGeometry it(theDagPath, theComponents);
				while( !it.isDone() ) {
					const int idx = it.index();
					vertexIndicesChanged_.insert(idx);
					inserted = true;
					it.next();
				}
			}
		}

		if( inserted ) {
			justDirty();
			meshDirtyEvent_.waitOne();
			isMeshDirty_ = true;
			meshDirtyEvent_.set();
		}
	}
}

void Mesh::OnPlugDirtied( MObject& node, MPlug& plug ) {
}

void Mesh::justBeforeNotify() {
	std::unique_lock<std::mutex> lock(vertexIndicesChangedMutex_);
	if( vertexIndicesChanged_.size() <= 0 ) {
		return;
	}

	addChange(DagCallback::kMeshPointsChanged, nullptr);
}

void Mesh::justAfterNotify() {
	std::unique_lock<std::mutex> lock(vertexIndicesChangedMutex_);
	vertexIndicesChanged_.clear();
}

void Mesh::onTranslate() {
	if( !hasChange(DagCallback::kMatrixChanged, nullptr) ) {
		addChange(DagCallback::kMatrixChanged, nullptr);
	}
}

void Mesh::onRotate() {
	if( !hasChange(DagCallback::kMatrixChanged, nullptr) ) {
		addChange(DagCallback::kMatrixChanged, nullptr);
	}
}

void Mesh::onScale() {
	if( !hasChange(DagCallback::kMatrixChanged, nullptr) ) {
		addChange(DagCallback::kMatrixChanged, nullptr);
	}
}