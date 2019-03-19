#ifndef __atom_WatchCmd__
#define __atom_WatchCmd__

// Command: watch
// Purpose: Sets up a client to watch a node for changes.
// Returns: nothing
// Syntax:
//   [name:string] - Name of the node to watch.
// Example:
//   watch |pCube1|pCubeShape1

#include <vector>
#include "ICommandEater.hpp"
#include "watchers/IWatchHandler.hpp"

namespace atom {
	class WatchCmd : public ICommandEater {
	public:
		WatchCmd();
		virtual ~WatchCmd();

		virtual bool consume( const ArgParser& parser, std::shared_ptr<atom::Connection> connection, std::shared_ptr<dag::AtomDag> adag ) override;

	private:
		std::vector<std::shared_ptr<IWatchHandler>> watchHandlers_;
	};
}

#endif