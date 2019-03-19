#ifndef __atom_dag_Node__
#define __atom_dag_Node__

#include <memory>
#include <string>
#include <set>
#include <atomic>
#include <unordered_map>
#include <maya/MObject.h>
#include <maya/MDagPath.h>
#include "DagType.hpp"
#include <maya/MNodeMessage.h>
#include <maya/MPlug.h>
#include <maya/MMatrix.h>
#include "../DagCallbacks.hpp"
#include "../../ManualResetEvent.hpp"

namespace atom { namespace dag {

class Xform;
class AtomDag;

class Node : public std::enable_shared_from_this<Node> {
	friend class Xform;

public:
	Node( const std::shared_ptr<AtomDag>& atomdag, MObject& object, MDagPath& path );
	virtual ~Node();

	DagType type() const; // can safely cast to child type based on this
	const std::shared_ptr<Xform>& parent() const; // can be null
	const MObject& mayaObject() const;
	const MDagPath& dagPath() const; // non-dag nodes don't have a vaild path
	void setParent( const std::shared_ptr<Xform>& newParent );
	const std::string& name(); // uses full path name, or just node name if it doesn't have a path
	const std::string& lastName();
	bool isDirty(); // dirty nodes have pending changes to be sent
	virtual void justBeforeNotify(){} // called just before notifying watchers of pending changes; good place to add last second messages
	void addWatcher( const OnNodeChanged& func, const std::string& id );
	virtual void justAfterNotify(){} // called just after notify is complete; can clean things up here
	void removeWatcher( const std::string& id );
	void notifyWatchers(); // notifies of pending changes
	virtual	void forceUpdateName(); // xform overrides to update children
	bool isVisible() const;
	MMatrix transformationMatrix( bool world ) const;

protected:
	bool hasChange( DagCallback type, const std::shared_ptr<Node>& instigator );
	void addChange( DagCallback type, std::shared_ptr<Node> instigator );
	void justDirty();
	void OnMayaNameChanged();
	virtual void OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug )=0; // called when Maya detects an attribute changed
	virtual void OnPlugDirtied( MObject& node, MPlug& plug )=0; // called when Maya detects a plug has been dirtied
	virtual void onTranslate(){}
	virtual void onRotate(){};
	virtual void onScale(){};
	virtual std::string getNameInternal() const=0;
	
private:
	void initializeName();
	void addVisibilityChange();

protected:
	DagType type_;                  /**< DagType this node represents.  Derived classes should set this in the constructor. */
	std::shared_ptr<Xform> parent_; /**< Parent Xform.  Can be null for certain node types. */
	std::shared_ptr<AtomDag> adag_; /**< Handy-dandy pointer to the AtomDag system.  Useful for utilities to find nodes, etc. */
	MObject mayaObject_;            /**< Maya's internal MObject of the node. */
	MDagPath dagPath_;              /**< Maya's internal MDagPath of the node. */

private:
	std::string name_;                    /**< The node's name.  Derived classes should set this in the constructor and update it, too. */
	std::string lastName_;                /**< The node's previous name. */
	std::string lastValidName_;
	bool firstTimeGettingName_;           /**< To avoid pure virtual in constructor, lazy-get the name. */
	MCallbackId nameChangedCbId_;         /**< Callback ID for name changed. */
	MCallbackId attribChangedCbId_;       /**< Callback ID for attribute changed. */
	MCallbackId plugDirtiedCbId_;         /**< Callback ID for plug dirtied. *///plugDirtyCbId_
	ManualResetEvent callbackResetEvent_; /**< To ensure only one current call of OnInternalNameChanged. */
	ManualResetEvent changeResetEvent_;   /**< To ensure only one current call of OnAttributeChanged. */
	std::atomic<bool> isDirty_;           /**< A node is considered dirty if it has pending changes. */
	std::set<std::pair<DagCallback, std::shared_ptr<Node>>> dirtyCallbacks_; /**< Set of changes pending to be handled with their instigator (can be null). */
	std::unordered_map<std::string, OnNodeChanged> watchers_; /**< Watchers for when the node changes.  Notifications are sent out for pending changes. */
};

}
}

#endif