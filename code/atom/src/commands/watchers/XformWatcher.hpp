#ifndef __atom_XformWatcher__
#define __atom_XformWatcher__

#include "IWatchHandler.hpp"

namespace atom {

namespace dag{ class Xform; }

class XformWatcher : public IWatchHandler {
public:
	XformWatcher();
	virtual ~XformWatcher();

	virtual bool handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) override;

private:
	void sendXformData( const std::shared_ptr<dag::Xform>& xform, const std::shared_ptr<Connection>& connection );
};

}

#endif