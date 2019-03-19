#define VS_SHADERMODEL vs_5_0
#define PS_SHADERMODEL ps_5_0

matrix Xform;
matrix World; // WORKING #2
float3 LightPosition; // WORKING #2
float FarPlane; // WORKING #2

struct VertexShaderInput {
	float3 Position : SV_POSITION;
	float3 Normal : NORMAL0;
	float4 Tangent : TANGENT0;
	float2 Texcoord : TEXCOORD0;
};

struct VertexShaderOutput {
	float4 Position : POSITION;
	float3 WPos : TANGENT0; // WORKING #2
	nointerpolation float Depth : TEXCOORD0;
};

VertexShaderOutput MainVS(in VertexShaderInput input) {
	VertexShaderOutput output = (VertexShaderOutput)0;
	output.Position = mul(float4(input.Position, 1.0), Xform);

	// WORKING #1
	//output.Depth = (output.Position.z / output.Position.w);

	// WORKING #2
	//output.WPos = mul(float4(input.Position, 1.0), World).xyz;

	return output;
}

float4 MainPS(VertexShaderOutput input) : SV_TARGET {
	// WORKING #1
	//return float4(input.Depth, 0.0, 0.0, 1.0);
	return float4(input.Position.z, 0.0, 0.0, 1.0);

	// WORKING #2
	//float depth = max(0.01, length(LightPosition - input.WPos)) / FarPlane;
	//return float4(exp((FarPlane * 0.5) * depth), 0.0, 0.0, 1.0);
}

technique Depth {
	pass Pass0 {
		VertexShader = compile VS_SHADERMODEL MainVS();
		PixelShader = compile PS_SHADERMODEL MainPS();
	}
};