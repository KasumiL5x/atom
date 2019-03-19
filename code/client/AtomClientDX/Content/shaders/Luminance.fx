#if OPENGL
	#define SV_POSITION POSITION
	#define VS_SHADERMODEL vs_3_0
	#define PS_SHADERMODEL ps_3_0
#else
	#define VS_SHADERMODEL vs_4_0
	#define PS_SHADERMODEL ps_4_0
#endif

texture InputTexture;
sampler2D InputSampler = sampler_state {
	Texture = (InputTexture);
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

float calcLuminance( float3 color ) {
  return max(dot(color, float3(0.299, 0.587, 0.114)), 0.0001);
}

float4 MainPS( VertexShaderOutput input ) : SV_TARGET {
	// input sample
	float3 color = tex2D(InputSampler, input.Texcoord).rgb;
	// calc average weighted luminance
	float luminance = calcLuminance(color);
	// log it
	//float logLuminance = log(1e-5 + luminance);
	return float4(luminance, 1.0, 1.0, 1.0);
}

technique Luminance {
	pass P0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPS();
	}
}