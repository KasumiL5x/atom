#include "MaterialWatcher.hpp"
#include "../../MTLog.hpp"
#include "../../server/Connection.hpp"
#include "../../AtomDag/AtomDag.hpp"
#include "../../AtomDag/Nodes/Node.hpp"
#include "../../AtomDag/Nodes/Material.hpp"
#include "../../proto/AtomMessage.pb.h"
#include "../../ProtobufHelper.hpp"

using namespace atom;
using namespace atom::dag;

MaterialWatcher::MaterialWatcher()
	: IWatchHandler() {

}

MaterialWatcher::~MaterialWatcher() {
}

bool MaterialWatcher::handle( std::shared_ptr<Node> node, std::shared_ptr<Connection> connection, std::shared_ptr<dag::AtomDag> adag ) {
	if( node->type() != DagType::Material ) {
		MTLog::instance()->log("MaterialWatcher::handle: ADagNode type was not kMaterial!\n");
		return false;
	}

	const auto material = std::static_pointer_cast<Material>(node);

	// send initial data
	sendMaterial(material, connection);

	// add watch handler
	std::shared_ptr<Connection> copyOfConnection = connection;
	node->addWatcher([this, copyOfConnection, material](DagCallback type, const std::shared_ptr<Node>& node, std::shared_ptr<Node> instigator) {
		if( nullptr == node ) {
			MTLog::instance()->log("MaterialWatcher::handle's callback delivered a null node.\n");
			return false;
		}

		// this will trigger the watcher callback to be removed inside of ADagNode on the next notifyWatchers call
		if( !copyOfConnection->isActive() ) {
			return false;
		}

		switch( type ) {
			case DagCallback::kNameChanged: {
				protohelper::sendNameChanged(node, copyOfConnection);
				break;
			}

			case DagCallback::kMaterialSurfaceShaderChanged: {
				sendMaterial(material, copyOfConnection);
				break;
			}

			case DagCallback::kMaterialChangedColor:
			case DagCallback::kMaterialChangedTransparency:
			case DagCallback::kMaterialChangedAmbientColor:
			case DagCallback::kMaterialChangedIncandescence:
			case DagCallback::kMaterialChangedDiffuseAmount:
			case DagCallback::kMaterialChangedTranslucence:
			case DagCallback::kMaterialChangedTranslucenceDepth:
			case DagCallback::kMaterialChangedTranslucenceFocus:
			case DagCallback::kMaterialChangedGlowIntensity:
			case DagCallback::kMaterialChangedSpecularColor:
			case DagCallback::kMaterialChangedReflectivity:
			case DagCallback::kMaterialChangedReflectedColor:
			case DagCallback::kMaterialChangedRoughness:
			case DagCallback::kMaterialChangedCosinePower:
			case DagCallback::kMaterialChangedHighlightSize:
			case DagCallback::kMaterialChangedWhiteness:
			case DagCallback::kMaterialChangedEccentricity:
			case DagCallback::kMaterialChangedSpecularRollOff:
			case DagCallback::kMaterialChangedAngle:
			case DagCallback::kMaterialChangedSpreadX:
			case DagCallback::kMaterialChangedSpreadY:
			case DagCallback::kMaterialChangedFresnelIndex:
			case DagCallback::kMaterialChangedBumpTexture: {
				sendMaterialChanged(type, material, copyOfConnection);
				break;
			}
			default: {
				MTLog::instance()->log("MaterialWatcher::handle's callback type was unhandled.\n");
				break;
			}
		}

		return true;
	}, copyOfConnection->getClientName());

	return true;
}

void MaterialWatcher::sendMaterial( const std::shared_ptr<Material>& material, const std::shared_ptr<Connection>& connection ) {
	if( material->shaderObject() == MObject::kNullObj ) {
		MTLog::instance()->log("Tried to send a material with no surfaceShader.\n");
		return;
	}

	auto atomMaterial = new atom::proto::materials::Material();
	atomMaterial->set_name(material->name());

	switch( material->shaderObject().apiType() ) {
		case MFn::kLambert: {
			atomMaterial->set_type(atom::proto::materials::kMaterialTypeLambert);
			auto atomLambert = new atom::proto::materials::Lambert();
			atomLambert->set_bumpmap(material->getBumpTexture());
			atomLambert->set_allocated_color(protohelper::textureParameterFrom(protohelper::colorFrom(material->getColor()), material->getColorTexture()));
			atomLambert->set_allocated_transparency(protohelper::textureParameterFrom(protohelper::colorFrom(material->getTransparency()), material->getTransparencyTexture()));
			atomLambert->set_allocated_ambientcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getAmbientColor()), material->getAmbientColorTexture()));
			atomLambert->set_allocated_incandescence(protohelper::textureParameterFrom(protohelper::colorFrom(material->getIncandescence()),material->getIncandescenceTexture()));
			atomLambert->set_allocated_diffuseamount(protohelper::textureParameterFrom(material->getDiffuseAmount(), material->getDiffuseAmountTexture()));
			atomLambert->set_allocated_translucence(protohelper::textureParameterFrom(material->getTranslucence(), material->getTranslucenceTexture()));
			atomLambert->set_allocated_translucencedepth(protohelper::textureParameterFrom(material->getTranslucenceDepth(), material->getTranslucenceDepthTexture()));
			atomLambert->set_allocated_translucencefocus(protohelper::textureParameterFrom(material->getTranslucenceFocus(), material->getTranslucenceFocusTexture()));
			atomLambert->set_allocated_glowintensity(protohelper::textureParameterFrom(material->getGlowIntensity(), material->getGlowIntensityTexture()));
			atomMaterial->set_allocated_lambert(atomLambert);
			break;
		}

		case MFn::kPhong: {
			atomMaterial->set_type(atom::proto::materials::kMaterialTypePhong);
			auto atomPhong = new atom::proto::materials::Phong();
			atomPhong->set_bumpmap(material->getBumpTexture());
			// lambert stuff
			atomPhong->set_allocated_color(protohelper::textureParameterFrom(protohelper::colorFrom(material->getColor()), material->getColorTexture()));
			atomPhong->set_allocated_transparency(protohelper::textureParameterFrom(protohelper::colorFrom(material->getTransparency()), material->getTransparencyTexture()));
			atomPhong->set_allocated_ambientcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getAmbientColor()), material->getAmbientColorTexture()));
			atomPhong->set_allocated_incandescence(protohelper::textureParameterFrom(protohelper::colorFrom(material->getIncandescence()),material->getIncandescenceTexture()));
			atomPhong->set_allocated_diffuseamount(protohelper::textureParameterFrom(material->getDiffuseAmount(), material->getDiffuseAmountTexture()));
			atomPhong->set_allocated_translucence(protohelper::textureParameterFrom(material->getTranslucence(), material->getTranslucenceTexture()));
			atomPhong->set_allocated_translucencedepth(protohelper::textureParameterFrom(material->getTranslucenceDepth(), material->getTranslucenceDepthTexture()));
			atomPhong->set_allocated_translucencefocus(protohelper::textureParameterFrom(material->getTranslucenceFocus(), material->getTranslucenceFocusTexture()));
			atomPhong->set_allocated_glowintensity(protohelper::textureParameterFrom(material->getGlowIntensity(), material->getGlowIntensityTexture()));
			// phong stuff
			atomPhong->set_allocated_cosinepower(protohelper::textureParameterFrom(material->getCosinePower(), material->getCosinePowerTexture()));
			atomPhong->set_allocated_specularcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getSpecularColor()), material->getSpecularColorTexture()));
			atomPhong->set_allocated_reflectivity(protohelper::textureParameterFrom(material->getReflectivity(), material->getReflectivityTexture()));
			atomPhong->set_allocated_reflectedcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getReflectedColor()), material->getReflectedColorTexture()));
			atomMaterial->set_allocated_phong(atomPhong);
			break;
		}
											
		case MFn::kPhongExplorer: {
			atomMaterial->set_type(atom::proto::materials::kMaterialTypePhongE);
			auto atomPhongE = new atom::proto::materials::PhongE();
			atomPhongE->set_bumpmap(material->getBumpTexture());
			// lambert stuff
			atomPhongE->set_allocated_color(protohelper::textureParameterFrom(protohelper::colorFrom(material->getColor()), material->getColorTexture()));
			atomPhongE->set_allocated_transparency(protohelper::textureParameterFrom(protohelper::colorFrom(material->getTransparency()), material->getTransparencyTexture()));
			atomPhongE->set_allocated_ambientcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getAmbientColor()), material->getAmbientColorTexture()));
			atomPhongE->set_allocated_incandescence(protohelper::textureParameterFrom(protohelper::colorFrom(material->getIncandescence()),material->getIncandescenceTexture()));
			atomPhongE->set_allocated_diffuseamount(protohelper::textureParameterFrom(material->getDiffuseAmount(), material->getDiffuseAmountTexture()));
			atomPhongE->set_allocated_translucence(protohelper::textureParameterFrom(material->getTranslucence(), material->getTranslucenceTexture()));
			atomPhongE->set_allocated_translucencedepth(protohelper::textureParameterFrom(material->getTranslucenceDepth(), material->getTranslucenceDepthTexture()));
			atomPhongE->set_allocated_translucencefocus(protohelper::textureParameterFrom(material->getTranslucenceFocus(), material->getTranslucenceFocusTexture()));
			atomPhongE->set_allocated_glowintensity(protohelper::textureParameterFrom(material->getGlowIntensity(), material->getGlowIntensityTexture()));
			// phonge stuff
			atomPhongE->set_allocated_roughness(protohelper::textureParameterFrom(material->getRoughness(), material->getRoughnessTexture()));
			atomPhongE->set_allocated_highlightsize(protohelper::textureParameterFrom(material->getHighlightSize(), material->getHighlightSizeTexture()));
			atomPhongE->set_allocated_whiteness(protohelper::textureParameterFrom(protohelper::colorFrom(material->getWhiteness()), material->getWhitenessTexture()));
			atomPhongE->set_allocated_specularcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getSpecularColor()), material->getSpecularColorTexture()));
			atomPhongE->set_allocated_reflectivity(protohelper::textureParameterFrom(material->getReflectivity(), material->getReflectivityTexture()));
			atomPhongE->set_allocated_reflectedcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getReflectedColor()), material->getReflectedColorTexture()));
			atomMaterial->set_allocated_phonge(atomPhongE);
			break;
		}

		case MFn::kBlinn: {
			atomMaterial->set_type(atom::proto::materials::kMaterialTypeBlinn);
			auto atomBlinn = new atom::proto::materials::Blinn();
			atomBlinn->set_bumpmap(material->getBumpTexture());
			// lambert stuff
			atomBlinn->set_allocated_color(protohelper::textureParameterFrom(protohelper::colorFrom(material->getColor()), material->getColorTexture()));
			atomBlinn->set_allocated_transparency(protohelper::textureParameterFrom(protohelper::colorFrom(material->getTransparency()), material->getTransparencyTexture()));
			atomBlinn->set_allocated_ambientcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getAmbientColor()), material->getAmbientColorTexture()));
			atomBlinn->set_allocated_incandescence(protohelper::textureParameterFrom(protohelper::colorFrom(material->getIncandescence()),material->getIncandescenceTexture()));
			atomBlinn->set_allocated_diffuseamount(protohelper::textureParameterFrom(material->getDiffuseAmount(), material->getDiffuseAmountTexture()));
			atomBlinn->set_allocated_translucence(protohelper::textureParameterFrom(material->getTranslucence(), material->getTranslucenceTexture()));
			atomBlinn->set_allocated_translucencedepth(protohelper::textureParameterFrom(material->getTranslucenceDepth(), material->getTranslucenceDepthTexture()));
			atomBlinn->set_allocated_translucencefocus(protohelper::textureParameterFrom(material->getTranslucenceFocus(), material->getTranslucenceFocusTexture()));
			atomBlinn->set_allocated_glowintensity(protohelper::textureParameterFrom(material->getGlowIntensity(), material->getGlowIntensityTexture()));
			// blinn stuff
			atomBlinn->set_allocated_eccentricity(protohelper::textureParameterFrom(material->getEccentricity(), material->getEccentricityTexture()));
			atomBlinn->set_allocated_specularrolloff(protohelper::textureParameterFrom(material->getSpecularRollOff(), material->getSpecularRollOffTexture()));
			atomBlinn->set_allocated_specularcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getSpecularColor()), material->getSpecularColorTexture()));
			atomBlinn->set_allocated_reflectivity(protohelper::textureParameterFrom(material->getReflectivity(), material->getReflectivityTexture()));
			atomBlinn->set_allocated_reflectedcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getReflectedColor()), material->getReflectedColorTexture()));
			atomMaterial->set_allocated_blinn(atomBlinn);
			break;
		}

		case MFn::kAnisotropy: {
			atomMaterial->set_type(atom::proto::materials::kMaterialTypeAnisotropic);
			auto atomAniso = new atom::proto::materials::Anisotropic();
			atomAniso->set_bumpmap(material->getBumpTexture());
			// lambert stuff
			atomAniso->set_allocated_color(protohelper::textureParameterFrom(protohelper::colorFrom(material->getColor()), material->getColorTexture()));
			atomAniso->set_allocated_transparency(protohelper::textureParameterFrom(protohelper::colorFrom(material->getTransparency()), material->getTransparencyTexture()));
			atomAniso->set_allocated_ambientcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getAmbientColor()), material->getAmbientColorTexture()));
			atomAniso->set_allocated_incandescence(protohelper::textureParameterFrom(protohelper::colorFrom(material->getIncandescence()),material->getIncandescenceTexture()));
			atomAniso->set_allocated_diffuseamount(protohelper::textureParameterFrom(material->getDiffuseAmount(), material->getDiffuseAmountTexture()));
			atomAniso->set_allocated_translucence(protohelper::textureParameterFrom(material->getTranslucence(), material->getTranslucenceTexture()));
			atomAniso->set_allocated_translucencedepth(protohelper::textureParameterFrom(material->getTranslucenceDepth(), material->getTranslucenceDepthTexture()));
			atomAniso->set_allocated_translucencefocus(protohelper::textureParameterFrom(material->getTranslucenceFocus(), material->getTranslucenceFocusTexture()));
			atomAniso->set_allocated_glowintensity(protohelper::textureParameterFrom(material->getGlowIntensity(), material->getGlowIntensityTexture()));
			// aniso stuff
			atomAniso->set_allocated_angle(protohelper::textureParameterFrom(material->getAngle(), material->getAngleTexture()));
			atomAniso->set_allocated_spreadx(protohelper::textureParameterFrom(material->getSpreadX(), material->getSpreadXTexture()));
			atomAniso->set_allocated_spready(protohelper::textureParameterFrom(material->getSpreadY(), material->getSpreadYTexture()));
			atomAniso->set_allocated_roughness(protohelper::textureParameterFrom(material->getRoughness(), material->getRoughnessTexture()));
			atomAniso->set_allocated_fresnelindex(protohelper::textureParameterFrom(material->getFresnelIndex(), material->getFresnelIndexTexture()));
			atomAniso->set_allocated_specularcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getSpecularColor()), material->getSpecularColorTexture()));
			atomAniso->set_allocated_reflectivity(protohelper::textureParameterFrom(material->getReflectivity(), material->getReflectivityTexture()));
			atomAniso->set_allocated_reflectedcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getReflectedColor()), material->getReflectedColorTexture()));
			atomMaterial->set_allocated_anisotropic(atomAniso);
			break;
		}
	}

	atom::proto::AtomMessage msg;
	msg.set_allocated_material(atomMaterial);
	protohelper::sendTo(msg, connection);
}

void MaterialWatcher::sendMaterialChanged( DagCallback type, const std::shared_ptr<Material>& material, const std::shared_ptr<Connection>& connection ) {
	auto atomMaterialChanged = new atom::proto::materials::MaterialChanged();
	atomMaterialChanged->set_materialname(material->name());

	switch( type ) {
		case DagCallback::kMaterialChangedColor: {
			atomMaterialChanged->set_allocated_color(protohelper::textureParameterFrom(protohelper::colorFrom(material->getColor()), material->getColorTexture()));
			break;
		}
		case DagCallback::kMaterialChangedTransparency: {
			atomMaterialChanged->set_allocated_transparency(protohelper::textureParameterFrom(protohelper::colorFrom(material->getTransparency()), material->getTransparencyTexture()));
			break;
		}
		case DagCallback::kMaterialChangedAmbientColor: {
			atomMaterialChanged->set_allocated_ambientcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getAmbientColor()), material->getAmbientColorTexture()));
			break;
		}
		case DagCallback::kMaterialChangedIncandescence: {
			atomMaterialChanged->set_allocated_incandescence(protohelper::textureParameterFrom(protohelper::colorFrom(material->getIncandescence()),material->getIncandescenceTexture()));
			break;
		}
		case DagCallback::kMaterialChangedDiffuseAmount: {
			atomMaterialChanged->set_allocated_diffuseamount(protohelper::textureParameterFrom(material->getDiffuseAmount(), material->getDiffuseAmountTexture()));
			break;
		}
		case DagCallback::kMaterialChangedTranslucence: {
			atomMaterialChanged->set_allocated_translucence(protohelper::textureParameterFrom(material->getTranslucence(), material->getTranslucenceTexture()));
			break;
		}
		case DagCallback::kMaterialChangedTranslucenceDepth: {
			atomMaterialChanged->set_allocated_translucencedepth(protohelper::textureParameterFrom(material->getTranslucenceDepth(), material->getTranslucenceDepthTexture()));
			break;
		}
		case DagCallback::kMaterialChangedTranslucenceFocus: {
			atomMaterialChanged->set_allocated_translucencefocus(protohelper::textureParameterFrom(material->getTranslucenceFocus(), material->getTranslucenceFocusTexture()));
			break;
		}
		case DagCallback::kMaterialChangedGlowIntensity: {
			atomMaterialChanged->set_allocated_glowintensity(protohelper::textureParameterFrom(material->getGlowIntensity(), material->getGlowIntensityTexture()));
			break;
		}
		case DagCallback::kMaterialChangedSpecularColor: {
			atomMaterialChanged->set_allocated_specularcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getSpecularColor()), material->getSpecularColorTexture()));
			break;
		}
		case DagCallback::kMaterialChangedReflectivity: {
			atomMaterialChanged->set_allocated_reflectivity(protohelper::textureParameterFrom(material->getReflectivity(), material->getReflectivityTexture()));
			break;
		}
		case DagCallback::kMaterialChangedReflectedColor: {
			atomMaterialChanged->set_allocated_reflectedcolor(protohelper::textureParameterFrom(protohelper::colorFrom(material->getReflectedColor()), material->getReflectedColorTexture()));
			break;
		}
		case DagCallback::kMaterialChangedRoughness: {
			atomMaterialChanged->set_allocated_roughness(protohelper::textureParameterFrom(material->getRoughness(), material->getRoughnessTexture()));
			break;
		}
		case DagCallback::kMaterialChangedCosinePower: {
			atomMaterialChanged->set_allocated_cosinepower(protohelper::textureParameterFrom(material->getCosinePower(), material->getCosinePowerTexture()));
			break;
		}
		case DagCallback::kMaterialChangedHighlightSize: {
			atomMaterialChanged->set_allocated_highlightsize(protohelper::textureParameterFrom(material->getHighlightSize(), material->getHighlightSizeTexture()));
			break;
		}
		case DagCallback::kMaterialChangedWhiteness: {
			atomMaterialChanged->set_allocated_whiteness(protohelper::textureParameterFrom(protohelper::colorFrom(material->getWhiteness()), material->getWhitenessTexture()));
			break;
		}
		case DagCallback::kMaterialChangedEccentricity: {
			atomMaterialChanged->set_allocated_eccentricity(protohelper::textureParameterFrom(material->getEccentricity(), material->getEccentricityTexture()));
			break;
		}
		case DagCallback::kMaterialChangedSpecularRollOff: {
			atomMaterialChanged->set_allocated_specularrolloff(protohelper::textureParameterFrom(material->getSpecularRollOff(), material->getSpecularRollOffTexture()));
			break;
		}
		case DagCallback::kMaterialChangedAngle: {
			atomMaterialChanged->set_allocated_angle(protohelper::textureParameterFrom(material->getAngle(), material->getAngleTexture()));
			break;
		}
		case DagCallback::kMaterialChangedSpreadX: {
			atomMaterialChanged->set_allocated_spreadx(protohelper::textureParameterFrom(material->getSpreadX(), material->getSpreadXTexture()));
			break;
		}
		case DagCallback::kMaterialChangedSpreadY: {
			atomMaterialChanged->set_allocated_spready(protohelper::textureParameterFrom(material->getSpreadY(), material->getSpreadYTexture()));
			break;
		}
		case DagCallback::kMaterialChangedFresnelIndex: {
			atomMaterialChanged->set_allocated_fresnelindex(protohelper::textureParameterFrom(material->getFresnelIndex(), material->getFresnelIndexTexture()));
			break;
		}
		case DagCallback::kMaterialChangedBumpTexture: {
			atomMaterialChanged->set_bumpmap(material->getBumpTexture());
			break;
		}
	}

	atom::proto::AtomMessage msg;
	msg.set_allocated_materialchanged(atomMaterialChanged);
	protohelper::sendTo(msg, connection);
}
