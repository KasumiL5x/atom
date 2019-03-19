#include "UnwatchCmd.hpp"

using namespace atom;

UnwatchCmd::UnwatchCmd()
	: ICommandEater() {
}

UnwatchCmd::~UnwatchCmd() {
}

bool UnwatchCmd::consume( const ArgParser& parser, std::shared_ptr<atom::Connection> connection, std::shared_ptr<dag::AtomDag> adag ) {
	// validate arg  count
	if( parser.count() != 2 ) {
		return false;
	}

	// validate command
	if( parser.argType(0) != ArgType::String || strcmp("unwatch", parser.argValue<std::string>(0).data()) != 0 ) {
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

	node->removeWatcher(connection->getClientName());

	return true;
}