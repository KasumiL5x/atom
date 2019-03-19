#include "CameraWatcher.hpp"
#include "../../MTLog.hpp"
#include "../../server/Connection.hpp"
#include "../../AtomDag/AtomDag.hpp"
#include "../../AtomDag/Nodes/Node.hpp"
#include "../../AtomDag/Nodes/Camera.hpp"
#include "../../proto/AtomMessage.pb.h"
#include "../../ProtobufHelper.hpp"

using namespace atom;
using namespace atom::dag;

CameraWatcher::CameraWatcher()
	: IWatchHandler() {
}

CameraWatcher::~CameraWatcher() {
}

bool CameraWatcher::handle( std::shared_ptr<Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) {
	if( node->type() != DagType::Camera ) {
		MTLog::instance()->log("CameraWatcher::handle: ADagNode type was not kCamera!\n");
		return false;
	}

	const auto camera = std::static_pointer_cast<Camera>(node);

	// send initial data
	sendCameraData(camera, connection);

	// add watch handler
	std::shared_ptr<Connection> copyOfConnection = connection;
	node->addWatcher([this, copyOfConnection, camera](DagCallback type, const std::shared_ptr<Node>& node, std::shared_ptr<Node> instigator) {
		if( nullptr == node ) {
			MTLog::instance()->log("CameraWatcher::handle's callback delivered a null node.\n");
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
			case DagCallback::kCameraChanged: {
				sendCameraData(camera, copyOfConnection);
				break;
			}
			default: {
				MTLog::instance()->log("CameraWatcher::handle's callback type was unhandled.\n");
				break;
			}
		}

		return true;
	}, copyOfConnection->getClientName());

	return true;
}

void CameraWatcher::sendCameraData( const std::shared_ptr<Camera>& camera, const std::shared_ptr<Connection>& connection ) {
	auto atomCamera = new atom::proto::Camera();
	atomCamera->set_name(camera->name());

	atomCamera->set_allocated_position(protohelper::vector3From(camera->position()));
	atomCamera->set_allocated_target(protohelper::vector3From(camera->target()));
	atomCamera->set_allocated_up(protohelper::vector3From(camera->up()));
	atomCamera->set_fieldofview((float)camera->fieldOfView());
	atomCamera->set_aspectratio((float)camera->aspectRatio());
	atomCamera->set_nearplane((float)camera->nearPlane());
	atomCamera->set_farplane((float)camera->farPlane());
	atomCamera->set_initialvisibility(camera->isVisible());

	atom::proto::AtomMessage msg;
	msg.set_allocated_camera(atomCamera);
	protohelper::sendTo(msg, connection);
}
