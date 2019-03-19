#include "Annotation.hpp"
#include <maya/MFnDagNode.h>

using namespace atom::dag;

Annotation::Annotation( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path ) : Node(adag, object, path) {
	type_ = DagType::Annotation;
}

Annotation::~Annotation() {
}

const std::string Annotation::text() const {
	return MFnDagNode(mayaObject_).findPlug("text").asString().asChar();
}

std::string Annotation::getNameInternal() const {
	return dagPath_.fullPathName().asChar();
}

void Annotation::OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) {
	if( !((msg & MNodeMessage::kAttributeSet) && (msg & MNodeMessage::kIncomingDirection)) ) {
		return;
	}

	const char* name = plug.partialName().asChar();
	if( strcmp(name, "txt")==0 ) { // text(txt)
		addChange(DagCallback::kAnnotationChangedText, nullptr);
	}
}

void Annotation::OnPlugDirtied( MObject& node, MPlug& plug ) {
}

void Annotation::onTranslate() {
	if( !hasChange(DagCallback::kMatrixChanged, nullptr) ) {
		addChange(DagCallback::kMatrixChanged, nullptr);
	}
}

void Annotation::onRotate() {
	if( !hasChange(DagCallback::kMatrixChanged, nullptr) ) {
		addChange(DagCallback::kMatrixChanged, nullptr);
	}
}

void Annotation::onScale() {
	if( !hasChange(DagCallback::kMatrixChanged, nullptr) ) {
		addChange(DagCallback::kMatrixChanged, nullptr);
	}
}