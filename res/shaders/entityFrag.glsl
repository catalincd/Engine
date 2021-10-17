#version 330 core

struct Light
{
	vec4 Color;
	vec3 Position;
	vec3 Falloff;
};


uniform sampler2D DiffuseMap;
uniform sampler2D NormalMap;
uniform sampler2D SpecularMap;
uniform vec4 vColor = vec4(1.0);
uniform vec4 Ambient = vec4(0.05);
uniform vec2 Resolution;
uniform int ApplyLightType = 0; 
uniform float SpecularScale = 1.0f;
in vec2 TexPos;

uniform Light Lights[4];
uniform int LightsNum = 0;

void main()
{

	vec4 DiffuseColor = texture2D(DiffuseMap, TexPos);
	vec3 vNormalMap = texture2D(NormalMap, TexPos).xyz;
	vec3 vSpecular = mix(vec3(1.0), texture2D(SpecularMap, TexPos).xyz, SpecularScale);

	vec3 FinalColor = vec3(0.0);
	vec3 xAmbient = Ambient.rgb * Ambient.a;

	if(ApplyLightType == 0)
	{
		
		for(int i=0;i<LightsNum;i++)
		{
			vec3 LightPos = Lights[i].Position;
			vec4 LightColor = Lights[i].Color;
			vec3 Falloff = Lights[i].Falloff;

			vec2 GLPos = vec2(gl_FragCoord.x, gl_FragCoord.y * -1 + Resolution.y);

			vec3 LightDir = vec3((GLPos - LightPos.xy) / Resolution.xy, LightPos.z);
	
			LightDir.x *= Resolution.x / Resolution.y;
	
			float D = length(LightDir.xy);
	
			vec3 N = normalize(vNormalMap * 2.0 - 1.0);
			vec3 L = normalize(LightDir);

			vec3 Diffuse = vSpecular * (LightColor.rgb * LightColor.a) * max(dot(N, L), 0.0);
			
			float Attenuation = 1.0 / ( Falloff.x + (Falloff.y*D) + (Falloff.z*D*D) );
	
			vec3 Intensity = xAmbient + Diffuse * Attenuation;
			FinalColor += DiffuseColor.rgb * Intensity;
		}
	}
	else
	{
		if(ApplyLightType == 1)
			FinalColor = DiffuseColor.rgb * Ambient.rgb;
		else
			FinalColor = DiffuseColor.rgb;
	}

	gl_FragColor = vColor * vec4(FinalColor, DiffuseColor.a);

};