#ifndef __atom_dag_Curve__
#define __atom_dag_Curve__

#include "Node.hpp"
#include <maya/MPointArray.h>

namespace atom { namespace dag {

class Curve : public Node {
public:
	Curve( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path );
	virtual ~Curve();

	MPointArray getCVs() const;

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