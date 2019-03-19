#include "AnnotationWatcher.hpp"
#include "../../AtomDag/AtomDag.hpp"
#include "../../AtomDag/Nodes/Node.hpp"
#include "../../AtomDag/Nodes/Annotation.hpp"
#include "../../server/Connection.hpp"
#include "../../proto/AtomMessage.pb.h"
#include "../../ProtobufHelper.hpp"
#include "../../MTLog.hpp"

using namespace atom;
using namespace atom::dag;

AnnotationWatcher::AnnotationWatcher()
	: IWatchHandler() {
}

AnnotationWatcher::~AnnotationWatcher() {
}

bool AnnotationWatcher::handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) {
	if( node->type() != DagType::Annotation ) {
		MTLog::instance()->log("AnnotationWatcher::handle: Node type was not Annotation!\n");
		return false;
	}

	const auto annotation = std::static_pointer_cast<Annotation>(node);

	// send initial data
	sendAnnotationData(annotation, connection);

	// add watch handler
	std::shared_ptr<Connection> copyOfConnection = connection;
	node->addWatcher([this, copyOfConnection, annotation](DagCallback type, const std::shared_ptr<Node>& node, std::shared_ptr<Node> instigator) {
		if( nullptr == node ) {
			MTLog::instance()->log("AnnotationWatcher::handle's callback delivered a null node.\n");
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
			case DagCallback::kMatrixChanged: {
				protohelper::sendMatrixChanged(annotation, annotation->transformationMatrix(true), copyOfConnection);
				break;
			}
			case DagCallback::kAnnotationChangedText: {
				sendAnnotationData(annotation, copyOfConnection);
				break;
			}
			default: {
				MTLog::instance()->log("AnnotationWatcher::handle's callback type was unhandled.\n");
				break;
			}
		}

		return true;
	}, copyOfConnection->getClientName());


	return true;
}

void AnnotationWatcher::sendAnnotationData( const std::shared_ptr<dag::Annotation>& annotation, const std::shared_ptr<Connection>& connection ) {
	auto atomAnnotation = new atom::proto::Annotation();
	atomAnnotation->set_name(annotation->name());
	atomAnnotation->set_text(annotation->text());
	atomAnnotation->set_allocated_world(protohelper::matrixFrom(annotation->transformationMatrix(true)));
	atomAnnotation->set_initialvisibility(annotation->isVisible());

	atom::proto::AtomMessage msg;
	msg.set_allocated_annotation(atomAnnotation);
	protohelper::sendTo(msg, connection);
}