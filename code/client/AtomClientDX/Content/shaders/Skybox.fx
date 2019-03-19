#if OPENGL
	#define SV_POSITION POSITION
	#define VS_SHADERMODEL vs_3_0
	#define PS_SHADERMODEL ps_3_0
#else
	#define VS_SHADERMODEL vs_4_0
	#define PS_SHADERMODEL ps_4_0
#endif

float4x4 ViewMatrix;
float4x4 InverseProjMatrix;

TextureCube SkyboxTexture;
SamplerState SkyboxSampler = sampler_state {
	Texture = <SkyboxTexture>;
	Filter = Linear;
	AddressU = Clamp;
	AddressV = Clamp;
	AddressW = Clamp;
};

struct VertexShaderInput {
	float4 Position  : POSITION;
	float4 Texcoord : TEXCOORD0;
};

struct VertexShaderOutput {
	float4 HPosition : SV_POSITION;
	float3 Texcoord : TEXCOORD0;
};

VertexShaderOutput MainVS(in VertexShaderInput input) {
	VertexShaderOutput output = (VertexShaderOutput)0;

	output.HPosition = float4(input.Position.xyz, 1.0);

	float3x3 view33 = (float3x3)ViewMatrix;
	view33 = (view33);
	float3 unprojected = mul(InverseProjMatrix, float4(input.Position.xyz, 1.0)).xyz;
	output.Texcoord = mul(view33, unprojected);
	//output.Texcoord.y = -output.Texcoord.y;

	return output;
}

float4 MainPS( VertexShaderOutput input ) : SV_TARGET {
	//return float4(input.Texcoord, 1.0);
	float3 tex = SkyboxTexture.Sample(SkyboxSampler, input.Texcoord).xyz;
	return float4(tex, 1.0);
}

technique Skybox {
	pass P0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPS();
	}
}