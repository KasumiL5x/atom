#ifndef __atom_MaterialWatcher__
#define __atom_MaterialWatcher__

#include "IWatchHandler.hpp"
#include "../../AtomDag/DagCallbacks.hpp"

namespace atom {

namespace dag { class Material; }

class MaterialWatcher : public IWatchHandler {
public:
	MaterialWatcher();
	virtual ~MaterialWatcher();

	virtual bool handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) override;

private:
	void sendMaterial( const std::shared_ptr<dag::Material>& material, const std::shared_ptr<Connection>& connection );
	void sendMaterialChanged( dag::DagCallback type, const std::shared_ptr<dag::Material>& material, const std::shared_ptr<Connection>& connection );
};

}

#endif
