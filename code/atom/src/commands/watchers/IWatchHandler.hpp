#ifndef __atom_IWatchHandler__
#define __atom_IWatchHandler__

#include <memory>

namespace atom {

namespace dag {
	class AtomDag;
	class Node;
}
class Connection;

class IWatchHandler {
public:
	IWatchHandler() {
	}
	virtual ~IWatchHandler() {
	}

	/**
	 * Derived classes should handle their node type accordingly.
	 * @param node       ADagNode that needs to be watched.
	 * @param connection Connection that watched the node.
	 * @param adag       ADag for interacting with nodes.
	 */
	virtual bool handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag )=0;
};

}


#endif