#ifndef __atom_AnnotationWatcher__
#define __atom_AnnotationWatcher__

#include "IWatchHandler.hpp"

namespace atom {

namespace dag { class Annotation; }

class AnnotationWatcher : public IWatchHandler {
public:
	AnnotationWatcher();
	virtual ~AnnotationWatcher();

	virtual bool handle( std::shared_ptr<dag::Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) override;

private:
	void sendAnnotationData( const std::shared_ptr<dag::Annotation>& annotation, const std::shared_ptr<Connection>& connection );
};

}

#endif