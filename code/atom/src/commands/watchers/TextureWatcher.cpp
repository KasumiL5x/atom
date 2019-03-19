#include "TextureWatcher.hpp"
#include "../../MTLog.hpp"
#include "../../server/Connection.hpp"
#include "../../AtomDag/AtomDag.hpp"
#include "../../AtomDag/Nodes/Node.hpp"
#include "../../AtomDag/Nodes/Texture.hpp"
#include "../../proto/AtomMessage.pb.h"
#include "../../ProtobufHelper.hpp"

using namespace atom;
using namespace atom::dag;

TextureWatcher::TextureWatcher()
	: IWatchHandler() {
}

TextureWatcher::~TextureWatcher() {
}

bool TextureWatcher::handle( std::shared_ptr<Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) {
	if( node->type() != DagType::Texture ) {
		MTLog::instance()->log("TextureWatcher::handle: ADagNode type was not kTexture!\n");
		return false;
	}

	const auto texture = std::static_pointer_cast<Texture>(node);

	// send initial data
	sendTexture(texture, connection);

	// add watch handler
	std::shared_ptr<Connection> copyOfConnection = connection;
	node->addWatcher([this, copyOfConnection, texture](DagCallback type, const std::shared_ptr<Node>& node, std::shared_ptr<Node> instigator) {
		if( nullptr == node ) {
			MTLog::instance()->log("TextureWatcher::handle's callback delivered a null node.\n");
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

			case DagCallback::kTextureChangedFile:
			case DagCallback::kTextureChangedTranslateFrame:
			case DagCallback::kTextureChangedRotateFrame:
			case DagCallback::kTextureChangedMirrorU:
			case DagCallback::kTextureChangedMirrorV:
			case DagCallback::kTextureChangedWrapU:
			case DagCallback::kTextureChangedWrapV:
			case DagCallback::kTextureChangedRepeat:
			case DagCallback::kTextureChangedOffset:
			case DagCallback::kTextureChangedRotateUV:
			case DagCallback::kTextureChangedNoise: {
				sendTextureChanged(type, texture, copyOfConnection);
				break;
			}

			default: {
				MTLog::instance()->log("TextureWatcher::handle's callback type was unhandled.\n");
				break;
			}
		}

		return true;
	}, copyOfConnection->getClientName());

	return true;
}

void TextureWatcher::sendTexture( const std::shared_ptr<Texture>& texture, const std::shared_ptr<Connection>& connection ) {
	auto atomTexture = new atom::proto::materials::Texture();

	// node name
	atomTexture->set_texturename(texture->name());

	// filename and bytes
	auto atomTextureData = new atom::proto::materials::TextureData();
	atomTextureData->set_filename(texture->getTextureName());
	atomTextureData->set_extension(texture->getTextureExt());
	const auto data = texture->getTextureData();
	const auto length = texture->getTextureDataLength();
	if( data != nullptr ) {
		atomTextureData->set_bytes(data, length);
	}
	atomTexture->set_allocated_data(atomTextureData);

	atomTexture->set_allocated_translateframe(protohelper::vector2From(texture->getTranslateFrameU(), texture->getTranslateFrameV()));
	atomTexture->set_rotateframe(texture->getRotateFrame());
	atomTexture->set_mirroru(texture->getMirrorU());
	atomTexture->set_mirrorv(texture->getMirrorV());
	atomTexture->set_wrapu(texture->getWrapU());
	atomTexture->set_wrapv(texture->getWrapV());
	atomTexture->set_allocated_repeat(protohelper::vector2From(texture->getRepeatU(), texture->getRepeatV()));
	atomTexture->set_allocated_offset(protohelper::vector2From(texture->getOffsetU(), texture->getOffsetV()));
	atomTexture->set_rotate(texture->getRotateUV());
	atomTexture->set_allocated_noise(protohelper::vector2From(texture->getNoiseU(), texture->getNoiseV()));

	atom::proto::AtomMessage msg;
	msg.set_allocated_texture(atomTexture);
	protohelper::sendTo(msg, connection);
}

void TextureWatcher::sendTextureChanged( DagCallback type, const std::shared_ptr<Texture>& texture, const std::shared_ptr<Connection>& connection ) {
	auto atomTextureChanged = new atom::proto::materials::TextureChanged();
	atomTextureChanged->set_texturename(texture->name());

	switch( type ) {
		case DagCallback::kTextureChangedFile: {
			auto atomTextureData = new atom::proto::materials::TextureData();
			atomTextureData->set_filename(texture->getTextureName());
			atomTextureData->set_extension(texture->getTextureExt());
			const auto data = texture->getTextureData(); // force re-read of data since it changed
			const auto length = texture->getTextureDataLength();
			if( data != nullptr ) {
				atomTextureData->set_bytes(data, length);
			}
			atomTextureChanged->set_allocated_data(atomTextureData);
			break;
		}
		case DagCallback::kTextureChangedTranslateFrame: {
			atomTextureChanged->set_allocated_translateframe(protohelper::vector2From(texture->getTranslateFrameU(), texture->getTranslateFrameV()));
			break;
		}
		case DagCallback::kTextureChangedRotateFrame: {
			atomTextureChanged->set_rotateframe(texture->getRotateFrame());
			break;
		}
		case DagCallback::kTextureChangedMirrorU: {
			atomTextureChanged->set_mirroru(texture->getMirrorU());
			break;
		}
		case DagCallback::kTextureChangedMirrorV: {
			atomTextureChanged->set_mirrorv(texture->getMirrorV());
			break;
		}
		case DagCallback::kTextureChangedWrapU: {
			atomTextureChanged->set_wrapu(texture->getWrapU());
			break;
		}
		case DagCallback::kTextureChangedWrapV: {
			atomTextureChanged->set_wrapv(texture->getWrapV());
			break;
		}
		case DagCallback::kTextureChangedRepeat: {
			atomTextureChanged->set_allocated_repeat(protohelper::vector2From(texture->getRepeatU(), texture->getRepeatV()));
			break;
		}
		case DagCallback::kTextureChangedOffset: {
			atomTextureChanged->set_allocated_offset(protohelper::vector2From(texture->getOffsetU(), texture->getOffsetV()));
			break;
		}
		case DagCallback::kTextureChangedRotateUV: {
			atomTextureChanged->set_rotate(texture->getRotateUV());
			break;
		}
		case DagCallback::kTextureChangedNoise: {
			atomTextureChanged->set_allocated_noise(protohelper::vector2From(texture->getNoiseU(), texture->getNoiseV()));
			break;
		}

		default: {
			MTLog::instance()->log("TextureWatcher::handle's callback received an unhandled type.\n");
			break;
		}
	}

	atom::proto::AtomMessage msg;
	msg.set_allocated_texturechanged(atomTextureChanged);
	protohelper::sendTo(msg, connection);
}
