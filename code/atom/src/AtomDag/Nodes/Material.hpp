#ifndef __atom_dag_Material__
#define __atom_dag_Material__

#include <string>
#include "Node.hpp"
#include <maya/MColor.h>

namespace atom { namespace dag {

class Material : public Node {
public:
	Material( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path );
	virtual ~Material();

	MObject shaderObject() const;
	MColor getColor() const; // lambert
	MColor getTransparency() const;
	MColor getAmbientColor() const;
	MColor getIncandescence() const;
	float getDiffuseAmount() const;
	float getTranslucence() const;
	float getTranslucenceDepth() const;
	float getTranslucenceFocus() const;
	float getGlowIntensity() const;
	MColor getSpecularColor() const; // multiple
	float getReflectivity() const;
	MColor getReflectedColor() const;
	float getRoughness() const;
	float getCosinePower() const; // phong
	float getHighlightSize() const; // phong e
	MColor getWhiteness() const;
	float getEccentricity() const; // blinn
	float getSpecularRollOff() const;
	float getAngle() const; // aniso
	float getSpreadX() const;
	float getSpreadY() const;
	float getFresnelIndex() const;
	std::string getColorTexture() const;
	std::string getTransparencyTexture() const;
	std::string getAmbientColorTexture() const;
	std::string getIncandescenceTexture() const;
	std::string getDiffuseAmountTexture() const;
	std::string getTranslucenceTexture() const;
	std::string getTranslucenceDepthTexture() const;
	std::string getTranslucenceFocusTexture() const;
	std::string getGlowIntensityTexture() const;
	std::string getSpecularColorTexture() const;
	std::string getReflectivityTexture() const;
	std::string getReflectedColorTexture() const;
	std::string getRoughnessTexture() const;
	std::string getCosinePowerTexture() const;
	std::string getHighlightSizeTexture() const;
	std::string getWhitenessTexture() const;
	std::string getEccentricityTexture() const;
	std::string getSpecularRollOffTexture() const;
	std::string getAngleTexture() const;
	std::string getSpreadXTexture() const;
	std::string getSpreadYTexture() const;
	std::string getFresnelIndexTexture() const;
	std::string getBumpTexture() const;

private:
	std::string getTextureFromPlug( const std::string& plugName ) const;
	MColor getColorFromPlug( const std::string& plugName ) const;
	float getSingleFromPlug( const std::string& plugName ) const;
	bool updateShaderObject();
	void addShaderCallbacks();
	void removeShaderCallbacks();
	void onPlugDirtied( MObject& node, MPlug& plug, void* clientData );

protected:
	virtual std::string getNameInternal() const override;
	virtual void OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) override;
	virtual void OnPlugDirtied( MObject& node, MPlug& plug ) override;

private:
	MObject shaderObject_;            /**< MObject of the connected surfaceShader.  Is MObject::kNullObject when nothing is connected. */
	MCallbackId shaderPlugDirtyCbId_;
};

}
}


#endif
