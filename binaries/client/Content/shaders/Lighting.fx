/**
 * Computes Lambert lighting.
 * @param L             Light vector.
 * @param N             Surface normal.
 * @param diffuseColor  Color of light's diffuse.
 * @param intensity     Intensity of light source.
 */
float3 lambert( float3 L, float3 N, float3 diffuseColor, float intensity ) {
	float diffuseLight = max(dot(L, N), 0.0);
	return (diffuseLight * diffuseColor) * intensity;
}

/**
 * Computes Phong lighting.
 * @param L             Light vector.
 * @param N             Surface normal.
 * @param camPos        Worldspace camera position.
 * @param worldPos      Worldspace fragment position.
 * @param diffuseColor  Color of light's diffuse.
 * @param specularColor Color of light's specular highlights.
 * @param intensity     Intensity of light source.
 * @param shininess     Specular exponent.
 */
float3 phong( float3 L, float3 N, float3 camPos, float3 worldPos, float3 diffuseColor, float3 specularColor, float intensity, float shininess ) {
	float3 diffuse = diffuseColor * max(dot(L, N), 0.0);

	float3 V = normalize(camPos - worldPos);
	float3 RL = reflect(-L, N);
	float RdotV = max(dot(RL, V), 0.0);
	float3 specular = shininess > 0.0 ? specularColor * pow(RdotV, shininess) : float3(0.0, 0.0, 0.0);

	return (diffuse + specular) * intensity;
}

/**
 * Computes Blinn-Phong lighting.
 * @param L             Light vector.
 * @param N             Surface normal.
 * @param camPos        Worldspace camera position.
 * @param worldPos      Worldspace fragment position.
 * @param diffuseColor  Color of light's diffuse.
 * @param specularColor Color of light's specular highlights.
 * @param intensity     Intensity of light source.
 * @param shininess     Specular exponent.
 */
float3 blinn( float3 L, float3 N, float3 camPos, float3 worldPos, float3 diffuseColor, float3 specularColor, float intensity, float shininess ) {
	float3 diffuse = diffuseColor * max(dot(L, N), 0.0);

	float3 V = normalize(camPos - worldPos);
	float3 H = normalize(L + V);
	float HdotN = max(dot(H, N), 0.0);
	float3 specular = shininess > 0.0 ? specularColor * pow(HdotN, shininess) : float3(0.0, 0.0, 0.0);

	return (diffuse + specular) * intensity;
}

/**
 * Computes isotropic Ward lighting.
 * @param L             Light vector.
 * @param N             Surface normal.
 * @param camPos        Worldspace camera position.
 * @param worldPos      Worldspace fragment position.
 * @param diffuseColor  Color of light's diffuse.
 * @param specularColor Color of light's specular highlights.
 * @param intensity     Intensity of light source.
 * @param roughness     Roughness of specular.
 */
float3 ward_iso( float3 L, float3 N, float3 camPos, float3 worldPos, float3 diffuseColor, float3 specularColor, float intensity, float roughness ) {
	float3 V = normalize(camPos - worldPos);
	float3 H = normalize(L + V);

	float VdotN = dot(V, N);
	float LdotN = dot(L, N);
	float HdotN = dot(H, N);
	float r_sq = (roughness * roughness) + 1e-5;

	float exp_a = -pow(tan(acos(HdotN)), 2.0);
	float spec_num = exp(exp_a / r_sq);
	float spec_den = 4.0 * 3.14159 * r_sq;
	spec_den *= sqrt( LdotN * VdotN );
	if( isnan(spec_den) ) {
		spec_den = 1.0;
	}
	float3 specular = specularColor * (spec_num / spec_den);

	return (LdotN * (diffuseColor + specular)) * intensity;
}

/**
 * Computes anisotropic Ward lighting.
 * @param L             Light vector.
 * @param N             Surface normal.
 * @param camPos        Worldspace camera position.
 * @param worldPos      Worldspace fragment position.
 * @param diffuseColor  Color of light's diffuse.
 * @param specularColor Color of light's specular highlights.
 * @param intensity     Intensity of light source.
 * @param roughness     Roughness of specular.
 */
float3 ward_aniso( float3 L, float3 N, float3 camPos, float3 worldPos, float3 diffuseColor, float3 specularColor, float intensity, float2 roughness ) {
	float3 V = normalize(camPos - worldPos);
	float3 H = normalize(L + V);

	// bias for non-zero
	roughness += float2(1e-5, 1e-5);

	// define coordinate frame
	float3 epsilon = float3(1.0, 0.0, 0.0);
	float3 tangent = normalize(cross(N, epsilon));
	float3 binormal = normalize(cross(N, tangent));

	float VdotN = dot(V, N);
	float LdotN = dot(L, N);
	float HdotN = dot(H, N);
	float HdotT = dot(H, tangent);
	float HdotB = dot(H, binormal);

	// evaluate specular exponent
	float beta_a = HdotT / roughness.x;
	beta_a *= beta_a;
	float beta_b = HdotB / roughness.y;
	beta_b *= beta_b;
	float beta = -2.0 * ( ( beta_a + beta_b ) / ( 1.0 + HdotN ) );
	// evaluate specular denominator
	float s_den = 4.0 * 3.14159;
	s_den *= roughness.x;
	s_den *= roughness.y;
	s_den *= sqrt(LdotN * VdotN);
	// compute final specular term
	float3 specular = specularColor * (exp(beta) / s_den);

	return (LdotN * (diffuseColor + specularColor)) * intensity;
}

/**
 * Computes Cook-Torrance lighting.
 * @param L                  Light vector.
 * @param N                  Surface normal.
 * @param camPos             Worldspace camera position.
 * @param worldPos           Worldspace fragment position.
 * @param diffuseColor       Color of light's diffuse.
 * @param specularColor      Color of light's specular highlights.
 * @param intensity          Intensity of light source.
 * @param roughnessValue     Roughness value.
 * @param refAtNormIncidence Arbitrary roughness value.
 */
float3 cook_torrance( float3 L, float3 N, float3 camPos, float3 worldPos, float3 diffuseColor, float3 specularColor, float intensity, float roughnessValue, float refAtNormIncidence ) {
	float3 V = normalize(camPos - worldPos);
	float3 H = normalize(L + V);

	float NdotL = max(dot(N, L), 0.0);
	float NdotH = max(dot(N, H), 0.0);
	float NdotV = max(dot(N, V), 0.0);
	float VdotH = max(dot(V, H), 0.0);
	float r_sq = (roughnessValue * roughnessValue) + 1e-5;

	// evaluate geometric term
	float geo_num = 2.0 * NdotH;
	float geo_den = VdotH;
	float geo_b = (geo_num * NdotV) / geo_den;
	float geo_c = (geo_num * NdotL) / geo_den;
	float geo = min(1.0, min(geo_b, geo_c));

	// evaluate roughness term using gaussian mode
	float roughness_c = 1.0; // could be exposed to control
	float roughness_alpha = acos(dot(N, H));
	float roughness = roughness_c * exp(-(roughness_alpha / r_sq ));

	// evaluate fresnel term
	float fresnel = pow(1.0 - VdotH, 5.0 );
	fresnel *= (1.0 - refAtNormIncidence);
	fresnel += refAtNormIncidence;

	// specular term
	float3 rs_num = (fresnel * geo * roughness);
	float rs_den = NdotV * NdotL;
	float3 rs = rs_num / rs_den;

	// final term
	return (NdotL * (specularColor * rs + diffuseColor)) * intensity;
}

/**
 * Computes Oren-Nyar lighting.
 * @param L            Light vector.
 * @param N            Surface normal.
 * @param camPos       Worldspace camera position.
 * @param worldPos     Worldspace fragment position.
 * @param diffuseColor Color of light's diffuse.
 * @param intensity    Intensity of light source.
 * @param roughness    Roughness value.
 */
float3 oren_nayar( float3 L, float3 N, float3 camPos, float3 worldPos, float3 diffuseColor, float intensity, float roughness ) {
	const float PI = 3.14159;

	float3 V = normalize(camPos - worldPos);

	float VdotN = dot(V, N);
	float LdotN = dot(L, N);
	float alpha = max(acos(VdotN), acos(LdotN));
	float beta = min(acos(VdotN), acos(LdotN));
	float gamma = dot(V - N * VdotN, L - N * LdotN);
	float rough_sq = roughness * roughness;
	float C1 = 1.0 - 0.5 * (rough_sq / (rough_sq + 0.33));
	float C2 = 0.45 * (rough_sq / (rough_sq + 0.09));
	if( gamma >= 0.0 ) {
		C2 *= sin(alpha);
	} else {
		C2 *= (sin(alpha) - pow((2.0 * beta) / PI, 3.0));
	}
	float C3 = (1.0 / 8.0);
	C3 *= (rough_sq / (rough_sq + 0.09));
	C3 *= pow((4.0 * alpha * beta) / (PI * PI), 2.0);
	float A = gamma * C2 * tan(beta);
	float B = (1.0 - abs(gamma)) * C3 * tan((alpha + beta) / 2.0);

	return (diffuseColor * max(0.0, dot(N, L)) * (C1 + A + B)) * intensity;
}

/**
 * Computes Ashikhmin-Shirley lighting.
 * @param L                  Light vector.
 * @param N                  Surface normal.
 * @param camPos             Worldspace camera position.
 * @param worldPos           Worldspace fragment position.
 * @param diffuseColor       Color of light's diffuse.
 * @param specularColor      Color of light's specular highlights.
 * @param intensity          Intensity of light source.
 * @param anisotropy         Anisotropic value.
 */
float3 ashikhmin_shirley( float3 L, float3 N, float3 camPos, float3 worldPos, float3 diffuseColor, float3 specularColor, float intensity, float2 anisotropy ) {
	float3 V = normalize(camPos - worldPos);
	float3 H = normalize(L + V);

	// define coordinate frame
	float3 epsilon = float3(1.0, 0.0, 0.0);
	float3 tangent = normalize(cross(N, epsilon));
	float3 binormal = normalize(cross(N, tangent));

	float VdotN = dot(V, N);
	float LdotN = dot(L, N);
	float HdotN = dot(H, N);
	float HdotL = dot(H, L);
	float HdotT = dot(H, tangent);
	float HdotB = dot(H, binormal);

	float3 Rd = diffuseColor;
	float3 Rs = specularColor;

	float Nu = anisotropy.x;
	float Nv = anisotropy.y;

	// compute diffuse term
	float3 Pd = (28.0 * Rd) / (23.0 * 3.14159);
	Pd *= (1.0 - Rs);
	Pd *= (1.0 - pow(1.0 - (LdotN / 2.0), 5.0));
	Pd *= (1.0 - pow(1.0 - (VdotN / 2.0), 5.0));

	// compute the specular term
	float ps_num_exp = Nu * HdotT * HdotT + Nv * HdotB * HdotB;
	ps_num_exp /= (1.0 - HdotN * HdotN);
	float Ps_num = sqrt((Nu + 1.0) * (Nv + 1.0));
	Ps_num *= pow(HdotN, ps_num_exp);
	float Ps_den = 8.0 * 3.14159 * HdotL;
	Ps_den *= max(LdotN, VdotN);
	float3 Ps = Rs * (Ps_num / Ps_den);
	Ps *= (Rs + (1.0 - Rs) * pow(1.0 - HdotL, 5.0));

	return Pd + Ps;
}