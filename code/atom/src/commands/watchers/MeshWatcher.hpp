#ifndef __atom_MeshWatcher__
#define __atom_MeshWatcher__

#include <set>
#include "IWatchHandler.hpp"

namespace atom {

namespace dag {
	class Mesh;
}

class MeshWatcher : public IWatchHandler {
public:
	MeshWatcher();
	virtual ~MeshWatcher();

	virtual bool handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) override;

private:
	void sendMesh( const std::shared_ptr<dag::Mesh>& mesh, const std::shared_ptr<Connection>& connection );
	void sendMeshPoints( const std::shared_ptr<dag::Mesh>& mesh, const std::shared_ptr<Connection>& connection, const std::set<int>& indicesData );
	void sendMeshGeometry( const std::shared_ptr<dag::Mesh>& mesh, const std::shared_ptr<Connection>& connection );
	void sendMeshMaterial( const std::shared_ptr<dag::Mesh>& mesh, const std::shared_ptr<Connection>& connection );
};

}

#endif