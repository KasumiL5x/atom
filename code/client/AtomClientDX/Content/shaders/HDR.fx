#if OPENGL
	#define SV_POSITION POSITION
	#define VS_SHADERMODEL vs_3_0
	#define PS_SHADERMODEL ps_3_0
#else
	#define VS_SHADERMODEL vs_4_0
	#define PS_SHADERMODEL ps_4_0
#endif

#include "ToneMap.fx"

bool Bloom = true;
float BloomAmount = 1.0;

texture HdrTexture;
sampler2D HdrSampler = sampler_state {
	Texture = (HdrTexture);
	Filter = Point;
	AddressU = Clamp;
	AddressV = Clamp;
};

texture BloomTexture;
sampler2D BloomSampler = sampler_state {
	Texture = (BloomTexture);
	Filter = Linear;
	AddressU = Clamp;
	AddressV = Clamp;
};

struct VertexShaderInput {
	float4 Position  : POSITION;
	float4 Texcoord : TEXCOORD0;
};

struct VertexShaderOutput {
	float4 HPosition : SV_POSITION;
	float2 Texcoord : TEXCOORD0;
};

VertexShaderOutput MainVS(in VertexShaderInput input) {
	VertexShaderOutput output = (VertexShaderOutput)0;

	output.HPosition = float4(input.Position.xyz, 1.0);
	output.Texcoord = input.Texcoord.xy;

	return output;
}

float4 MainPS( VertexShaderOutput input ) : SV_TARGET {
	// hdr color value
	float3 color = tex2D(HdrSampler, input.Texcoord).rgb;
	// sample and add bloom
	float3 bloom = float3(0.0, 0.0, 0.0);
	if( Bloom ) {
		bloom = tex2D(BloomSampler, input.Texcoord).rgb * BloomAmount;
	}
	color += bloom;
	// tonemapped value
	color = tonemap(color, 0.0f);

	return float4(color, 1.0);
}

technique Hdr {
	pass P0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPS();
	}
}