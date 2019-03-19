#include "Material.hpp"
#include <maya/MPlugArray.h>
#include <maya/MFnDependencyNode.h>
#include "../../MTLog.hpp"

using namespace atom::dag;

Material::Material( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path ) : Node(adag, object, path),
	shaderPlugDirtyCbId_(0) {
	type_ = DagType::Material;
	if( !updateShaderObject() ) {
		MTLog::instance()->log("Material::updateShaderObject failed.\n");
	}
}

Material::~Material() {
	removeShaderCallbacks();
}

MObject Material::shaderObject() const {
	return shaderObject_;
}

MColor Material::getColor() const {
	return getColorFromPlug("color");
}

MColor Material::getTransparency() const {
	return getColorFromPlug("transparency");
}

MColor Material::getAmbientColor() const {
	return getColorFromPlug("ambientColor");
}

MColor Material::getIncandescence() const {
	return getColorFromPlug("incandescence");
}

float Material::getDiffuseAmount() const {
	return getSingleFromPlug("diffuse");
}

float Material::getTranslucence() const {
	return getSingleFromPlug("translucence");
}

float Material::getTranslucenceDepth() const {
	return getSingleFromPlug("translucenceDepth");
}

float Material::getTranslucenceFocus() const {
	return getSingleFromPlug("translucenceFocus");
}

float Material::getGlowIntensity() const {
	return getSingleFromPlug("glowIntensity");
}

MColor Material::getSpecularColor() const {
	return getColorFromPlug("specularColor");
}

float Material::getReflectivity() const {
	return getSingleFromPlug("reflectivity");
}

MColor Material::getReflectedColor() const {
	return getColorFromPlug("reflectedColor");
}

float Material::getRoughness() const {
	return getSingleFromPlug("roughness");
}

float Material::getCosinePower() const {
	return getSingleFromPlug("cosinePower");
}

float Material::getHighlightSize() const {
	return getSingleFromPlug("highlightSize");
}

MColor Material::getWhiteness() const {
	return getColorFromPlug("whiteness");
}

float Material::getEccentricity() const {
	return getSingleFromPlug("eccentricity");
}

float Material::getSpecularRollOff() const {
	return getSingleFromPlug("specularRollOff");
}

float Material::getAngle() const {
	return getSingleFromPlug("angle");
}

float Material::getSpreadX() const {
	return getSingleFromPlug("spreadX");
}

float Material::getSpreadY() const {
	return getSingleFromPlug("spreadY");
}

float Material::getFresnelIndex() const {
	return getSingleFromPlug("fresnelRefractiveIndex");
}

std::string Material::getColorTexture() const {
	return getTextureFromPlug("color");
}

std::string Material::getTransparencyTexture() const {
	return getTextureFromPlug("transparency");
}

std::string Material::getAmbientColorTexture() const {
	return getTextureFromPlug("ambientColor");
}

std::string Material::getIncandescenceTexture() const {
	return getTextureFromPlug("incandescence");
}

std::string Material::getDiffuseAmountTexture() const {
	return getTextureFromPlug("diffuse");
}

std::string Material::getTranslucenceTexture() const {
	return getTextureFromPlug("translucence");
}

std::string Material::getTranslucenceDepthTexture() const {
	return getTextureFromPlug("translucenceDepth");
}

std::string Material::getTranslucenceFocusTexture() const {
	return getTextureFromPlug("translucenceFocus");
}

std::string Material::getGlowIntensityTexture() const {
	return getTextureFromPlug("glowIntensity");
}

std::string Material::getSpecularColorTexture() const {
	return getTextureFromPlug("specularColor");
}

std::string Material::getReflectivityTexture() const {
	return getTextureFromPlug("reflectivity");
}

std::string Material::getReflectedColorTexture() const {
	return getTextureFromPlug("reflectedColor");
}

std::string Material::getRoughnessTexture() const {
	return getTextureFromPlug("roughness");
}

std::string Material::getCosinePowerTexture() const {
	return getTextureFromPlug("cosinePower");
}

std::string Material::getHighlightSizeTexture() const {
	return getTextureFromPlug("highlightSize");
}

std::string Material::getWhitenessTexture() const {
	return getTextureFromPlug("whiteness");
}

std::string Material::getEccentricityTexture() const {
	return getTextureFromPlug("eccentricity");
}

std::string Material::getSpecularRollOffTexture() const {
	return getTextureFromPlug("specularRollOff");
}

std::string Material::getAngleTexture() const {
	return getTextureFromPlug("angle");
}

std::string Material::getSpreadXTexture() const {
	return getTextureFromPlug("spreadX");
}

std::string Material::getSpreadYTexture() const {
	return getTextureFromPlug("spreadY");
}

std::string Material::getFresnelIndexTexture() const {
	return getTextureFromPlug("fresnelRefractiveIndex");
}

std::string Material::getBumpTexture() const {
	const MPlug normalCamera = MFnDependencyNode(shaderObject_).findPlug("normalCamera");
	MPlugArray normalCameraPlugArray;
	if( normalCamera.connectedTo(normalCameraPlugArray, true, false) ) {
		const MObject bumpNode = normalCameraPlugArray[0].node();
		if( bumpNode.hasFn(MFn::kBump) ) { // bump2d
			const MPlug bumpValuePlug = MFnDependencyNode(bumpNode).findPlug("bumpValue");
			MPlugArray bumpValuePlugArray;
			if( bumpValuePlug.connectedTo(bumpValuePlugArray, true, false) ) {
				if( bumpValuePlugArray[0].node().hasFn(MFn::kFileTexture) ) {
					return MFnDependencyNode(bumpValuePlugArray[0].node()).name().asChar();
				}
			}
		}
	}
	return "";
}

std::string Material::getTextureFromPlug( const std::string& plugName ) const {
	const auto plug = MFnDependencyNode(shaderObject_).findPlug(plugName.c_str());
	MPlugArray plugArray;
	if( plug.connectedTo(plugArray, true, false) ) {
		if( plugArray[0].node().hasFn(MFn::kFileTexture) ) { // todo: or psd?
			return MFnDependencyNode(plugArray[0].node()).name().asChar();
		}
	}
	return "";
}

MColor Material::getColorFromPlug( const std::string& plugName ) const {
	const auto plug = MFnDependencyNode(shaderObject_).findPlug(plugName.c_str(), true);
	if( plug.numChildren() != 3 ) { // RGB
		return MColor(0.0f, 0.0f, 0.0f, 1.0f);
	}
	return MColor(plug.child(0).asFloat(), plug.child(1).asFloat(), plug.child(2).asFloat());
}

float Material::getSingleFromPlug( const std::string& plugName ) const {
	return MFnDependencyNode(shaderObject_).findPlug(plugName.c_str(), true).asFloat();
}

bool Material::updateShaderObject() {
	// gets surfaceShader plug
	const MPlug surfaceShader = MFnDependencyNode(mayaObject_).findPlug("surfaceShader", false);
	if( !surfaceShader.isDestination() ) {
		shaderObject_ = MObject::kNullObj;
		removeShaderCallbacks();
		return false;
	}

	// get shader connected to surfaceShader plug
	MPlugArray shaderArray;
	surfaceShader.connectedTo(shaderArray, true, false);
	if( !shaderArray.length() ) {
		shaderObject_ = MObject::kNullObj;
		removeShaderCallbacks();
		return false;
	}

	// check for valid shader type
	const MObject theShader = shaderArray[0].node();
	if( theShader.apiType() != MFn::kLambert && theShader.apiType() != MFn::kBlinn && theShader.apiType() != MFn::kPhong && theShader.apiType() != MFn::kPhongExplorer && theShader.apiType() != MFn::kAnisotropy ) {
		shaderObject_ = MObject::kNullObj;
		removeShaderCallbacks();
		return false;
	}

	// update local shader
	shaderObject_ = theShader;

	// update shader callbacks for new shader
	removeShaderCallbacks();
	addShaderCallbacks();

	return true;
}

void Material::addShaderCallbacks() {
	shaderPlugDirtyCbId_ = MNodeMessage::addNodeDirtyPlugCallback(shaderObject_, [](MObject& node,MPlug& plug,void* clientData){
		static_cast<Material*>(clientData)->onPlugDirtied(node, plug, clientData);
	}, this);
}

void Material::removeShaderCallbacks() {
	if( shaderPlugDirtyCbId_ != 0 ) {
		MNodeMessage::removeCallback(shaderPlugDirtyCbId_);
		shaderPlugDirtyCbId_= 0;
	}
}

void Material::onPlugDirtied( MObject& node, MPlug& plug, void* clientData ) {
	const char* name = plug.partialName().asChar();

	bool changed = false;
	DagCallback DagCallback;

	if( strcmp("c", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedColor;
		changed = true;
	} else if( strcmp("it", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedTransparency;
		changed = true;
	} else if( strcmp("ambc", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedAmbientColor;
		changed = true;
	} else if( strcmp("ic", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedIncandescence;
		changed = true;
	} else if( strcmp("dc", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedDiffuseAmount;
		changed = true;
	} else if( strcmp("tc", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedTranslucence;
		changed = true;
	} else if( strcmp("trsd", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedTranslucenceDepth;
		changed = true;
	} else if( strcmp("tcf", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedTranslucenceFocus;
		changed = true;
	} else if( strcmp("gi", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedGlowIntensity;
		changed = true;
	} else if( strcmp("sc", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedSpecularColor;
		changed = true;
	} else if( strcmp("rfl", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedReflectivity;
		changed = true;
	} else if( strcmp("rc", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedReflectedColor;
		changed = true;
	} else if( strcmp("rn", name)==0 || strcmp("roug", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedRoughness;
		changed = true;
	} else if( strcmp("cp", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedCosinePower;
		changed = true;
	} else if( strcmp("hls", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedHighlightSize;
		changed = true;
	} else if( strcmp("wn", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedWhiteness;
		changed = true;
	} else if( strcmp("ec", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedEccentricity;
		changed = true;
	} else if( strcmp("sro", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedSpecularRollOff;
		changed = true;
	} else if( strcmp("angl", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedAngle;
		changed = true;
	} else if( strcmp("sprx", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedSpreadX;
		changed = true;
	} else if( strcmp("spry", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedSpreadY;
		changed = true;
	} else if( strcmp("frfi", name)==0 ) {
		DagCallback = DagCallback::kMaterialChangedFresnelIndex;
		changed = true;
	} else if( strcmp("n", name)==0 ) { // normalCamera(n)
		DagCallback = DagCallback::kMaterialChangedBumpTexture;
		changed = true;
	}

	if( changed ) {
		addChange(DagCallback, nullptr);
	}
}

std::string Material::getNameInternal() const {
	return MFnDependencyNode(mayaObject_).name().asChar();
}

void Material::OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) {
	// ignore messages that don't set values
	if( !((msg & MNodeMessage::kAttributeSet || msg & MNodeMessage::kOtherPlugSet) && (msg & MNodeMessage::kIncomingDirection)) ) {
		return;
	}

	if( strcmp("ss", plug.partialName().asChar())==0 ) {
		if( !updateShaderObject() ) {
			MTLog::instance()->log("ADagMaterial::updateShaderObject failed.\n");
		}

		addChange(DagCallback::kMaterialSurfaceShaderChanged, nullptr); // will resend the entire material
	}
}

void Material::OnPlugDirtied( MObject& node, MPlug& plug ) {
}
