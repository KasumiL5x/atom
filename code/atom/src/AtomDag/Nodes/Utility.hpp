#ifndef __atom_dag_Utility__
#define __atom_dag_Utility__

#include <set>
#include <mutex>
#include "Node.hpp"
#include "../../ManualResetEvent.hpp"

namespace atom { namespace dag {

class Utility : public Node {
public:
	Utility( const std::shared_ptr<AtomDag>& atomdag, MObject& object, MDagPath& path );
	virtual ~Utility();

	void sendInitial();
	std::set<int> getComponentIndices();

private:
	std::set<int> getComponentIndicesInternal() const;
	std::string getOutputNodeName() const;
	bool updateInternalLink();
	void sendBasedOnNodeType();

protected:
	virtual std::string getNameInternal() const override;
	virtual void OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) override;
	virtual void OnPlugDirtied( MObject& node, MPlug& plug ) override;
	virtual void justBeforeNotify() override;
	virtual void justAfterNotify() override;

private:
	ManualResetEvent dagNodeEvent_;
	std::shared_ptr<Node> dagNode_; /**< The node this utility modifies. */
	std::mutex cachedComponentIndicesMutex_;
	std::set<int> cachedComponentIndices_;
};

}
}

#endif