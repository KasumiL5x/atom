#include <vector>
#include <memory>
#include <string>
#include <maya/MFnPlugin.h>
#include <thread>
#include "MTLog.hpp"
#include <google/protobuf/stubs/common.h>
#include "proto/Scene.pb.h"
#include "proto/AtomMessage.pb.h"
#include "ProtobufHelper.hpp"
#include "commands/ArgParser.hpp"
#include "commands/ICommandEater.hpp"
#include "commands/WatchCmd.hpp"
#include "commands/UnwatchCmd.hpp"
#include "server/Server.hpp"
#include <maya/MSceneMessage.h>
#include "ProtobufHelper.hpp"
#include "utils/ConfigFile.hpp"

#include "AtomDag/AtomDag.hpp"
std::shared_ptr<atom::dag::AtomDag> ATOM_DAG = nullptr;

std::shared_ptr<atom::Server> SERVER = nullptr;
std::vector<std::shared_ptr<atom::ICommandEater>> EATERS;
std::thread SEND_DATA_THREAD;
MCallbackId MAYA_EXITING_CALLBACK_ID = 0;
MCallbackId MAYA_AFTER_NEW_CALLBACK_ID = 0;
MCallbackId MAYA_AFTER_OPEN_CALLBACK_ID = 0;

const int DEFAULT_SERVER_PORT = 1337;
const int DEFAULT_SEND_DELAY = 500; // ms

int SERVER_PORT = DEFAULT_SERVER_PORT;
int SEND_DELAY = DEFAULT_SEND_DELAY;

void shutdownPlugin() {
	MTLog::instance()->log("Shutting down atom...");

	// remove callback or maya will fatal error (and it doesn't need help doing that, believe me)
	MTLog::instance()->log("callbacks...", false);
	MSceneMessage::removeCallback(MAYA_AFTER_OPEN_CALLBACK_ID);
	MSceneMessage::removeCallback(MAYA_AFTER_NEW_CALLBACK_ID);
	MSceneMessage::removeCallback(MAYA_EXITING_CALLBACK_ID);

	MTLog::instance()->log("server...", false);
	if( SERVER != nullptr ) {
		SERVER->stop();
		SEND_DATA_THREAD.join(); // after stop but before delete
		SERVER = nullptr;
	}

	MTLog::instance()->log("adag...", false);
	if( ATOM_DAG != nullptr ) {
		ATOM_DAG->uninitialize();
		ATOM_DAG = nullptr;
	}

	MTLog::instance()->log("eaters...", false);
	EATERS.clear();

	MTLog::instance()->log("protobuf...", false);
	google::protobuf::ShutdownProtobufLibrary();

	MTLog::instance()->log("done!\n", false);
}

std::string getLoadPath( MObject obj ) {
	MFnPlugin plugin(obj);
	const std::string path = plugin.loadPath().asChar();
	return path;
}

MStatus initializePlugin( MObject obj ) {
	MTLog::instance()->log("atom v1.0dev\n", false);

	// read config file values
	atom::ConfigFile config;
	const std::string configFile = getLoadPath(obj) + "/atom.cfg";
	if( config.readFromFile(configFile) ) {
		if( !config.getInt("port", SERVER_PORT) ) {
			MTLog::instance()->log("Failed to read value for \"port\" from config; using default of " + std::to_string(DEFAULT_SERVER_PORT) + ".\n");
		}
		if( !config.getInt("delay", SEND_DELAY) ) {
			MTLog::instance()->log("Failed to read value for \"delay\" from config; using default of " + std::to_string(DEFAULT_SEND_DELAY) + ".\n");
		}
	} else {
		MTLog::instance()->log("Could not open config file (" + configFile + ").  Using defaults (Port: " + std::to_string(DEFAULT_SERVER_PORT) + "; Delay: " + std::to_string(DEFAULT_SEND_DELAY) + "ms).\n");
	}

	// configure callback for when maya exits, as it will not call uninitializePlugin and therefore will crash
	MAYA_EXITING_CALLBACK_ID = MSceneMessage::addCallback(MSceneMessage::kMayaExiting, [](void* clientData) {
		shutdownPlugin();
	});

	// sanity check
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	// create server and adag
	 SERVER = std::make_shared<atom::Server>();
	 ATOM_DAG = std::make_shared<atom::dag::AtomDag>();

	// populate command eaters
	EATERS.push_back(std::make_shared<atom::WatchCmd>());
	EATERS.push_back(std::make_shared<atom::UnwatchCmd>());

	// initialize adag
	if( !ATOM_DAG->initialize() ) {
		MTLog::instance()->log("ERROR: Failed to initialize AtomDag.\n");
		return MS::kFailure;
	}
	//ATOM_DAG->print(2);

	// configure the server
	if( !SERVER->start(SERVER_PORT) ) {
		MTLog::instance()->log("ERROR: Failed to start server on port " + std::to_string(SERVER_PORT) + ".\n");
		return MS::kFailure;
	} else {
		MTLog::instance()->log("Server started on port " + std::to_string(SERVER_PORT) + ".\n");
	}
	
	// handle client join server
	SERVER->setOnConnectionMade([](std::shared_ptr<atom::Connection> connection) {
		MTLog::instance()->log("INFO: Client connected <" + connection->getClientName() + ">\n");

		// send scene information
		const auto protoScene = atom::protohelper::createFullScene(ATOM_DAG, atom::proto::Scene_Reason_kRebuildOnConnected);
		atom::proto::AtomMessage msg;
		msg.set_allocated_scene(protoScene);
		atom::protohelper::sendTo(msg, connection);

		// configure parsing of received data from connections
		std::shared_ptr<atom::Connection> connDupe = connection; // for lifetime reasons
		connection->setOnReceived([connDupe](std::shared_ptr<atom::Message> message) {
			const std::string strMsg = std::string((char*)message->data().get(), message->dataSize());
			MTLog::instance()->log("INFO: Received data from <" + connDupe->getClientName() + ">: " + strMsg + "\n");
		
			if( strMsg.empty() ) {
				MTLog::instance()->log("WARNING: Received empty string.\n");
				return;
			}

			if( strcmp(&strMsg.back(), ";") != 0 ) {
				MTLog::instance()->log("WARNING: Received command does not terminate with a semicolon.\n");
				return;
			}

			const atom::ArgParser parser(strMsg.substr(0, strMsg.size()-1));

			bool commandWasAte = false;
			for( auto& eater : EATERS ) {
				if( eater->consume(parser, connDupe, ATOM_DAG) ) {
					commandWasAte = true;
					break;
				}
			}
			if( !commandWasAte ) {
				MTLog::instance()->log("WARNING: Received command was not consumed.  Syntax is likely incorrect.\n");
			}
		});
	});

	// handle client server disconnect
	SERVER->setOnDisconnected([](std::shared_ptr<atom::Connection> connection) {
		MTLog::instance()->log("INFO: Client disconnected <" + connection->getClientName() + ">\n");
	});

	// handle adag node added
	ATOM_DAG->addNodeAddedWatcher([](const std::shared_ptr<atom::dag::Node>& node){
		if( SERVER->numberOfClients() != 0 ) {
			const auto protoScene = atom::protohelper::createSceneFrom(node, atom::proto::Scene_Reason_kAdded);
			if( nullptr == protoScene ) {
				return;
			}

			atom::proto::AtomMessage msg;
			msg.set_allocated_scene(protoScene);
			int byteSize;
			const auto bytes = atom::protohelper::serializeTo(msg, byteSize);
			if( bytes != nullptr ) {
				SERVER->sendToAll(atom::Message::createOutgoing(bytes.get(), byteSize));
			} else {
				MTLog::instance()->log("node added serializeTo failed.\n");
			}
		}
	});

	// handle adag node removed
	ATOM_DAG->addNodeRemovedWatcher([](std::shared_ptr<atom::dag::Node> node){
		if( SERVER->numberOfClients() != 0 ) {
			const auto protoScene = atom::protohelper::createSceneFrom(node, atom::proto::Scene_Reason_kRemoved);
			if( nullptr == protoScene ) {
				return;
			}

			atom::proto::AtomMessage msg;
			msg.set_allocated_scene(protoScene);
			int byteSize;
			const auto bytes = atom::protohelper::serializeTo(msg, byteSize);
			if( bytes != nullptr ) {
				SERVER->sendToAll(atom::Message::createOutgoing(bytes.get(), byteSize));
			} else {
				MTLog::instance()->log("node added serializeTo failed.\n");
			}
		}
	});

	// handle adag rebuild
	ATOM_DAG->addRebuildWatcher([](atom::dag::RebuildCause reason) {
		if( SERVER->numberOfClients() != 0 ) {

			atom::proto::Scene* protoScene = nullptr;
			atom::proto::AtomMessage msg;

			switch( reason ) {
				case atom::dag::RebuildCause::Initialized: {
					break; // ignore initialized
				}
				case atom::dag::RebuildCause::NewScene: {
					protoScene = atom::protohelper::createFullScene(ATOM_DAG, atom::proto::Scene_Reason_kRebuildOnNew);
					break;
				}
				case atom::dag::RebuildCause::OpenScene: {
					protoScene = atom::protohelper::createFullScene(ATOM_DAG, atom::proto::Scene_Reason_kRebuildOnOpen);
					break;
				}
				case atom::dag::RebuildCause::Forced: {
					// todo: handle forced
					throw;
					break;
				}
			}

			if( protoScene != nullptr ) {
				msg.set_allocated_scene(protoScene);
				int byteSize;
				const auto bytes = atom::protohelper::serializeTo(msg, byteSize);
				if( bytes != nullptr ) {
					SERVER->sendToAll(atom::Message::createOutgoing(bytes.get(), byteSize));
				} else {
					MTLog::instance()->log("node added serializeTo failed.\n");
				}
			}
		}
	});

	// configure callback for after a file->new so we can rebuild the ADAG
	MAYA_AFTER_NEW_CALLBACK_ID = MSceneMessage::addCallback(MSceneMessage::kAfterNew, [](void* clientData) {
		if( ATOM_DAG != nullptr ) {
			ATOM_DAG->rebuild(atom::dag::RebuildCause::NewScene);
		}
	});

	// configure callback for after a file->open so we can rebuild the ADAG
	MAYA_AFTER_OPEN_CALLBACK_ID = MSceneMessage::addCallback(MSceneMessage::kAfterOpen, [](void* clientData) {
		if( ATOM_DAG != nullptr ) {
			ATOM_DAG->rebuild(atom::dag::RebuildCause::OpenScene);
		}
	});

	// send data every X milliseconds i want to make this customizable in the future
	MTLog::instance()->log("Send delay is " + std::to_string(SEND_DELAY) + "ms.\n");
	SEND_DATA_THREAD = std::thread([&](){
		while( SERVER->isRunning() ) {
			std::this_thread::sleep_for(std::chrono::milliseconds(SEND_DELAY));

			// call before because some nodes like utility nodes will dirty meshes etc.
			ATOM_DAG->forAllNodes([](const std::shared_ptr<atom::dag::Node>& node) {
				node->justBeforeNotify();
			});

			ATOM_DAG->forAllNodes([](const std::shared_ptr<atom::dag::Node>& node) {
				if( node->isDirty() ) {
					node->notifyWatchers();
				}
			});

			ATOM_DAG->forAllNodes([](const std::shared_ptr<atom::dag::Node>& node) {
				node->justAfterNotify();
			});
		}
	});

	return MS::kSuccess;
}

MStatus uninitializePlugin( MObject obj ) {
	shutdownPlugin();
	return MS::kSuccess;
}