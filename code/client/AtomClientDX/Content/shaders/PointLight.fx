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
float3 LightColor;
float LightIntensity;
float3 LightAmbientColor;
float LightRange;

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

struct VertexShaderInput {
	float3 Position : SV_POSITION;
	float3 Normal : NORMAL0;
	float4 Tangent : TANGENT0;
	float2 Texcoord : TEXCOORD0;
};

struct VertexShaderOutput {
	float4 HPosition : SV_POSITION;
	float3 Position : POSITIONT;
	float3 Normal : NORMAL;
	float2 Texcoord : TEXCOORD;
	float3x3 TBN : TEXCOORD1;
};

float attenuate( float3 P, float3 L, float range ) {
	float dist = length(P - L);
	return smoothstep(range, 0.0, dist);
}

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

struct PixelShaderOutput {
	float4 Color;
	float4 Bloom;
};

PixelShaderOutput MainPSLambert( VertexShaderOutput input ) : SV_TARGET {
	PixelShaderOutput output = (PixelShaderOutput)0;

	float3 L = normalize(LightPosition - input.Position);
	float3 N = getNormal(input.Normal, input.Texcoord, input.TBN);
	float3 albedo = getAlbedo(input.Texcoord);

	float3 lighting = lambert(L, N, LightColor, LightIntensity);
	float attenuation = attenuate(input.Position, LightPosition, LightRange);
	output.Color = float4(LightAmbientColor + lighting * albedo * attenuation, 1.0);

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

	float3 L = normalize(LightPosition - input.Position);
	float3 N = getNormal(input.Normal, input.Texcoord, input.TBN);
	float3 albedo = getAlbedo(input.Texcoord);

	float3 lighting = phong(L, N, CameraPosition, input.Position, LightColor, float3(1.0, 1.0, 1.0), LightIntensity, SpecularPower);
	float attenuation = attenuate(input.Position, LightPosition, LightRange);
	output.Color = float4(LightAmbientColor + lighting * albedo * attenuation, 1.0);

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

	float3 L = normalize(LightPosition - input.Position);
	float3 N = getNormal(input.Normal, input.Texcoord, input.TBN);
	float3 albedo = getAlbedo(input.Texcoord);

	float3 lighting = blinn(L, N, CameraPosition, input.Position, LightColor, float3(1.0, 1.0, 1.0), LightIntensity, SpecularPower);
	float attenuation = attenuate(input.Position, LightPosition, LightRange);
	output.Color = float4(LightAmbientColor + lighting * albedo * attenuation, 1.0);

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

	float3 L = normalize(LightPosition - input.Position);
	float3 N = getNormal(input.Normal, input.Texcoord, input.TBN);
	float3 albedo = getAlbedo(input.Texcoord);

	float3 lighting = ward_iso(L, N, CameraPosition, input.Position, LightColor, float3(1.0, 1.0, 1.0), LightIntensity, SpecularPower); // todo: roughness
	float attenuation = attenuate(input.Position, LightPosition, LightRange);
	output.Color = float4(LightAmbientColor + lighting * albedo * attenuation, 1.0);

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