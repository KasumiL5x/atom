#ifndef __atom_protobuf_helper__
#define __atom_protobuf_helper__

#include <memory>
#include <string>
#include "MTLog.hpp"
#include "proto/AtomMessage.pb.h"
#include "server/Connection.hpp"
#include "AtomDag/AtomDag.hpp"
#include "proto/materials/TexturedParameter.pb.h"
#include "proto/Color.pb.h"
#include "proto/Vector3.pb.h"
#include "proto/Vector2.pb.h"
#include <maya/MColor.h>
#include <maya/MVector.h>
#include <maya/MMatrix.h>

namespace atom { namespace protohelper {

/**
	* Serializes a protobuf object into a new array.
	* @param protoObj A protobuf object that can be serialized.
	* @param outSize  Output size in bytes of the protobuf object.
	* @returns New unique_ptr to an unsigned char[] of size outSize, or nullptr upon error.
	*/
template<typename T>
static std::unique_ptr<unsigned char[]> serializeTo( const T& protoObj, int& outSize ) {
	const int byteSize = protoObj.ByteSize();
	if( byteSize <= 0 ) {
		return nullptr; // bad protobuf size
	}
	auto bytes = std::make_unique<unsigned char[]>(byteSize);
	if( !protoObj.SerializeToArray(bytes.get(), byteSize) ) {
		bytes = nullptr;
	}
	outSize = byteSize;
	return bytes;
}

/**
 * Creates a proto::TexturedParameter from an existing allocated proto::Color and texture string.
 * @param color   Allocated protobuf Color.
 * @param texture Filename of texture; can be empty.
 * @returns Allocated protobuf TexturedParameter with color and texture set.
 */
static atom::proto::materials::TexturedParameter* textureParameterFrom( atom::proto::Color* color, const std::string& texture ) {
	auto output = new atom::proto::materials::TexturedParameter();
	output->set_texture(texture);
	output->set_allocated_ascolor(color);
	return output;
}

/**
 * Creates a proto::TexturedParameter from a float and texture string.
 * @param value   Float value to set.
 * @param texture Filename of texture; can be empty.
 * @returns Allocated protobuf TexturedParameter with float and texture set.
 */
static atom::proto::materials::TexturedParameter* textureParameterFrom( float value, const std::string& texture ) {
	auto output = new atom::proto::materials::TexturedParameter();
	output->set_texture(texture);
	output->set_asfloat(value);
	return output;
}

/**
 * Creates a proto::Color from a Maya MColor.
 * @param color Maya MColor to convert.
 * @returns Allocated proto::Color with data from Maya's MColor.
 */
static atom::proto::Color* colorFrom( const MColor& color ) {
	auto output = new atom::proto::Color();
	output->set_r(color.r); output->set_g(color.g); output->set_b(color.b); output->set_a(color.a);
	return output;
}

/**
 * Creates a proto::Vector3 from a Maya MVector.
 * @param vec Maya MVector to convert.
 * @returns Allocated proto::Vector3 with data from Maya's MVector.
 */
static atom::proto::Vector3* vector3From( const MVector& vec ) {
	auto output = new atom::proto::Vector3();
	output->set_x((float)vec.x); output->set_y((float)vec.y); output->set_z((float)vec.z);
	return output;
}

/**
 * Creates a proto::Vector2 from given values.
 * @param x X value.
 * @param y Y value.
 * @returns Allocated proto::Vector2 with given data set.
 */
static atom::proto::Vector2* vector2From( float x, float y ) {
	auto output = new atom::proto::Vector2();
	output->set_x(x); output->set_y(y);
	return output;
}

static void sendTo( const atom::proto::AtomMessage& msg, const std::shared_ptr<Connection>& connection ){
	int byteSize;
	const auto bytes = protohelper::serializeTo(msg, byteSize);
	if( bytes != nullptr ) {
		connection->write(atom::Message::createOutgoing(bytes.get(), byteSize));
	} else {
		MTLog::instance()->log("CameraWatcher::sendCameraData serializeTo failed.\n");
	}
}

static atom::proto::Scene* createSceneFrom( const std::shared_ptr<dag::Node>& node, atom::proto::Scene_Reason reason ) {
	atom::proto::Scene* protoScene = new atom::proto::Scene();
	protoScene->set_transferreason(reason);
	if( strcmp(node->name().c_str(), "")==0 ) {
		return nullptr; // don't send objects with no name
	}
	switch( node->type() ) {
		case atom::dag::DagType::Xform: {
			auto protoXform = protoScene->add_transforms();
			protoXform->set_name(node->name());
			break;
		}
		case atom::dag::DagType::Mesh: {
			auto protoMesh = protoScene->add_meshes();
			protoMesh->set_name(node->name());
			break;
		}
		case atom::dag::DagType::Light: {
			auto protoLight = protoScene->add_lights();
			protoLight->set_name(node->name());
			break;
		}
		case atom::dag::DagType::Camera: {
			auto protoCamera = protoScene->add_cameras();
			protoCamera->set_name(node->name());
			break;
		}
		case atom::dag::DagType::Material: {
			auto protoMaterial = protoScene->add_materials();
			protoMaterial->set_name(node->name());
			break;
		}
		case atom::dag::DagType::Texture: {
			auto protoTexture = protoScene->add_textures();
			protoTexture->set_name(node->name());
			break;
		}
		case atom::dag::DagType::Annotation: {
			auto protoAnnotation = protoScene->add_annotations();
			protoAnnotation->set_name(node->name());
			break;
		}
		case atom::dag::DagType::Curve: {
			auto protoCurve = protoScene->add_curves();
			protoCurve->set_name(node->name());
			break;
		}
		case atom::dag::DagType::Invalid: {
			// ignore
			delete protoScene; protoScene = nullptr;
			return nullptr;
		}
	}
	return protoScene;
}

static atom::proto::Scene* createFullScene( const std::shared_ptr<dag::AtomDag>& adag, atom::proto::Scene_Reason reason ) {
	atom::proto::Scene* protoScene = new atom::proto::Scene();
	protoScene->set_transferreason(reason);
	adag->forAllNodes([=](const std::shared_ptr<dag::Node>& node) {
		if( strcmp(node->name().c_str(), "")==0 ) {
			return; // don't send objects with no name (this can happen if shadingEngines have no surfaceShader, for example)
		}

		switch( node->type() ) {
			case atom::dag::DagType::Xform: {
				auto protoXform = protoScene->add_transforms();
				protoXform->set_name(node->name());
				break;
			}
			case atom::dag::DagType::Mesh: {
				auto protoMesh = protoScene->add_meshes();
				protoMesh->set_name(node->name());
				break;
			}
			case atom::dag::DagType::Light: {
				auto protoLight = protoScene->add_lights();
				protoLight->set_name(node->name());
				break;
			}
			case atom::dag::DagType::Camera: {
				auto protoCamera = protoScene->add_cameras();
				protoCamera->set_name(node->name());
				break;
			}
			case atom::dag::DagType::Material: {
				auto protoMaterial = protoScene->add_materials();
				protoMaterial->set_name(node->name());
				break;
			}
			case atom::dag::DagType::Texture: {
				auto protoTexture = protoScene->add_textures();
				protoTexture->set_name(node->name());
				break;
			}
			case atom::dag::DagType::Annotation: {
				auto protoAnnotation = protoScene->add_annotations();
				protoAnnotation->set_name(node->name());
				break;
			}
			case atom::dag::DagType::Curve: {
				auto protoCurve = protoScene->add_curves();
				protoCurve->set_name(node->name());
				break;
			}
			case atom::dag::DagType::Invalid: {
				// ignore
				break;
			}
		}
	});
	return protoScene;
}

static atom::proto::Matrix* matrixFrom( const MMatrix& matrix ) {
	float xform[4][4] = {0.0f,};
	matrix.get(xform);
	auto atomWorld = new atom::proto::Matrix();
	atomWorld->set_cols(4);
	atomWorld->set_rows(4);
	for( unsigned int j = 0; j < 4; ++j ) {
		for( unsigned int i = 0; i <4; ++i ) {
			atomWorld->add_m(xform[j][i]);
		}
	}
	return atomWorld;
}

static void sendMatrixChanged( const std::shared_ptr<dag::Node>& node, const MMatrix& matrix, const std::shared_ptr<Connection>& connection ) {
	auto protoMatrix = new atom::proto::MatrixChanged();
	protoMatrix->set_objectname(node->name());
	protoMatrix->set_allocated_matrix(protohelper::matrixFrom(matrix));
	proto::AtomMessage msg;
	msg.set_allocated_matrixchanged(protoMatrix);
	protohelper::sendTo(msg, connection);
}

static void sendNameChanged( const std::shared_ptr<dag::Node>& node, const std::shared_ptr<Connection>& connection ) {
	auto atomName = new atom::proto::NameChanged();
	atomName->set_oldname(node->lastName());
	atomName->set_newname(node->name());
	atom::proto::AtomMessage msg;
	msg.set_allocated_namechanged(atomName);
	protohelper::sendTo(msg, connection);
}

static void sendVisibilityChanged( const std::shared_ptr<dag::Node>& node, const std::shared_ptr<Connection>& connection ) {
	auto atomVis = new atom::proto::VisibilityChanged();
	atomVis->set_objectname(node->name());
	atomVis->set_visible(node->isVisible());
	atom::proto::AtomMessage msg;
	msg.set_allocated_visibilitychanged(atomVis);
	protohelper::sendTo(msg, connection);
}

}
}

#endif /* __atom_protobuf_helper__ */