#include "Light.hpp"
#include <maya/MFnLight.h>
#include <maya/MFnSpotLight.h>
#include "Xform.hpp"

using namespace atom::dag;

Light::Light( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path ) : Node(adag, object, path) {
	type_ = DagType::Light;
}

Light::~Light() {
}

MVector Light::getPosition() const {
	return parent()->position(true);
}

MVector Light::getDirection() const {
	return MFnLight(dagPath_).lightDirection(0, MSpace::kWorld).normal();
}

float Light::range() const {
	return static_cast<float>(MFnLight(dagPath_).centerOfIllumination());
}

MColor Light::diffuseColor() const {
	return MFnLight(dagPath_).color();
}

float Light::intensity() const {
	return MFnLight(dagPath_).intensity();
}

float Light::innerConeAngle() const {
	return (MFn::kSpotLight == mayaObject_.apiType()) ? ((float)MFnSpotLight(dagPath_).coneAngle()*0.5f) * 57.29578f : 0.0f;
}

float Light::penumbraAngle() const {
	if( mayaObject_.apiType() != MFn::kSpotLight ) {
		return 0.0f;
	}
	return static_cast<float>(MFnSpotLight(dagPath_).penumbraAngle()) * 57.29578f;
}

float Light::dropoff() const {
	if( mayaObject_.apiType() != MFn::kSpotLight ) {
		return 0.0f;
	}
	return static_cast<float>(MFnSpotLight(dagPath_).dropOff());
}

bool Light::useShadows() const {
	if( MFn::kAmbientLight == mayaObject_.apiType() ) {
		return false;
	}
	return MFnNonExtendedLight(dagPath_).useDepthMapShadows();
}

int Light::shadowResolution() const {
	if( MFn::kAmbientLight == mayaObject_.apiType() ) {
		return 0;
	}
	return static_cast<int>(MFnNonExtendedLight(dagPath_).depthMapResolution(nullptr));
}

float Light::shadowBias() const {
	if( MFn::kAmbientLight == mayaObject_.apiType() ) {
		return 0;
	}
	return MFnNonExtendedLight(dagPath_).depthMapBias(nullptr);
}

MColor Light::shadowColor() const {
	return MFnLight(dagPath_).shadowColor();
}

std::string Light::getNameInternal() const {
	return dagPath_.fullPathName().asChar();
}

void Light::OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) {
	if( !((msg & MNodeMessage::kAttributeSet) && (msg & MNodeMessage::kIncomingDirection)) ) {
		return;
	}

	const char* name = plug.partialName().asChar();

	DagCallback DagCallback;
	bool changed = false;

	if( strcmp(name, "col")==0 ) { // centerOfIllumination/col
		DagCallback = DagCallback::kLightChangedRange;
		changed = true;
	} else if( strcmp(name, "cl")==0 ) { // color/cl
		DagCallback = DagCallback::kLightChangedColor;
		changed = true;
	} else if( strcmp(name, "in")==0 ) { // intensity(in)
		DagCallback = DagCallback::kLightChangedIntensity;
		changed = true;
	} else if( strcmp(name, "ca")==0 ) { // coneAngle/ca
		DagCallback = DagCallback::kLightChangedConeAngle;
		changed = true;
	} else if( strcmp(name, "pa")==0 ) { // penumbraAngle/pa
		DagCallback = DagCallback::kLightChangedPenumbraAngle;
		changed = true;
	} else if( strcmp(name, "dro")==0 ) { // dropoff/dro
		DagCallback = DagCallback::kLightChangedDropoff;
		changed = true;
	} else if( strcmp(name, "dms")==0 ) { // useDepthMapShadows/dms
		DagCallback = DagCallback::kLightChangedShadows;
		changed = true;
	} else if( strcmp(name, "dr")==0 ) { // dmapResolution/dr
		DagCallback = DagCallback::kLightChangedShadowResolution;
		changed = true;
	} else if( strcmp(name, "db")==0 ) { // dmapBias/db
		DagCallback = DagCallback::kLightChangedShadowBias;
		changed = true;
	} else if( strcmp(name, "sc")==0 ) { // shadowColor/sc
		DagCallback = DagCallback::kLightChangedShadowColor;
		changed = true;
	}

	if( changed ) {
		addChange(DagCallback, nullptr);
	}
}

void Light::OnPlugDirtied( MObject& node, MPlug& plug ) {
}

void Light::onTranslate() {
	addChange(DagCallback::kLightChangedPosition, nullptr);
}

void Light::onRotate() {
	addChange(DagCallback::kLightChangedDirection, nullptr);
}