#ifndef __atom_TextureWatcher__
#define __atom_TextureWatcher__

#include "IWatchHandler.hpp"
#include "../../AtomDag/DagCallbacks.hpp"

namespace atom {

namespace dag { class Texture; }

class TextureWatcher : public IWatchHandler {
public:
	TextureWatcher();
	virtual ~TextureWatcher();

	virtual bool handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) override;

private:
	void sendTexture( const std::shared_ptr<dag::Texture>& texture, const std::shared_ptr<Connection>& connection );
	void sendTextureChanged( dag::DagCallback type, const std::shared_ptr<dag::Texture>& texture, const std::shared_ptr<Connection>& connection );
};

}

#endif
