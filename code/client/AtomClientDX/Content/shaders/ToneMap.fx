/**
 * Luminance texture (1x1).
 */
Texture2D LuminanceTexture;
SamplerState LuminanceSampler = sampler_state {
	Texture = (LuminanceTexture);
	Filter = Point;
	AddressU = Clamp;
	AddressV = Clamp;
};

float Exposure            = 1.0; /**< Exposure level where 1.0 is neutral. */
float MiddleGrey          = 0.6; /**< Middle gray level. min=0.0; max=1.0. */
float WhiteLevel          = 5.0; /**< White level. min=0.0; max=25.0. */
float LuminanceSaturation = 1.0; /**< Saturation value for luminance. min=0.0; max=4.0. */
float Bias                = 1.0; /**< Bias level. min=0.0; max=1.0. */
int   TonemapTechnique    = 2;   /**< 0=Reinhard Modified; 1=Logarithmic; 2=Drago Logarithmic; 3=Exponential. */

/**
 * Gets the average luminance from the LuminanceSampler.
 */
float getAverageLuminance() {
	return tex2D(LuminanceSampler, float2(0.5, 0.5)).r;
}

/**
 * Calculates the luminance value of a color.
 */
float calcLuminance( float3 color ) {
	return max(dot(color, float3(0.299, 0.587, 0.114)), 0.0001);
}

/**
 * Calculates exposed color from regular color using exposure and thresholding.
 */
float3 calcExposedColor( float3 color, float averageLum, float threshold ) {
	float exposure = 0.0;

	if( false ) { // auto exposure; make variable eventually
		// use geometric mean
		averageLum = max(averageLum, 0.001);
		float keyValue = 1.03 - (2.0 / (2.0 + log10(averageLum + 1.0)));
		float linearExposure = (keyValue / averageLum);
		exposure = log2(max(linearExposure, 0.0001));
	} else {
		// just use input exposure
		exposure = Exposure;
	}

	exposure -= threshold;
	return exp2(exposure) * color;
}

/**
 * Tonemaps using Reinhard's modified equation.
 */
float3 tonemapReinhardModified( float3 color, float averageLuminance ) {
	float pixelLuminance = calcLuminance(color);
	float lumScaled = (pixelLuminance * MiddleGrey) / averageLuminance;
	float lumCompressed = (lumScaled * (1.0 + (lumScaled / (WhiteLevel * WhiteLevel)))) / (1.0 + lumScaled);
	return lumCompressed * pow(color / lumScaled, LuminanceSaturation);
}

/**
 * Tonemaps using a logarithmic equation.
 */
float3 tonemapLogarithmic( float3 color, float averageLuminance ) {
	float pixelLuminance = calcLuminance(color);
	float lumScaled = (pixelLuminance * MiddleGrey) / averageLuminance;
	float mappedLuminance = log10(1.0 + lumScaled) / log10(1.0 + WhiteLevel);
	return mappedLuminance * pow(color / lumScaled, LuminanceSaturation);
}

/**
 * Tonemaps using Drago's logarithmic equation.
 */
float3 tonemapDragoLogarithmic( float3 color, float averageLuminance ) {
	float pixelLuminance = calcLuminance(color);
	float lumScaled = (pixelLuminance * MiddleGrey) / averageLuminance;

	float mapped = log10(1.0 + lumScaled);
	mapped /= log10(1.0 + WhiteLevel);
	mapped /= log10(2.0 + 8.0 * ((lumScaled / WhiteLevel) * log10(Bias) / log10(0.5)));
	return mapped * pow(color / lumScaled, LuminanceSaturation);
}

// exponential
/**
 * Tonemaps using an exponential equation.
 */
float3 tonemapExponential( float3 color, float averageLuminance ) {
	float pixelLuminance = calcLuminance(color);
	float lumScaled = (pixelLuminance * MiddleGrey) / averageLuminance;

	float mapped = 1.0 - exp(-lumScaled / WhiteLevel);
	return mapped * pow(color / lumScaled, LuminanceSaturation);
}

float3 tonemap( float3 hdrColor, float threshold ) {
	// average luminance value
	float averageLum = getAverageLuminance();

	// calculate exposed color
	float3 color = calcExposedColor(hdrColor, averageLum, threshold);
	
	// tonemap color
	[branch]
	if( 0 == TonemapTechnique ) {
		color = tonemapReinhardModified(color, averageLum);
	} else if( 1 == TonemapTechnique ) {
		color = tonemapLogarithmic(color, averageLum);
	} else if( 2 == TonemapTechnique ) {
		color = tonemapDragoLogarithmic(color, averageLum);
	} else if( 3 == TonemapTechnique ) {
		color = tonemapExponential(color, averageLum);
	}

	return color;
}