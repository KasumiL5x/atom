#if OPENGL
	#define SV_POSITION POSITION
	#define VS_SHADERMODEL vs_3_0
	#define PS_SHADERMODEL ps_3_0
#else
	#define VS_SHADERMODEL vs_4_0
	#define PS_SHADERMODEL ps_4_0
#endif

float Tau; // adaption rate; min=0.0; max=4.0; default=1.25
float TimeDelta; // frame delta

texture InputTexture1;
sampler2D InputSampler1 = sampler_state {
	Texture = (InputTexture1);
	Filter = Point;
	AddressU = Clamp;
	AddressV = Clamp;
};

texture InputTexture2;
sampler2D InputSampler2 = sampler_state {
	Texture = (InputTexture2);
	Filter = Point;
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
	float currLum = tex2D(InputSampler1, float2(0.5, 0.5)).r;
	float lastLum = exp(tex2D(InputSampler2, float2(0.5, 0.5)).r);

	// Pattanaik's technique
	float adaptedLum = lastLum + (currLum - lastLum) * (1.0 - exp(-TimeDelta * Tau));

	return float4(log(adaptedLum), 1.0, 1.0, 1.0);
}

technique AdaptLuminance {
	pass P0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPS();
	}
}