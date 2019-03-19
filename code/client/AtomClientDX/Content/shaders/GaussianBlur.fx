#if OPENGL
	#define SV_POSITION POSITION
	#define VS_SHADERMODEL vs_3_0
	#define PS_SHADERMODEL ps_3_0
#else
	#define VS_SHADERMODEL vs_4_0_level_9_1
	#define PS_SHADERMODEL ps_4_0_level_9_1
#endif

float2 TextureSize; // size of a single pixel, a.k.a 1.0f/size
bool Horizontal;

static const float Weight[5] = {0.2270270270, 0.1945945946, 0.1216216216, 0.0540540541, 0.0162162162};

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
	output.Texcoord = input.Texcoord;

	return output;
}

float4 MainPS( VertexShaderOutput input ) : SV_TARGET {
	float3 result = tex2D(InputSampler, input.Texcoord).rgb * Weight[0]; // current fragment's contrib

	if( Horizontal ) {
		for( int i = 1; i < 5; ++i ) {
			result += tex2D(InputSampler, input.Texcoord + float2(TextureSize.x * i, 0.0)).rgb * Weight[i];
			result += tex2D(InputSampler, input.Texcoord - float2(TextureSize.x * i, 0.0)).rgb * Weight[i];
		}
	} else {
		for( int i = 1; i < 5; ++i ) {
			result += tex2D(InputSampler, input.Texcoord + float2(0.0, TextureSize.y * i)).rgb * Weight[i];
			result += tex2D(InputSampler, input.Texcoord - float2(0.0, TextureSize.y * i)).rgb * Weight[i];
		}
	}

	return float4(result, 1.0);
}

technique GaussianBlur {
	pass P0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPS();
	}
}