#include "Xform.hpp"
#include <maya/MFnTransform.h>

using namespace atom::dag;

Xform::Xform( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path ) : Node(adag, object, path) {
	type_ = DagType::Xform;
}

Xform::~Xform() {
}

bool Xform::addChild( const std::shared_ptr<Xform>& child ) {
	if( containsChild(child) ) {
		return false;
	}

	if( child->parent() != nullptr ) {
		child->parent()->removeChild(child);
	}

	children_.insert(child);
	child->setParent(std::static_pointer_cast<Xform>(shared_from_this()));

	return true;
}

bool Xform::removeChild( const std::shared_ptr<Xform>& child ) {
	const auto existing = std::find(std::begin(children_), std::end(children_), child);
	if( children_.end() == existing ) {
		return false;
	}
	(*existing)->setParent(nullptr);
	children_.erase(existing);
	return true;
}

bool Xform::containsChild( const std::shared_ptr<Xform>& child ) {
	return children_.end() != std::find(std::begin(children_), std::end(children_), child);
}

const std::set<std::shared_ptr<Xform>>& Xform::children() const {
	return children_;
}

bool Xform::addComponent( const std::shared_ptr<Node>& component ) {
	if( containsComponent(component) ) {
		return false;
	}

	if( component->parent() != nullptr ) {
		component->parent()->removeComponent(component);
	}

	components_.insert(component);
	component->setParent(std::static_pointer_cast<Xform>(shared_from_this()));

	return true;
}
bool Xform::removeComponent( const std::shared_ptr<Node>& component ) {
	const auto existing = std::find(std::begin(components_), std::end(components_), component);
	if( components_.end() != existing ) {
		return false;
	}
	(*existing)->setParent(nullptr);
	components_.erase(existing);
	return true;
}

bool Xform::containsComponent( const std::shared_ptr<Node>& component ) {
	return components_.end() != std::find(std::begin(components_), std::end(components_), component);
}
const std::set<std::shared_ptr<Node>>& Xform::components() const {
	return components_;
}

MVector Xform::position( bool world ) const {
	return MFnTransform(dagPath_).getTranslation(world ? MSpace::kWorld : MSpace::kObject);
}

void Xform::forceUpdateName() {
	Node::forceUpdateName();

	for( const auto& child : children_ ) {
		child->forceUpdateName();
	}

	for( const auto& comp : components_ ) {
		comp->forceUpdateName();
	}
}

std::string Xform::getNameInternal() const {
	return (MFn::kWorld==mayaObject_.apiType()) ? "ROOT" : dagPath_.fullPathName().asChar();
}

void Xform::OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) {
	if( !((msg & MNodeMessage::kAttributeSet) && (msg & MNodeMessage::kIncomingDirection)) ) {
		return;
	}

	const char* plugName = plug.partialName().asChar();
	if( strcmp("t", plugName)==0 || strcmp("tx", plugName)==0 || strcmp("ty", plugName)==0 || strcmp("tz", plugName)==0 ) {
		onTranslate();
	}	
	if( strcmp("r", plugName)==0 || strcmp("rx", plugName)==0 || strcmp("ry", plugName)==0 || strcmp("rz", plugName)==0 ) {
		onRotate();
	}
	if( strcmp("s", plugName)==0 || strcmp("sx", plugName)==0 || strcmp("sy", plugName)==0 || strcmp("sz", plugName)==0 ) {
		onScale();
	}
}

void Xform::OnPlugDirtied( MObject& node, MPlug& plug ) {
}

void Xform::onTranslate() {
	addChange(DagCallback::kTranslated, nullptr);
	for( const auto& comp : components_ ) {
		comp->onTranslate();
	}
	for( const auto& child : children_ ) {
		child->onTranslate();
	}
}

void Xform::onRotate() {
	addChange(DagCallback::kRotated, nullptr);
	for( const auto& comp : components_ ) {
		comp->onRotate();
	}
	for( const auto& child : children_ ) {
		child->onRotate();
	}
}

void Xform::onScale() {
	addChange(DagCallback::kScaled, nullptr);
	for( const auto& comp : components_ ) {
		comp->onScale();
	}
	for( const auto& child : children_ ) {
		child->onScale();
	}
}