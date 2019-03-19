#ifndef __atom_dag_Annotation__
#define __atom_dag_Annotation__

#include "Node.hpp"

namespace atom { namespace dag {

class Annotation : public Node {
public:
	Annotation( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path );
	virtual ~Annotation();

	const std::string text() const;

protected:
	virtual std::string getNameInternal() const override;
	virtual void OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) override;
	virtual void OnPlugDirtied( MObject& node, MPlug& plug ) override;
	virtual void onTranslate() override;
	virtual void onRotate() override;
	virtual void onScale() override;
};

}
}

#endif