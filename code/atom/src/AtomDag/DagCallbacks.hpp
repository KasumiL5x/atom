#ifndef __atom_dag_DagCallbacks__
#define __atom_dag_DagCallbacks__

#include <functional>
#include <set>
#include <string>
#include <maya/MMatrix.h>

namespace atom { namespace dag {

class Node;

enum class DagCallback {
	kInvalid,

	// generic
	kNameChanged, /**< A node has changed its name. */
	kTranslated,  /**< A node has been translated. */
	kRotated,     /**< A node has been rotated. */
	kScaled,      /**< A node has been scaled. */

	// meshes
	kMeshPointsChanged,
	kMeshGeometryChanged,
	kMeshMaterialChanged,

	// lights
	kColorChanged, /**< Light color changed. */
	kIntensityChanged, /**< Light intensity changed. */

	// cameras
	kCameraChanged, /**< Camera's view or projection changed. */

	// lights
	kLightChangedType,
	kLightChangedPosition,
	kLightChangedDirection,
	kLightChangedRange,
	kLightChangedColor,
	kLightChangedIntensity,
	kLightChangedConeAngle,
	kLightChangedPenumbraAngle,
	kLightChangedDropoff,
	kLightChangedShadows,
	kLightChangedShadowResolution,
	kLightChangedShadowBias,
	kLightChangedShadowColor,

	// materials
	kMaterialSurfaceShaderChanged,
	kMaterialChangedColor,
	kMaterialChangedTransparency,
	kMaterialChangedAmbientColor,
	kMaterialChangedIncandescence,
	kMaterialChangedDiffuseAmount,
	kMaterialChangedTranslucence,
	kMaterialChangedTranslucenceDepth,
	kMaterialChangedTranslucenceFocus,
	kMaterialChangedGlowIntensity,
	kMaterialChangedSpecularColor,
	kMaterialChangedReflectivity,
	kMaterialChangedReflectedColor,
	kMaterialChangedRoughness,
	kMaterialChangedCosinePower,
	kMaterialChangedHighlightSize,
	kMaterialChangedWhiteness,
	kMaterialChangedEccentricity,
	kMaterialChangedSpecularRollOff,
	kMaterialChangedAngle,
	kMaterialChangedSpreadX,
	kMaterialChangedSpreadY,
	kMaterialChangedFresnelIndex,
	kMaterialChangedBumpTexture,

	// ADagTexture
	kTextureChangedFile,
	kTextureChangedTranslateFrame,
	kTextureChangedRotateFrame,
	kTextureChangedMirrorU,
	kTextureChangedMirrorV,
	kTextureChangedWrapU,
	kTextureChangedWrapV,
	kTextureChangedRepeat,
	kTextureChangedOffset,
	kTextureChangedRotateUV,
	kTextureChangedNoise,

	// annotations
	kAnnotationChangedText,

	// curves
	kCurveChanged,

	// matrix changed
	kMatrixChanged,

	// visibility changed
	kVisibilityChanged
};

static std::string DagCallbackToString( DagCallback type ) {
#define DC_2_STR(x, y)case DagCallback::x:{return y;}
	switch( type ) {
		DC_2_STR(kInvalid, "kInvalid")
		DC_2_STR(kNameChanged, "kNameChanged")
		DC_2_STR(kTranslated, "kTranslated")
		DC_2_STR(kRotated, "kRotated")
		DC_2_STR(kScaled, "kScaled")
		DC_2_STR(kMeshPointsChanged, "kMeshPointsChanged")
		DC_2_STR(kMeshGeometryChanged, "kMeshGeometryChanged")
		DC_2_STR(kMeshMaterialChanged, "kMeshMaterialChanged")
		DC_2_STR(kColorChanged, "kColorChanged")
		DC_2_STR(kIntensityChanged, "kIntensityChanged")
		DC_2_STR(kCameraChanged, "kCameraChanged")
		DC_2_STR(kLightChangedType, "kLightChangedType")
		DC_2_STR(kLightChangedPosition, "kLightChangedPosition")
		DC_2_STR(kLightChangedDirection, "kLightChangedDirection")
		DC_2_STR(kLightChangedRange, "kLightChangedRange")
		DC_2_STR(kLightChangedColor, "kLightChangedColor")
		DC_2_STR(kLightChangedIntensity, "kLightChangedIntensity")
		DC_2_STR(kLightChangedConeAngle, "kLightChangedConeAngle")
		DC_2_STR(kLightChangedPenumbraAngle, "kLightChangedPenumbraAngle")
		DC_2_STR(kLightChangedDropoff, "kLightChangedDropoff")
		DC_2_STR(kLightChangedShadows, "kLightChangedShadows")
		DC_2_STR(kLightChangedShadowResolution, "kLightChangedShadowResolution")
		DC_2_STR(kLightChangedShadowBias, "kLightChangedShadowBias")
		DC_2_STR(kLightChangedShadowColor, "kLightChangedShadowColor")
		DC_2_STR(kMaterialSurfaceShaderChanged, "kMaterialSurfaceShaderChanged")
		DC_2_STR(kMaterialChangedColor, "kMaterialChangedColor")
		DC_2_STR(kMaterialChangedTransparency, "kMaterialChangedTransparency")
		DC_2_STR(kMaterialChangedAmbientColor, "kMaterialChangedAmbientColor")
		DC_2_STR(kMaterialChangedIncandescence, "kMaterialChangedIncandescence")
		DC_2_STR(kMaterialChangedDiffuseAmount, "kMaterialChangedDiffuseAmount")
		DC_2_STR(kMaterialChangedTranslucence, "kMaterialChangedTranslucence")
		DC_2_STR(kMaterialChangedTranslucenceDepth, "kMaterialChangedTranslucenceDepth")
		DC_2_STR(kMaterialChangedTranslucenceFocus, "kMaterialChangedTranslucenceFocus")
		DC_2_STR(kMaterialChangedGlowIntensity, "kMaterialChangedGlowIntensity")
		DC_2_STR(kMaterialChangedSpecularColor, "kMaterialChangedSpecularColor")
		DC_2_STR(kMaterialChangedReflectivity, "kMaterialChangedReflectivity")
		DC_2_STR(kMaterialChangedReflectedColor, "kMaterialChangedReflectedColor")
		DC_2_STR(kMaterialChangedRoughness, "kMaterialChangedRoughness")
		DC_2_STR(kMaterialChangedCosinePower, "kMaterialChangedCosinePower")
		DC_2_STR(kMaterialChangedHighlightSize, "kMaterialChangedHighlightSize")
		DC_2_STR(kMaterialChangedWhiteness, "kMaterialChangedWhiteness")
		DC_2_STR(kMaterialChangedEccentricity, "kMaterialChangedEccentricity")
		DC_2_STR(kMaterialChangedSpecularRollOff, "kMaterialChangedSpecularRollOff")
		DC_2_STR(kMaterialChangedAngle, "kMaterialChangedAngle")
		DC_2_STR(kMaterialChangedSpreadX, "kMaterialChangedSpreadX")
		DC_2_STR(kMaterialChangedSpreadY, "kMaterialChangedSpreadY")
		DC_2_STR(kMaterialChangedFresnelIndex, "kMaterialChangedFresnelIndex")
		DC_2_STR(kMaterialChangedBumpTexture, "kMaterialChangedBumpTexture")
		DC_2_STR(kTextureChangedFile, "kTextureChangedFile")
		DC_2_STR(kTextureChangedTranslateFrame, "kTextureChangedTranslateFrame")
		DC_2_STR(kTextureChangedRotateFrame, "kTextureChangedRotateFrame")
		DC_2_STR(kTextureChangedMirrorU, "kTextureChangedMirrorU")
		DC_2_STR(kTextureChangedMirrorV, "kTextureChangedMirrorV")
		DC_2_STR(kTextureChangedWrapU, "kTextureChangedWrapU")
		DC_2_STR(kTextureChangedWrapV, "kTextureChangedWrapV")
		DC_2_STR(kTextureChangedRepeat, "kTextureChangedRepeat")
		DC_2_STR(kTextureChangedOffset, "kTextureChangedOffset")
		DC_2_STR(kTextureChangedRotateUV, "kTextureChangedRotateUV")
		DC_2_STR(kTextureChangedNoise, "kTextureChangedNoise")
		DC_2_STR(kAnnotationChangedText, "kAnnotationChangedText")
		DC_2_STR(kCurveChanged, "kCurveChanged")
		DC_2_STR(kMatrixChanged, "kMatrixChanged")
		DC_2_STR(kVisibilityChanged, "kVisibilityChanged")
	}
#undef DC_2_STR
	return "";
}

typedef std::function<bool(DagCallback type, const std::shared_ptr<Node>& node, std::shared_ptr<Node> instigator )> OnNodeChanged;

}
}

#endif // !__atom_dag_DagCallbacks__
