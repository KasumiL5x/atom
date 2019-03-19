#ifndef __atom_dag_Xform__
#define __atom_dag_Xform__

#include <set>
#include "Node.hpp"
#include <maya/MVector.h>
#include <maya/MMatrix.h>

namespace atom { namespace dag {

class Xform : public Node {
public:
	Xform( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path );
	virtual ~Xform();

	bool addChild( const std::shared_ptr<Xform>& child ); // automatically handles re-parenting
	bool removeChild( const std::shared_ptr<Xform>& child );
	bool containsChild( const std::shared_ptr<Xform>& child );
	const std::set<std::shared_ptr<Xform>>& children() const;

	bool addComponent( const std::shared_ptr<Node>& component ); // automatically handles re-parenting
	bool removeComponent( const std::shared_ptr<Node>& component );
	bool containsComponent( const std::shared_ptr<Node>& component );
	const std::set<std::shared_ptr<Node>>& components() const;

	MVector position( bool world ) const;

	virtual	void forceUpdateName() override; 

protected:
	virtual std::string getNameInternal() const override;
	virtual void OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) override;
	virtual void OnPlugDirtied( MObject& node, MPlug& plug ) override;
	virtual void onTranslate() override;
	virtual void onRotate() override;
	virtual void onScale() override;

private:
	std::set<std::shared_ptr<Xform>> children_;
	std::set<std::shared_ptr<Node>> components_; // components can be things like meshes, cameras, etc.
};

}
}

#endif