#include "WatchCmd.hpp"
#include "../MTLog.hpp"
#include "watchers/CameraWatcher.hpp"
#include "watchers/LightWatcher.hpp"
#include "watchers/MaterialWatcher.hpp"
#include "watchers/MeshWatcher.hpp"
#include "watchers/TextureWatcher.hpp"
#include "watchers/XformWatcher.hpp"
#include "watchers/AnnotationWatcher.hpp"
#include "watchers/CurveWatcher.hpp"

using namespace atom;
using namespace atom::dag;

WatchCmd::WatchCmd()
	: ICommandEater() {
}

WatchCmd::~WatchCmd() {
}

bool WatchCmd::consume( const ArgParser& parser, std::shared_ptr<atom::Connection> connection, std::shared_ptr<dag::AtomDag> adag ) {
	// validate arg count
	if( parser.count() != 2 ) {
		return false;
	}

	// validate command
	if( parser.argType(0) != ArgType::String || strcmp("watch", parser.argValue<std::string>(0).data()) != 0 ) {
		return false;
	}

	// validate arguments
	if( parser.argType(1) != ArgType::String ) {
		return false;
	}

	// get argument data
	const std::string nodeName = parser.argValue<std::string>(1);

	// get node from adag
	const auto node = adag->findNodeByName(nodeName);
	if( nullptr == node ) {
		return false;
	}

	switch( node->type() ) {
		case DagType::Xform: {
			auto watcher = std::make_shared<XformWatcher>();
			watcher->handle(node, connection, adag);
			watchHandlers_.push_back(watcher);
			break;
		}
		case DagType::Camera: {
			auto watcher = std::make_shared<CameraWatcher>();
			watcher->handle(node, connection, adag);
			watchHandlers_.push_back(watcher);
			break;
		}
		case DagType::Light: {
			auto watcher = std::make_shared<LightWatcher>();
			watcher->handle(node, connection, adag);
			watchHandlers_.push_back(watcher);
			break;
		}
		case DagType::Material: {
			auto watcher = std::make_shared<MaterialWatcher>();
			watcher->handle(node, connection, adag);
			watchHandlers_.push_back(watcher);
			break;
		}
		case DagType::Mesh: {
			auto watcher = std::make_shared<MeshWatcher>();
			watcher->handle(node, connection, adag);
			watchHandlers_.push_back(watcher);
			break;
		}
		case DagType::Texture: {
			auto watcher = std::make_shared<TextureWatcher>();
			watcher->handle(node, connection, adag);
			watchHandlers_.push_back(watcher);
			break;
		}
		case DagType::Annotation: {
			auto watcher = std::make_shared<AnnotationWatcher>();
			watcher->handle(node, connection, adag);
			watchHandlers_.push_back(watcher);
			break;
		}
		case DagType::Curve: {
			auto watcher = std::make_shared<CurveWatcher>();
			watcher->handle(node, connection, adag);
			watchHandlers_.push_back(watcher);
			break;
		}
		default: {
			MTLog::instance()->log("WatchCmd::consume received an unhandled node type.\n");
			break;
		}
	}

	return true;
}
