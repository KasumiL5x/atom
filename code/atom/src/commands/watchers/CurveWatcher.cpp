#include "CurveWatcher.hpp"
#include "../../AtomDag/AtomDag.hpp"
#include "../../AtomDag/Nodes/Node.hpp"
#include "../../AtomDag/Nodes/Curve.hpp"
#include "../../server/Connection.hpp"
#include "../../ProtobufHelper.hpp"
#include "../../MTLog.hpp"

using namespace atom;
using namespace atom::dag;

CurveWatcher::CurveWatcher()
	: IWatchHandler() {
}

CurveWatcher::~CurveWatcher() {
}

bool CurveWatcher::handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) {
	if( node->type() != DagType::Curve ) {
		MTLog::instance()->log("CurveWatcher::handle: Node type was node Curve!\n");
		return false;
	}

	const auto curve = std::static_pointer_cast<Curve>(node);

	// send initial data
	sendCurveData(curve, connection);

	// add watch handler
	std::shared_ptr<Connection> copyOfConnection = connection;
	node->addWatcher([this, copyOfConnection, curve](DagCallback type, const std::shared_ptr<Node>& node, std::shared_ptr<Node> instigator) {
		if( nullptr == node ) {
			MTLog::instance()->log("CurveWatcher::handle's callback delivered a null node.\n");
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
				protohelper::sendMatrixChanged(curve, curve->transformationMatrix(true), copyOfConnection);
				break;
			}
			case DagCallback::kCurveChanged: {
				sendCurveData(curve, copyOfConnection);
				break;
			}
			default: {
				MTLog::instance()->log("CurveWatcher::handle's callback type was unhandled.\n");
				break;
			}
		}

		return true;
	}, copyOfConnection->getClientName());

	return true;
}

void CurveWatcher::sendCurveData( const std::shared_ptr<dag::Curve>& curve, const std::shared_ptr<Connection>& connection ) {
	auto atomCurve = new atom::proto::Curve();
	atomCurve->set_name(curve->name());
	atomCurve->set_allocated_world(protohelper::matrixFrom(curve->transformationMatrix(true)));
	atomCurve->set_initialvisibility(curve->isVisible());
	
	auto points = curve->getCVs();
	for( unsigned int i = 0; i < points.length(); ++i ) {
		auto cv = atomCurve->add_cv();
		cv->set_x(static_cast<float>(points[i].x));
		cv->set_y(static_cast<float>(points[i].y));
		cv->set_z(static_cast<float>(points[i].z));
	}

	atom::proto::AtomMessage msg;
	msg.set_allocated_curve(atomCurve);
	protohelper::sendTo(msg, connection);
}