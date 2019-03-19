#include "MeshWatcher.hpp"
#include "../../MTLog.hpp"
#include "../../server/Connection.hpp"
#include "../../AtomDag/AtomDag.hpp"
#include "../../AtomDag/Nodes/Node.hpp"
#include "../../AtomDag/Nodes/Mesh.hpp"
#include "../../AtomDag/Nodes/Xform.hpp"
#include "../../AtomDag/Nodes/Utility.hpp"
#include "../../proto/AtomMessage.pb.h"
#include "../../ProtobufHelper.hpp"
#include <maya/MFnMesh.h>
#include <maya/MFloatVectorArray.h>
#include <maya/MFloatArray.h>
#include <maya/MItMeshFaceVertex.h>

using namespace atom;
using namespace atom::dag;

MeshWatcher::MeshWatcher()
	: IWatchHandler() {
}

MeshWatcher::~MeshWatcher() {
}

bool MeshWatcher::handle( std::shared_ptr<Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) {
	if( node->type() != DagType::Mesh ) {
		MTLog::instance()->log("MeshWatcher::handle: ADagNode type was not kMesh!\n");
		return false;
	}

	const auto mesh = std::static_pointer_cast<Mesh>(node);

	// send initial data
	sendMesh(mesh, connection);

	// add watch handler
	std::shared_ptr<Connection> copyOfConnection = connection;
	node->addWatcher([this, copyOfConnection, mesh](DagCallback type, const std::shared_ptr<Node>& node, std::shared_ptr<Node> instigator) {
		if( nullptr == node ) {
			MTLog::instance()->log("MeshWatcher::handle's callback delivered a null node.\n");
			return false;
		}

		// this will trigger the watcher callback to be removed inside of ADagNode on the next notifyWatchers call
		if( !copyOfConnection->isActive() ) {
			return false;
		}

		switch( type ) {
			case DagCallback::kNameChanged: {
				protohelper::sendNameChanged(node, copyOfConnection);
				break;
			}
			case DagCallback::kVisibilityChanged: {
				protohelper::sendVisibilityChanged(node, copyOfConnection);
				break;
			}

			case DagCallback::kMeshPointsChanged: {
				if( instigator != nullptr && DagType::Utility == instigator->type() ) {
					sendMeshPoints(mesh, copyOfConnection, std::static_pointer_cast<Utility>(instigator)->getComponentIndices());
				} else {
					sendMeshPoints(mesh, copyOfConnection, std::static_pointer_cast<Mesh>(node)->getVertexIndicesChanged());
				}
				break;
			}

			case DagCallback::kMeshGeometryChanged: {
				sendMeshGeometry(mesh, copyOfConnection);
				break;
			}

			case DagCallback::kMeshMaterialChanged: {
				sendMeshMaterial(mesh, copyOfConnection);
				break;
			}

			case DagCallback::kMatrixChanged: {
				protohelper::sendMatrixChanged(mesh, mesh->transformationMatrix(true), copyOfConnection);
				break;
			}

			default: {
				MTLog::instance()->log("MeshWatcher::handle's callback type was unhandled.\n");
				break;
			}
		}

		return true;
	}, copyOfConnection->getClientName());

	return true;
}

void MeshWatcher::sendMesh( const std::shared_ptr<Mesh>& mesh, const std::shared_ptr<Connection>& connection ) {
	auto atomMesh = new atom::proto::meshes::Mesh();
	atomMesh->set_name(mesh->name());
	atomMesh->set_materialname(mesh->getMaterialName());
	atomMesh->set_allocated_world(protohelper::matrixFrom(mesh->transformationMatrix(true)));
	atomMesh->set_initialvisibility(mesh->isVisible());

	mesh->lockMeshData();
	const auto& uvSetNames = mesh->getUVSetNames();
	const auto& vertexIndices = mesh->getVertexIndices();
	const auto& vertexPositions = mesh->getVertexPositions();
	const auto& vertexNormals = mesh->getVertexNormals();
	const auto& vertexUVs = mesh->getVertexTexcoords();
	const auto& vertexTangents = mesh->getVertexTangents();
	const auto& vertexBinormals = mesh->getVertexBinormals();
	const auto& colorSetNames = mesh->getColorSetNames();
	const auto& vertexColors = mesh->getVertexColors();
	const auto& indices = mesh->getIndices();
	// uv set names
	for( unsigned int i = 0; i < uvSetNames.length(); ++i ) {
		atomMesh->add_texcoordsetnames(uvSetNames[i].asChar());
	}
	// vertex data
	for( size_t i = 0; i < vertexPositions.size(); ++i ) {
		auto vtx = atomMesh->add_vertices();
		vtx->set_index(vertexIndices[i]);
		vtx->set_allocated_position(protohelper::vector3From(vertexPositions[i]));
		vtx->set_allocated_normal(protohelper::vector3From(vertexNormals[i]));
		for( unsigned int j = 0; j < (unsigned int)vertexUVs[i].size(); ++j ) { // unsigned int because [] below in Maya uses it
			auto tex = vtx->add_texcoord();
			auto tan = vtx->add_tangent();
			auto bin = vtx->add_binormal();
			tex->set_x(vertexUVs[i][j].first); tex->set_y(vertexUVs[i][j].second);
			tan->set_x(vertexTangents[i][j].x); tan->set_y(vertexTangents[i][j].y); tan->set_z(vertexTangents[i][j].z);
			bin->set_x(vertexBinormals[i][j].x); bin->set_y(vertexBinormals[i][j].y); bin->set_z(vertexBinormals[i][j].z);
		}
		for( unsigned int j = 0; j < colorSetNames.length(); ++j ) {
			auto clr = vtx->add_color();
			clr->set_r(vertexColors[i][j].r); clr->set_g(vertexColors[i][j].g); clr->set_b(vertexColors[i][j].b); clr->set_a(vertexColors[i][j].a);
		}
	}
	// index data
	for( unsigned int i = 0; i < indices.length(); ++i ) {
		atomMesh->add_indices(indices[i]);
	}
	mesh->unlockMeshData();

	atom::proto::AtomMessage msg;
	msg.set_allocated_mesh(atomMesh);
	protohelper::sendTo(msg, connection);
}

void MeshWatcher::sendMeshPoints( const std::shared_ptr<Mesh>& mesh, const std::shared_ptr<Connection>& connection, const std::set<int>& indicesData ) {
	auto pointsMsg = new atom::proto::meshes::MeshPointsChanged();
	pointsMsg->set_meshname(mesh->name());

	mesh->lockMeshData();
	const auto& vertexIndices = mesh->getVertexIndices();
	const auto& vertexMayaIndices = mesh->getVertexMayaIndices();
	const auto& vertexPositions = mesh->getVertexPositions();
	const auto& vertexNormals = mesh->getVertexNormals();
	const auto& vertexUVs = mesh->getVertexTexcoords();
	const auto& vertexTangents = mesh->getVertexTangents();
	const auto& vertexBinormals = mesh->getVertexBinormals();
	const auto& colorSetNames = mesh->getColorSetNames();
	const auto& vertexColors = mesh->getVertexColors();
	const auto& indices = mesh->getIndices();
	//
	for( const auto& idx : indicesData ) {
		for( size_t i = 0; i < vertexMayaIndices.size(); ++i ) {
			if( vertexMayaIndices[i] == idx ) {
				auto vtx = pointsMsg->add_vertices();
				vtx->set_index(vertexIndices[i]);
				vtx->set_allocated_position(protohelper::vector3From(vertexPositions[i]));
				vtx->set_allocated_normal(protohelper::vector3From(vertexNormals[i]));
				for( unsigned int j = 0; j < (unsigned int)vertexUVs[i].size(); ++j ) { // unsigned int because [] below in Maya uses it
					auto tex = vtx->add_texcoord();
					auto tan = vtx->add_tangent();
					auto bin = vtx->add_binormal();
					tex->set_x(vertexUVs[i][j].first); tex->set_y(vertexUVs[i][j].second);
					tan->set_x(vertexTangents[i][j].x); tan->set_y(vertexTangents[i][j].y); tan->set_z(vertexTangents[i][j].z);
					bin->set_x(vertexBinormals[i][j].x); bin->set_y(vertexBinormals[i][j].y); bin->set_z(vertexBinormals[i][j].z);
				}
				for( unsigned int j = 0; j < colorSetNames.length(); ++j ) {
					auto clr = vtx->add_color();
					clr->set_r(vertexColors[i][j].r); clr->set_g(vertexColors[i][j].g); clr->set_b(vertexColors[i][j].b); clr->set_a(vertexColors[i][j].a);
				}
			}
		}
	}
	mesh->unlockMeshData();

	atom::proto::AtomMessage msg;
	msg.set_allocated_meshpointschanged(pointsMsg);
	protohelper::sendTo(msg, connection);
}

void MeshWatcher::sendMeshGeometry( const std::shared_ptr<Mesh>& mesh, const std::shared_ptr<Connection>& connection ) {
	auto atomGeom = new atom::proto::meshes::MeshGeometryChanged();
	atomGeom->set_meshname(mesh->name());

	mesh->lockMeshData();
	const auto& vertexIndices = mesh->getVertexIndices();
	const auto& vertexPositions = mesh->getVertexPositions();
	const auto& vertexNormals = mesh->getVertexNormals();
	const auto& vertexUVs = mesh->getVertexTexcoords();
	const auto& vertexTangents = mesh->getVertexTangents();
	const auto& vertexBinormals = mesh->getVertexBinormals();
	const auto& colorSetNames = mesh->getColorSetNames();
	const auto& vertexColors = mesh->getVertexColors();
	const auto& indices = mesh->getIndices();
	// vertex data
	for( size_t i = 0; i < vertexPositions.size(); ++i ) {
		auto vtx = atomGeom->add_vertices();
		vtx->set_index(vertexIndices[i]);
		vtx->set_allocated_position(protohelper::vector3From(vertexPositions[i]));
		vtx->set_allocated_normal(protohelper::vector3From(vertexNormals[i]));
		for( unsigned int j = 0; j < (unsigned int)vertexUVs[i].size(); ++j ) { // unsigned int because [] below in Maya uses it
			auto tex = vtx->add_texcoord();
			auto tan = vtx->add_tangent();
			auto bin = vtx->add_binormal();
			tex->set_x(vertexUVs[i][j].first); tex->set_y(vertexUVs[i][j].second);
			tan->set_x(vertexTangents[i][j].x); tan->set_y(vertexTangents[i][j].y); tan->set_z(vertexTangents[i][j].z);
			bin->set_x(vertexBinormals[i][j].x); bin->set_y(vertexBinormals[i][j].y); bin->set_z(vertexBinormals[i][j].z);
		}
		for( unsigned int j = 0; j < colorSetNames.length(); ++j ) {
			auto clr = vtx->add_color();
			clr->set_r(vertexColors[i][j].r); clr->set_g(vertexColors[i][j].g); clr->set_b(vertexColors[i][j].b); clr->set_a(vertexColors[i][j].a);
		}
	}
	// index data
	for( unsigned int i = 0; i < indices.length(); ++i ) {
		atomGeom->add_indices(indices[i]);
	}
	mesh->unlockMeshData();

	atom::proto::AtomMessage msg;
	msg.set_allocated_meshgeometrychanged(atomGeom);
	protohelper::sendTo(msg, connection);
}

void MeshWatcher::sendMeshMaterial( const std::shared_ptr<Mesh>& mesh, const std::shared_ptr<Connection>& connection ) {
	auto atomMat = new atom::proto::meshes::MeshMaterialChanged();
	atomMat->set_meshname(mesh->name());
	atomMat->set_materialname(mesh->getMaterialName());

	atom::proto::AtomMessage msg;
	msg.set_allocated_meshmaterialchanged(atomMat);
	protohelper::sendTo(msg, connection);
}
