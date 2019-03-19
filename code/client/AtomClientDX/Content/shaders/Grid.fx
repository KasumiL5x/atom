#if OPENGL
	#define SV_POSITION POSITION
	#define VS_SHADERMODEL vs_3_0
	#define PS_SHADERMODEL ps_3_0
#else
	#define VS_SHADERMODEL vs_4_0_level_9_1
	#define PS_SHADERMODEL ps_4_0_level_9_1
#endif

matrix Xform;

struct VertexShaderInput
{
	float4 Position : SV_POSITION;
	float4 Color : COLOR0;
};

struct VertexShaderOutput
{
	float4 Position : SV_POSITION;
	float4 Color : COLOR0;
};

VertexShaderOutput MainVS(in VertexShaderInput input)
{
	VertexShaderOutput output = (VertexShaderOutput)0;

	output.Position = mul(input.Position, Xform);
	output.Color = input.Color;

	return output;
}

struct PixelShaderOutput {
	float4 Color;
	float4 Bloom;
};

PixelShaderOutput MainPS(VertexShaderOutput input) : COLOR
{
	PixelShaderOutput output = (PixelShaderOutput)0;
	output.Color = input.Color;
	output.Bloom = float4(0.0, 0.0, 0.0, 1.0);
	return output;
}

technique BasicColorDrawing
{
	pass P0
	{
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPS();
	}
};