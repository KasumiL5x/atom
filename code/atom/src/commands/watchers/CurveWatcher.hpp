#ifndef __atom_CurveWatcher__
#define __atom_CurveWatcher__

#include "IWatchHandler.hpp"

namespace atom {

namespace dag { class Curve; }

class CurveWatcher : public IWatchHandler {
public:
	CurveWatcher();
	virtual ~CurveWatcher();

	virtual bool handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) override;

private:
	void sendCurveData( const std::shared_ptr<dag::Curve>& curve, const std::shared_ptr<Connection>& connection );
};
}

#endif