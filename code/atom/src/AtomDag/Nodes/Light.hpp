#ifndef __atom_dag_Light__
#define __atom_dag_Light__

#include "Node.hpp"
#include <maya/MColor.h>
#include <maya/MVector.h>

namespace atom { namespace dag {

class Light : public Node {
public:
	Light( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path );
	virtual ~Light();

public:
	MVector getPosition() const; // worldspace
	MVector getDirection() const; // worldspace
	float range() const; // uses centerOfIllumination
	MColor diffuseColor() const;
	float intensity() const;
	float innerConeAngle() const; // in degrees
	float penumbraAngle() const; // in degrees
	float dropoff() const;
	bool useShadows() const;
	int shadowResolution() const;
	float shadowBias() const;
	MColor shadowColor() const;

protected:
	virtual std::string getNameInternal() const override;
	virtual void OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) override;
	virtual void OnPlugDirtied( MObject& node, MPlug& plug ) override;
	virtual void onTranslate() override;
	virtual void onRotate() override;
};

}
}

#endif