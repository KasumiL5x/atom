#include "Curve.hpp"
#include <maya/MFnNurbsCurve.h>

using namespace atom::dag;

Curve::Curve( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path ): Node(adag, object, path) {
	type_ = DagType::Curve;
}

Curve::~Curve() {
}

MPointArray Curve::getCVs() const {
	MPointArray points;
	MFnNurbsCurve(mayaObject_).getCVs(points, MSpace::kObject);
	return points;
}

std::string Curve::getNameInternal() const {
	return dagPath_.fullPathName().asChar();
}

void Curve::OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) {
	if( !((msg & MNodeMessage::kAttributeSet) && (msg & MNodeMessage::kIncomingDirection)) ) {
		return;
	}

	const char* name = plug.partialName().asChar();
	addChange(DagCallback::kCurveChanged, nullptr);
}

void Curve::OnPlugDirtied( MObject& node, MPlug& plug ) {
}

void Curve::onTranslate() {
	if( !hasChange(DagCallback::kMatrixChanged, nullptr) ) {
		addChange(DagCallback::kMatrixChanged, nullptr);
	}
}

void Curve::onRotate() {
	if( !hasChange(DagCallback::kMatrixChanged, nullptr) ) {
		addChange(DagCallback::kMatrixChanged, nullptr);
	}
}

void Curve::onScale() {
	if( !hasChange(DagCallback::kMatrixChanged, nullptr) ) {
		addChange(DagCallback::kMatrixChanged, nullptr);
	}
}