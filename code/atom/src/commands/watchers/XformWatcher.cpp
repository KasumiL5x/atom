#include "XformWatcher.hpp"
#include "../../server/Connection.hpp"
#include "../../AtomDag/AtomDag.hpp"
#include "../../AtomDag/Nodes/Node.hpp"
#include "../../AtomDag/Nodes/Xform.hpp"
#include "../../MTLog.hpp"
#include "../../ProtobufHelper.hpp"
#include "../../proto/AtomMessage.pb.h"

using namespace atom;
using namespace atom::dag;

XformWatcher::XformWatcher()
	: IWatchHandler() {
}

XformWatcher::~XformWatcher() {
}

bool XformWatcher::handle( std::shared_ptr<Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<AtomDag> adag ) {
	if( node->type() != DagType::Xform ) {
		MTLog::instance()->log("XformWatcher::handle ADagNode type was not Xform!\n");
		return false;
	}

	const auto xform = std::static_pointer_cast<Xform>(node);

	// send initial data
	sendXformData(xform, connection);

	// add wach handler
	std::shared_ptr<Connection> copyOfConnection = connection;
	node->addWatcher([this, copyOfConnection, xform](DagCallback type, const std::shared_ptr<Node>& node, std::shared_ptr<Node> instigator) {
		if( nullptr == node ) {
			MTLog::instance()->log("XformWatcher::handle's callback delivered a null node.\n");
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

			case DagCallback::kTranslated:
			case DagCallback::kRotated:
			case DagCallback::kScaled: {
				// todo: send only matrix data; send components changed separately
				sendXformData(xform, copyOfConnection);
				break;
			}

			default: {
				MTLog::instance()->log("XformWatcher::handle's callback type was unhandled.\n");
				break;
			}
		}
		return true;
	}, copyOfConnection->getClientName());

	return true;
}

void XformWatcher::sendXformData( const std::shared_ptr<Xform>& xform, const std::shared_ptr<Connection>& connection ) {
	auto protoXform = new atom::proto::Transform();
	protoXform->set_name(xform->name());
	protoXform->set_allocated_world(protohelper::matrixFrom(xform->transformationMatrix(true)));
	protoXform->set_initialvisibility(xform->isVisible());

	for( const auto& comp : xform->components() ) {
		const auto atomComp = protoXform->add_components();
		atomComp->set_name(comp->name());
		switch( comp->type() ) {
			case DagType::Camera: {
				atomComp->set_type(atom::proto::Component_ComponentType_kCamera);
				break;
			}
			case DagType::Mesh: {
				atomComp->set_type(atom::proto::Component_ComponentType_kMesh);
				break;
			}
			case DagType::Light: {
				atomComp->set_type(atom::proto::Component_ComponentType_kLight);
				break;
			}
			case DagType::Annotation: {
				atomComp->set_type(atom::proto::Component_ComponentType_kAnnotation);
				break;
			}
			case DagType::Curve: {
				atomComp->set_type(atom::proto::Component_ComponentType_kCurve);
				break;
			}
		}
	}

	atom::proto::AtomMessage msg;
	msg.set_allocated_transform(protoXform);
	protohelper::sendTo(msg, connection);
}