#ifndef __atom_dag_Camera__
#define __atom_dag_Camera__

#include "Node.hpp"
#include <maya/MVector.h>

namespace atom { namespace dag {

class Camera : public Node {
public:
	Camera( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path );
	virtual ~Camera();

	MVector position() const; // worldspace
	MVector target() const; // worldspace
	MVector up() const; // worldspace
	double fieldOfView() const;
	double aspectRatio() const;
	double nearPlane() const;
	double farPlane() const;

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