#include "Camera.hpp"
#include <maya/MFnCamera.h>

using namespace atom::dag;

Camera::Camera( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path ) : Node(adag, object, path) {
	type_ = DagType::Camera;
}

Camera::~Camera() {
}

MVector Camera::position() const {
	return MFnCamera(dagPath_).eyePoint(MSpace::kWorld);
}

MVector Camera::target() const {
	return MFnCamera(dagPath_).centerOfInterestPoint(MSpace::kWorld);
}

MVector Camera::up() const {
	return MFnCamera(dagPath_).upDirection(MSpace::kWorld);
}

double Camera::fieldOfView() const {
	return MFnCamera(dagPath_).verticalFieldOfView();
}

double Camera::aspectRatio() const {
	return MFnCamera(dagPath_).aspectRatio();
}

double Camera::nearPlane() const {
	return MFnCamera(dagPath_).nearClippingPlane();
}

double Camera::farPlane() const {
	return MFnCamera(dagPath_).farClippingPlane();
}

std::string Camera::getNameInternal() const {
	return dagPath_.fullPathName().asChar();
}

void Camera::OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) {
	if( !((msg & MNodeMessage::kAttributeSet) && (msg & MNodeMessage::kIncomingDirection)) ) {
		return;
	}

	const char* name = plug.partialName().asChar();
	addChange(DagCallback::kCameraChanged, nullptr);
}

void Camera::OnPlugDirtied( MObject& node, MPlug& plug ) {
}

void Camera::onTranslate() {
	addChange(DagCallback::kCameraChanged, nullptr);
}

void Camera::onRotate() {
	addChange(DagCallback::kCameraChanged, nullptr);
}