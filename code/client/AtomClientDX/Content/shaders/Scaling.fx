#if OPENGL
	#define SV_POSITION POSITION
	#define VS_SHADERMODEL vs_3_0
	#define PS_SHADERMODEL ps_3_0
#else
	#define VS_SHADERMODEL vs_4_0
	#define PS_SHADERMODEL ps_4_0
#endif

static const float Offsets[4] = {-1.5f, -0.5f, 0.5f, 1.5f};
float2 SourceDimensions;
bool Luminance = false;

texture InputTexture;
sampler2D InputSampler = sampler_state {
	Texture = (InputTexture);
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
	float4 color = float4(0.0, 0.0, 0.0, 0.0);
	for( int x = 0; x < 4; ++x ) {
		for( int y = 0; y < 4; ++y ) {
			float2 offset = float2(Offsets[x], Offsets[y]) / SourceDimensions;
			float4 Sample = tex2D(InputSampler, input.Texcoord + offset);
			color += Sample;
		}
	}
	color /= 16.0;

	if( Luminance ) {
		color = float4(exp(color.r), 1.0, 1.0, 1.0);
	}

	return color;
}

technique Downscale4 {
	pass P0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPS();
	}
}