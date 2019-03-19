#ifndef __atom_dag_AtomDag__
#define __atom_dag_AtomDag__

#include <memory>
#include <set>
#include <vector>
#include <string>
#include <mutex>
#include <unordered_map>
#include <functional>
#include "Nodes/Node.hpp"
#include "Nodes/Xform.hpp"
#include <maya/MDGMessage.h>
#include <maya/MDagMessage.h>
#include <maya/MObject.h>
#include <maya/MObjectHandle.h>

namespace atom { namespace dag {

enum class RebuildCause {
	Initialized,
	NewScene,
	OpenScene,
	Forced
};

struct MObjectHandleHasher {
	std::size_t operator()( const MObjectHandle& handle ) const {
		return handle.hashCode();
	}
};

class AtomDag : public std::enable_shared_from_this<AtomDag> {
public:
	typedef std::function<void(RebuildCause cause)> OnRebuild; 
	typedef std::function<void(const std::shared_ptr<Node>& node)> ForAllFunc;
	typedef std::function<void(const std::shared_ptr<Node>& node)> OnNodeAdded;
	typedef std::function<void(std::shared_ptr<Node> node)> OnNodeRemoved; // copy because otherwise it will go out of scope

public:
	AtomDag();
	~AtomDag();

	bool initialize();
	void uninitialize();

	void clear();
	void rebuild( RebuildCause cause );

	void print( int indent );

	std::shared_ptr<Node> findNodeByName( const std::string& name );
	std::shared_ptr<Node> findNodeByObject( const MObjectHandle& object );

	void forAllNodes( ForAllFunc func );

	void addRebuildWatcher( const OnRebuild& func );
	void addNodeAddedWatcher( const OnNodeAdded& func );
	void addNodeRemovedWatcher( const OnNodeRemoved& func );

private:
	void createRoot();
	void processNode( const std::shared_ptr<Xform>& node );
	std::shared_ptr<Node> createNode( MObject& object );
	bool shouldIgnoreName( const std::string& name );
	bool shouldIgnoreType( MFn::Type type );
	void addNode( const std::shared_ptr<Node>& node );
	void printInternal( const std::shared_ptr<Xform>& node, int indent, int increment );
	void MayaNodeAddedCallback( MObject& node );
	void MayaNodeRemovedCallback( MObject& node );
	void MayaNodeAddedIdleCallback();
	void MayaConnectionCallback( MPlug& srcPlug, MPlug& destPlug, bool made );
	void MayaChildAddedCallback( const MDagPath& child, const MDagPath& parent );

private:
	bool initialized_;
	std::shared_ptr<Xform> root_;
	std::set<std::string> ignoreNames_;
	std::set<MFn::Type> ignoreTypes_;
	std::mutex nodesMutex_;
	std::set<std::shared_ptr<Node>> allNodes_;
	std::set<std::shared_ptr<Node>> allXforms_;
	std::set<std::shared_ptr<Node>> allMeshes_;
	std::set<std::shared_ptr<Node>> allCameras_;
	std::set<std::shared_ptr<Node>> allLights_;
	std::set<std::shared_ptr<Node>> allTextures_;
	std::set<std::shared_ptr<Node>> allMaterials_;
	std::set<std::shared_ptr<Node>> allUtilities_;
	std::set<std::shared_ptr<Node>> allAnnotations_;
	std::set<std::shared_ptr<Node>> allCurves_;
	
	std::unordered_map<MObjectHandle, std::shared_ptr<Node>, MObjectHandleHasher> objectNodeMap_;

	MCallbackId nodeAddedCbId_;
	MCallbackId nodeRemovedCbId_;
	MCallbackId nodeAddedIdleCbId_;
	std::vector<MObject> nodesAddedToProcess_;
	std::mutex nodesAddedToProcessMutex_;

	std::vector<OnRebuild> rebuildCallbacks_;
	std::vector<OnNodeAdded> nodeAddedCallbacks_;
	std::vector<OnNodeRemoved> nodeRemovedCallbacks_;

	MCallbackId connectionCbId_;
	MCallbackId childAddedCbId_;
};

}
}

#endif