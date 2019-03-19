#include "LightWatcher.hpp"
#include "../../MTLog.hpp"
#include "../../server/Connection.hpp"
#include "../../AtomDag/AtomDag.hpp"
#include "../../AtomDag/Nodes/Node.hpp"
#include "../../AtomDag/Nodes/Light.hpp"
#include "../../proto/AtomMessage.pb.h"
#include "../../ProtobufHelper.hpp"

using namespace atom;
using namespace atom::dag;

LightWatcher::LightWatcher()
	: IWatchHandler() {
}

LightWatcher::~LightWatcher() {
}

bool LightWatcher::handle( std::shared_ptr<Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) {
	if( node->type() != DagType::Light ) {
		MTLog::instance()->log("LightWatcher::handle: ADagNode type was not kLight!\n");
		return false;
	}

	const auto light = std::static_pointer_cast<Light>(node);

	// send initial data
	sendLight(light, connection);

	// add watch handler
	std::shared_ptr<Connection> copyOfConnection = connection;
	node->addWatcher([this, copyOfConnection, light](DagCallback type, const std::shared_ptr<Node>& node, std::shared_ptr<Node> instigator) {
		if( nullptr == node ) {
			MTLog::instance()->log("LightWatcher::handle's callback delivered a null node.\n");
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

			case DagCallback::kLightChangedType:
			case DagCallback::kLightChangedRange:
			case DagCallback::kLightChangedColor:
			case DagCallback::kLightChangedIntensity:
			case DagCallback::kLightChangedConeAngle:
			case DagCallback::kLightChangedPenumbraAngle:
			case DagCallback::kLightChangedDropoff:
			case DagCallback::kLightChangedShadows:
			case DagCallback::kLightChangedShadowResolution:
			case DagCallback::kLightChangedShadowBias:
			case DagCallback::kLightChangedShadowColor:
			case DagCallback::kLightChangedPosition:
			case DagCallback::kLightChangedDirection: {
				sendLightChanged(type, light, copyOfConnection);
				break;
			}

			default: {
				MTLog::instance()->log("LightWatcher::handle's callback type was unhandled.\n");
				break;
			}
		}

		return true;
	}, copyOfConnection->getClientName());

	return true;
}

void LightWatcher::sendLight( const std::shared_ptr<Light>& light, const std::shared_ptr<Connection>& connection ) {
	auto atomLight = new atom::proto::lights::Light();
	atomLight->set_name(light->name());
	atomLight->set_initialvisibility(light->isVisible());

	// type
	atomLight->set_type(convertType(light->mayaObject().apiType()));
	// position
	atomLight->set_allocated_position(protohelper::vector3From(light->getPosition()));
	// direction
	atomLight->set_allocated_direction(protohelper::vector3From(light->getDirection()));
	// range
	atomLight->set_range(light->range());
	// color
	atomLight->set_allocated_color(protohelper::colorFrom(light->diffuseColor()));
	// intensity
	atomLight->set_intensity(light->intensity());
	// cone angle
	atomLight->set_coneangle(light->innerConeAngle());
	// penumbra angle
	atomLight->set_penumbraangle(light->penumbraAngle());
	// dropoff
	atomLight->set_dropoff(light->dropoff());
	// shadows
	atomLight->set_shadows(light->useShadows());
	// shadow resolution
	atomLight->set_shadowresolution(light->shadowResolution());
	// shadow bias
	atomLight->set_shadowbias(light->shadowBias());
	// shadow color
	atomLight->set_allocated_shadowcolor(protohelper::colorFrom(light->shadowColor()));

	atom::proto::AtomMessage msg;
	msg.set_allocated_light(atomLight);
	protohelper::sendTo(msg, connection);
}

void LightWatcher::sendLightChanged( DagCallback type, const std::shared_ptr<Light>& light, const std::shared_ptr<Connection>& connection ) {
	auto atomLightChanged = new atom::proto::lights::LightChanged();
	atomLightChanged->set_lightname(light->name());

	switch( type ) {
		case DagCallback::kLightChangedType: {
			atomLightChanged->set_type(convertType(light->mayaObject().apiType()));
			break;
		}
		case DagCallback::kLightChangedPosition: {
			atomLightChanged->set_allocated_position(protohelper::vector3From(light->getPosition()));
			break;
		}
		case DagCallback::kLightChangedDirection: {
			atomLightChanged->set_allocated_direction(protohelper::vector3From(light->getDirection()));
			break;
		}
		case DagCallback::kLightChangedRange: {
			atomLightChanged->set_range(light->range());
			break;
		}
		case DagCallback::kLightChangedColor: {
			atomLightChanged->set_allocated_color(protohelper::colorFrom(light->diffuseColor()));
			break;
		}
		case DagCallback::kLightChangedIntensity: {
			atomLightChanged->set_intensity(light->intensity());
			break;
		}
		case DagCallback::kLightChangedConeAngle: {
			atomLightChanged->set_coneangle(light->innerConeAngle());
			break;
		}
		case DagCallback::kLightChangedPenumbraAngle: {
			atomLightChanged->set_penumbraangle(light->penumbraAngle());
			break;
		}
		case DagCallback::kLightChangedDropoff: {
			atomLightChanged->set_dropoff(light->dropoff());
			break;
		}
		case DagCallback::kLightChangedShadows: {
			atomLightChanged->set_shadows(light->useShadows());
			break;
		}
		case DagCallback::kLightChangedShadowResolution: {
			atomLightChanged->set_shadowresolution(light->shadowResolution());
			break;
		}
		case DagCallback::kLightChangedShadowBias: {
			atomLightChanged->set_shadowbias(light->shadowBias());
			break;
		}
		case DagCallback::kLightChangedShadowColor: {
			atomLightChanged->set_allocated_shadowcolor(protohelper::colorFrom(light->shadowColor()));
			break;
		}
		default: {
			MTLog::instance()->log("LightWatcher::handle's callback received an unhandled type.\n");
			break;
		}
	}

	atom::proto::AtomMessage msg;
	msg.set_allocated_lightchanged(atomLightChanged);
	protohelper::sendTo(msg, connection);
}

atom::proto::lights::LightType LightWatcher::convertType( MFn::Type type ) const {
	switch( type ) {
		case MFn::kAmbientLight: {
			return atom::proto::lights::kLightTypeAmbient;
		}
		case MFn::kDirectionalLight: {
			return atom::proto::lights::kLightTypeDirectional;
		}
		case MFn::kSpotLight: {
			return atom::proto::lights::kLightTypeSpot;
		}
		case MFn::kPointLight: {
			return atom::proto::lights::kLightTypePoint;
		}
	}
	return atom::proto::lights::kLightTypeAmbient;
}