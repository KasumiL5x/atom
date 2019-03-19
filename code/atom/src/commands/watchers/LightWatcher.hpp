#ifndef __atom_LightWatcher__
#define __atom_LightWatcher__

#include "IWatchHandler.hpp"
#include "../../AtomDag/DagCallbacks.hpp"
#include "../../proto/lights/LightType.pb.h"
#include <maya/MFn.h>

namespace atom {

namespace dag { class Light; }

class LightWatcher : public IWatchHandler {
public:
	LightWatcher();
	virtual ~LightWatcher();
	virtual bool handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) override;

private:
	void sendLight( const std::shared_ptr<dag::Light>& light, const std::shared_ptr<Connection>& connection );
	void sendLightChanged( dag::DagCallback type, const std::shared_ptr<dag::Light>& light, const std::shared_ptr<Connection>& connection );
	atom::proto::lights::LightType convertType( MFn::Type type ) const;
};

}

#endif