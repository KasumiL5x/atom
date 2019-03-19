#if OPENGL
	#define SV_POSITION POSITION
	#define VS_SHADERMODEL vs_3_0
	#define PS_SHADERMODEL ps_3_0
#else
	#define VS_SHADERMODEL vs_5_0
	#define PS_SHADERMODEL ps_5_0
#endif

#include "Lighting.fx"

matrix World;
matrix Xform;
float3 CameraPosition;

// light properties
float3 LightPosition;
float3 LightDirection;
float3 LightColor;
float LightIntensity;
float3 LightAmbientColor;
float LightRange;
float LightCosInner;
float LightCosOuter;
float LightShadowBias;

// surface properties
float SpecularPower;
float3 SurfaceColor;

// textures
texture DiffuseTexture;
sampler2D DiffuseTextureSampler = sampler_state {
	Texture = (DiffuseTexture);
	MinFilter = Linear;
	MagFilter = Linear;
	AddressU = Wrap;
	AddressV = Wrap;
};
bool UseDiffuseTexture;
texture NormalTexture;
sampler2D NormalTextureSampler = sampler_state {
	Texture = (NormalTexture);
	MinFilter = Linear;
	MagFilter = Linear;
	AddressU = Wrap;
	AddressV = Wrap;
};
bool UseNormalTexture;
texture2D DepthTexture;
sampler DepthTextureSampler = sampler_state {
	Texture = (DepthTexture);
	Filter = Point;
};
bool CastShadows = false;
matrix LightViewProj;

struct VertexShaderInput {
	float3 Position : SV_POSITION;
	float3 Normal : NORMAL0;
	float4 Tangent : TANGENT0;
	float2 Texcoord : TEXCOORD0;
};

struct VertexShaderOutput {
	float4 HPosition : SV_POSITION;
	float3 Position : TEXCOORD5;
	float3 Normal : NORMAL0;
	float2 Texcoord : TEXCOORD0;
	float3x3 TBN : TEXCOORD1;
};

VertexShaderOutput MainVS(in VertexShaderInput input) {
	VertexShaderOutput output = (VertexShaderOutput)0;

	output.HPosition = mul(float4(input.Position.xyz, 1.0), Xform);
	output.Position = mul(float4(input.Position.xyz, 1.0), World).xyz;
	output.Normal = mul(float4(input.Normal.xyz, 0.0), World).xyz;
	output.Texcoord = input.Texcoord;

	float3 T = normalize(mul(float4(input.Tangent.xyz, 0.0), World).xyz);
	float3 N = normalize(output.Normal);
	float3 BT = cross(N, T) * input.Tangent.w;
	float3 B = normalize(mul(float4(BT, 0.0), World).xyz);
	output.TBN = float3x3(T, B, N);

	return output;
}

float3 getNormal( float3 normal, float2 texcoord, float3x3 tbn ) {
	float3 N = normalize(normal);
	if( UseNormalTexture ) {
		N = tex2D(NormalTextureSampler, texcoord).rgb;
		N = normalize(N * 2.0 - 1.0);
		N = normalize(mul(N, tbn));
	}
	return N;
}

float3 getAlbedo( float2 texcoord ) {
	float3 objectColor = SurfaceColor;
	if( UseDiffuseTexture ) {
		objectColor *= tex2D(DiffuseTextureSampler, texcoord).rgb;
	}
	return objectColor;
}

float getShadow( float3 wpos ) {
	if( CastShadows == false ) {
		return 1.0;
	}

	// WORKING #2
	//float4 lightScreenPos = mul(float4(wpos, 1.0), LightViewProj);
	//lightScreenPos /= lightScreenPos.w;
	//float2 luv = 0.5f * (float2(lightScreenPos.x, -lightScreenPos.y) + 1.0);
	//float depth = DepthTexture.Sample(DepthTextureSampler, luv).r;
	//float dist = max(0.01, length(LightPosition - wpos)) / LightRange;
	//float bias = 0.01f;
	//return (depth * exp(-(LightRange * 0.5) * (dist - bias)));

	// WORKING #1 W/ PCF
	//float4 lightScreenPos = mul(float4(wpos, 1.0), LightViewProj);
	//lightScreenPos /= lightScreenPos.w;
	//float2 luv = 0.5f * (float2(lightScreenPos.x, -lightScreenPos.y) + 1.0);
	//float shadow = 0.0f;
	//for( int y = -1; y <= 1; ++y ) {
	//	for( int x = -1; x <= 1; ++x ) {
	//		float2 offset = float2(x, y) * (1.0 / 512.0);
	//		shadow += DepthTexture.Sample(DepthTextureSampler, luv + offset).r < (lightScreenPos.z - LightShadowBias) ? 0.0 : 1.0;
	//	}
	//}
	//shadow /= 9.0;
	//return 1.0 - shadow;

	// WORKING #1
	//// wpos in light space
	//float4 lightScreenPos = mul(float4(wpos, 1.0), LightViewProj);
	//lightScreenPos /= lightScreenPos.w;
	//// projected texcoords
	//float2 luv = float2(lightScreenPos.x, -lightScreenPos.y) * 0.5 + 0.5;
	//// get depth from texture
	//float depth = DepthTexture.Sample(DepthTextureSampler, luv).r;
	//return depth < (lightScreenPos.z - LightShadowBias) ? 0.0 : 1.0;

	// WORKING #1 PCF
	float4 lightScreenPos = mul(float4(wpos, 1.0), LightViewProj);
	lightScreenPos /= lightScreenPos.w;
	float2 luv = float2(lightScreenPos.x, -lightScreenPos.y) * 0.5 + 0.5;
	float shadow = 0.0f;
	for( float y = -1.0; y <= 1.0; y += 1.0 ) {
		for( float x = -1.0; x <= 1.0; x += 1.0 ) {
			float2 offset = float2(x, y) * (1.0 / 512.0);
			shadow += DepthTexture.Sample(DepthTextureSampler, luv + offset).r < (lightScreenPos.z - LightShadowBias) ? 0.0 : 1.0;
		}
	}
	shadow /= 9.0;
	return shadow;


	//
	// BELOW IS EXPERIMENTATION
	//
	//if( CastShadows == false ) {
	//	return 1.0f;
	//}
	////float3 screenPos = lightSpaceWorldPos.xyz/ lightSpaceWorldPos.w;
	//float3 screenPos = float3(lightSpaceWorldPos.x, -lightSpaceWorldPos.y, lightSpaceWorldPos.z) / lightSpaceWorldPos.w;
	//screenPos.xy = screenPos.xy * 0.5 + 0.5;
	//if( screenPos.z > 1.0 ) {
	//	return 1.0;
	//}
	//// todo: compute bias
	//float bias = 0.000001;
	//// single sample
	//float depthSample = DepthTexture.Sample(DepthTextureSampler, screenPos.xy).x;
	//return (depthSample < (screenPos.z - bias) ? 0.0 : 1.0);
}

struct PixelShaderOutput {
	float4 Color;
	float4 Bloom;
};

PixelShaderOutput MainPSLambert( VertexShaderOutput input ) : SV_TARGET {
	PixelShaderOutput output = (PixelShaderOutput)0;

	// light vector and distance to light
	float3 L = LightPosition - input.Position;
	float distToLight = length(L);
	L = normalize(L);

	// spotlight effect
	float cosDir = dot(L, -LightDirection);
	float spotEffect = smoothstep(LightCosOuter, LightCosInner, cosDir);
	float heightAttenuation = smoothstep(LightRange, 0.0, distToLight);

	float3 N = getNormal(input.Normal, input.Texcoord, input.TBN);
	float3 albedo = getAlbedo(input.Texcoord);

	float3 lighting = lambert(L, N, LightColor, LightIntensity);
	float visibility = getShadow(input.Position);
	output.Color = float4(LightAmbientColor + lighting * albedo * spotEffect * heightAttenuation * visibility, 1.0);

	float4 bloom = float4(0.0f, 0.0f, 0.0f, 1.0f);
	float brightness = dot(output.Color.rgb, float3(0.2126, 0.7152, 0.0722));
	if( brightness > 1.0 ) {
		bloom = output.Color;
	}
	output.Bloom = bloom;
	return output;
}

PixelShaderOutput MainPSPhong( VertexShaderOutput input ) : SV_TARGET {
	PixelShaderOutput output = (PixelShaderOutput)0;

	// light vector and distance to light
	float3 L = LightPosition - input.Position;
	float distToLight = length(L);
	L = normalize(L);

	// spotlight effect
	float cosDir = dot(L, -LightDirection);
	float spotEffect = smoothstep(LightCosOuter, LightCosInner, cosDir);
	float heightAttenuation = smoothstep(LightRange, 0.0, distToLight);

	float3 N = getNormal(input.Normal, input.Texcoord, input.TBN);
	float3 albedo = getAlbedo(input.Texcoord);

	float3 lighting = phong(L, N, CameraPosition, input.Position, LightColor, float3(1.0, 1.0, 1.0), LightIntensity, SpecularPower) * spotEffect * heightAttenuation;
	float visibility = getShadow(input.Position);
	output.Color = float4(LightAmbientColor + lighting * albedo * spotEffect * heightAttenuation * visibility, 1.0);

	float4 bloom = float4(0.0f, 0.0f, 0.0f, 1.0f);
	float brightness = dot(output.Color.rgb, float3(0.2126, 0.7152, 0.0722));
	if( brightness > 1.0 ) {
		bloom = output.Color;
	}
	output.Bloom = bloom;
	return output;
}

PixelShaderOutput MainPSBlinn( VertexShaderOutput input ) : SV_TARGET {
	PixelShaderOutput output = (PixelShaderOutput)0;

	// light vector and distance to light
	float3 L = LightPosition - input.Position;
	float distToLight = length(L);
	L = normalize(L);

	// spotlight effect
	float cosDir = dot(L, -LightDirection);
	float spotEffect = smoothstep(LightCosOuter, LightCosInner, cosDir);
	float heightAttenuation = smoothstep(LightRange, 0.0, distToLight);

	float3 N = getNormal(input.Normal, input.Texcoord, input.TBN);
	float3 albedo = getAlbedo(input.Texcoord);

	float3 lighting = blinn(L, N, CameraPosition, input.Position, LightColor, float3(1.0, 1.0, 1.0), LightIntensity, SpecularPower) * spotEffect * heightAttenuation;
	float visibility = getShadow(input.Position);
	output.Color = float4(LightAmbientColor + lighting * albedo * spotEffect * heightAttenuation * visibility, 1.0);

	float4 bloom = float4(0.0f, 0.0f, 0.0f, 1.0f);
	float brightness = dot(output.Color.rgb, float3(0.2126, 0.7152, 0.0722));
	if( brightness > 1.0 ) {
		bloom = output.Color;
	}
	output.Bloom = bloom;
	return output;
}

PixelShaderOutput MainPSWardIso( VertexShaderOutput input ) : SV_TARGET {
	PixelShaderOutput output = (PixelShaderOutput)0;

	// light vector and distance to light
	float3 L = LightPosition - input.Position;
	float distToLight = length(L);
	L = normalize(L);

	// spotlight effect
	float cosDir = dot(L, -LightDirection);
	float spotEffect = smoothstep(LightCosOuter, LightCosInner, cosDir);
	float heightAttenuation = smoothstep(LightRange, 0.0, distToLight);

	float3 N = getNormal(input.Normal, input.Texcoord, input.TBN);
	float3 albedo = getAlbedo(input.Texcoord);

	float3 lighting = ward_iso(L, N, CameraPosition, input.Position, LightColor, float3(1.0, 1.0, 1.0), LightIntensity, SpecularPower); // todo: roughness
	float visibility = getShadow(input.Position);
	output.Color = float4(LightAmbientColor + lighting * albedo * spotEffect * heightAttenuation * visibility, 1.0);

	float4 bloom = float4(0.0f, 0.0f, 0.0f, 1.0f);
	float brightness = dot(output.Color.rgb, float3(0.2126, 0.7152, 0.0722));
	if( brightness > 1.0 ) {
		bloom = output.Color;
	}
	output.Bloom = bloom;
	return output;
}

technique Lambert {
	pass P0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPSLambert();
	}
};

technique Phong {
	pass P0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPSPhong();
	}
};

technique Blinn {
	pass P0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPSBlinn();
	}
};

technique WardIso {
	pass P0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPSWardIso();
	}
};