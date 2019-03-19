float3 CameraDirection;

TextureCube CubemapTexture;
SamplerState CubemapSampler = sampler_state {
	Texture = <CubemapTexture>;
	Filter = Linear;
	AddressU = Clamp;
	AddressV = Clamp;
	AddressW = Clamp;
};

float4 reflectRefract( float3 L, float3 N, float3 V ) {
	float FresnelBias = 0.05;
	float FresnelScale = 0.42;
	float FresnelPow = 0.75;
	float3 EtaRatio = float3(0.66, 0.5, 0.57);

	float reflectionFactor = FresnelBias + FresnelScale * pow(1.0 + dot(V, N), FresnelPow);
	float3 R = reflect(V, N);
	float3 Red = refract(V, N, EtaRatio.r);
	float3 Green = refract(V, N, EtaRatio.g);
	float3 Blue = refract(V, N, EtaRatio.b);

	float4 reflectedColor = CubemapTexture.Sample(CubemapSampler, R);
	float4 refractedColor;
	refractedColor.r = CubemapTexture.Sample(CubemapSampler, Red).r;
	refractedColor.g = CubemapTexture.Sample(CubemapSampler, Green).g;
	refractedColor.b = CubemapTexture.Sample(CubemapSampler, Blue).b;
	refractedColor.a = reflectionFactor;

	float4 final = lerp(refractedColor, reflectedColor, reflectionFactor);
	return final;
}