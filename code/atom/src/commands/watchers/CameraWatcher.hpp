#ifndef __atom_CameraWatcher__
#define __atom_CameraWatcher__

#include "IWatchHandler.hpp"

namespace atom {

namespace dag { class Camera; }

class CameraWatcher : public IWatchHandler {
public:
	CameraWatcher();
	virtual ~CameraWatcher();

	virtual bool handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) override;

private:
	void sendCameraData( const std::shared_ptr<dag::Camera>& camera, const std::shared_ptr<Connection>& connection );
};

}

#endif
