#include "Node.hpp"
#include <maya/MString.h>
#include <maya/MFnTransform.h>
#include "Xform.hpp"
#include "../../MTLog.hpp"

using namespace atom::dag;

Node::Node( const std::shared_ptr<AtomDag>& atomdag, MObject& object, MDagPath& path )
	: type_(DagType::Invalid), parent_(nullptr), adag_(atomdag), mayaObject_(object), dagPath_(path),
		name_(""), lastName_(""), lastValidName_(""), firstTimeGettingName_(true), nameChangedCbId_(0), attribChangedCbId_(0), plugDirtiedCbId_(0), isDirty_(false) {
	callbackResetEvent_.set();
	changeResetEvent_.set();

	// callback for name changing
	nameChangedCbId_ = MNodeMessage::addNameChangedCallback(object, [](MObject& node, const MString& str, void* clientData){
		const auto nodePtr = reinterpret_cast<Node*>(clientData);
		nodePtr->callbackResetEvent_.waitOne();
		nodePtr->OnMayaNameChanged();
		nodePtr->callbackResetEvent_.set();
	}, this);
	// callback for attributes changing
	attribChangedCbId_ = MNodeMessage::addAttributeChangedCallback(object, [](MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug, void* clientData){
		const auto nodePtr = reinterpret_cast<Node*>(clientData);
		nodePtr->callbackResetEvent_.waitOne();
		nodePtr->OnAttributeChanged(msg, plug, otherPlug);
		nodePtr->callbackResetEvent_.set();
	}, this);
	// callback for plugs dirtying
	plugDirtiedCbId_ = MNodeMessage::addNodeDirtyPlugCallback(object, [](MObject& node, MPlug& plug, void* clientData){
		const auto nodePtr = reinterpret_cast<Node*>(clientData);
		nodePtr->callbackResetEvent_.waitOne();

		const char* name = plug.partialName().asChar();

		// handle common visiblity change
		if( strcmp(name, "v")==0 || strcmp(name, "ovv")==0 || strcmp(name, "ove")==0 || strcmp(name, "do")==0 ) { // visibility(v) or overrideVisibility(ovv) or overrideEnabled(ove) or drawOverride(do)
			nodePtr->addVisibilityChange();
		}

		nodePtr->OnPlugDirtied(node, plug);
		nodePtr->callbackResetEvent_.set();
	}, this);
}

Node::~Node() {
	if( plugDirtiedCbId_ != 0 ) {
		MNodeMessage::removeCallback(plugDirtiedCbId_);
		plugDirtiedCbId_ = 0;
	}
	if( attribChangedCbId_ != 0 ) {
		MNodeMessage::removeCallback(attribChangedCbId_);
		attribChangedCbId_ = 0;
	}
	if( nameChangedCbId_ != 0 ) {
		MNodeMessage::removeCallback(nameChangedCbId_);
		nameChangedCbId_ = 0;
	}
}

DagType Node::type() const {
	return type_;
}

const std::shared_ptr<Xform>& Node::parent() const {
	return parent_;
}

const MObject& Node::mayaObject() const {
	return mayaObject_;
}

const MDagPath& Node::dagPath() const {
	return dagPath_;
}

void Node::setParent( const std::shared_ptr<Xform>& newParent ) {
	parent_ = newParent;
}

const std::string& Node::name() {
	initializeName();
	return name_;
}

const std::string& Node::lastName() {
	initializeName();
	return lastName_;
}

bool Node::isDirty() {
	return isDirty_;
}

void Node::addWatcher( const OnNodeChanged& func, const std::string& id ) {
	watchers_.insert(std::make_pair(id, func));
}

void Node::removeWatcher( const std::string& id ) {
	watchers_.erase(id);
}

void Node::notifyWatchers() {
	changeResetEvent_.waitOne();

	if( !isDirty_ ) {
		return;
	}

	// if the names are equal, remove the name change event and reset the last name
	if( strcmp(lastName_.c_str(), name_.c_str())==0 && hasChange(DagCallback::kNameChanged, nullptr) ) {
		dirtyCallbacks_.erase(std::make_pair(DagCallback::kNameChanged, nullptr)); // name changed is instigated by itself
		lastName_ = lastValidName_;
	}

	const auto thisShared = shared_from_this();

	std::vector<std::string> toRemove;
	for( auto& cb : watchers_ ) {
		for( auto& change : dirtyCallbacks_ ) {
			if( !cb.second(change.first, thisShared, change.second) ) {
				toRemove.push_back(cb.first);
			}
		}
	}
	for( const auto& id : toRemove ) {
		watchers_.erase(id);
	}

	isDirty_ = false;
	dirtyCallbacks_.clear();

	changeResetEvent_.set();
}

void Node::forceUpdateName() {
	OnMayaNameChanged();
}

bool Node::isVisible() const {
	// ignore non-dag nodes like utilities
	if( !mayaObject_.hasFn(MFn::kDagNode) ) {
		return false;
	}

	const MFnDagNode thisNode(dagPath_);
	const bool ownVisibility = thisNode.findPlug("visibility").asBool(); // as in [Display->Visibility]
	const bool overrideVisibility = (!thisNode.findPlug("overrideEnabled").asBool()) ? true : thisNode.findPlug("overrideVisibility").asBool(); // as in [Drawing Overrides->Visible] if [Drawing Overrides->Enable Overrides]
	const bool parentVisibility = nullptr==parent_ ? true : parent_->isVisible();

	return ownVisibility && overrideVisibility && parentVisibility;
}

MMatrix Node::transformationMatrix( bool world ) const {
	if( DagType::Xform == type_ ) {
		if( !world || nullptr == parent_ ) {
			return MFnTransform(mayaObject_).transformation().asMatrix();
		}
		return MFnTransform(mayaObject_).transformation().asMatrix() * parent_->transformationMatrix(true);
	} else {
		if( nullptr == parent_ ) {
			return MMatrix();
		}
		return parent_->transformationMatrix(world);
	}
}

bool Node::hasChange( DagCallback type, const std::shared_ptr<Node>& instigator ) {
	changeResetEvent_.waitOne();
	const bool has = dirtyCallbacks_.find(std::make_pair(type, instigator)) != dirtyCallbacks_.end();
	changeResetEvent_.set();
	return has;
}

void Node::addChange( DagCallback type, std::shared_ptr<Node> instigator ) {
	changeResetEvent_.waitOne();
	if( dirtyCallbacks_.end() == dirtyCallbacks_.find(std::make_pair(type, instigator)) ) { // only add an event if its pair doesn't already exist
		dirtyCallbacks_.insert(std::make_pair(type, instigator));
		isDirty_ = true;
		//MTLog::instance()->log("addChange(" + DagCallbackToString(type) + ")\n");
	}
	changeResetEvent_.set();
}

void Node::justDirty() {
	changeResetEvent_.waitOne();
	isDirty_ = true;
	changeResetEvent_.set();
}

void Node::OnMayaNameChanged() {
	// when undoing a rename, sometimes it is called twice (for meshes and so on).
	// comparing this ensures the new name isn't the same as the existing name.
	if( strcmp(getNameInternal().c_str(), name_.c_str()) == 0 ) {
		return;
	}

	initializeName();

	// update the last name if there's no name changed event.  this is so that if multiple
	// rename events are called, we preserve the original name the client knows about.  the
	// last name before changing is also stored, as in the event of an undo, which results
	// in the last name and current name now being equal, we need to be able to reset the
	// last name accordingly.  this check is done above just before notifying.
	if( !hasChange(DagCallback::kNameChanged, nullptr) ) {
		lastValidName_ = lastName_;
		lastName_ = name_;
	}
	name_ = getNameInternal();
	addChange(DagCallback::kNameChanged, nullptr);

	//MTLog::instance()->log("Node::OnMayaNameChanged(" + lastValidName_ + "/" + lastName_ + "=>" + name_ + ")\n");
}

void Node::initializeName() {
	if( firstTimeGettingName_ ) {
		lastValidName_ = lastName_ = name_ = getNameInternal();
		firstTimeGettingName_ = false;

		//MTLog::instance()->log("Name initialized: " + name_ + "\n");
	}
}

void Node::addVisibilityChange() {
	addChange(DagCallback::kVisibilityChanged, nullptr);

	if( DagType::Xform == type_ ) {
		for( const auto& child : reinterpret_cast<Xform*>(this)->children() ) {
			child->addVisibilityChange();
		}
		for( const auto& comp : reinterpret_cast<Xform*>(this)->components() ) {
			comp->addVisibilityChange();
		}
	}
}