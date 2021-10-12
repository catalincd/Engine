#version 330 core
uniform sampler2D DiffuseMap;
uniform sampler2D SpecularMap;
uniform sampler2D NormalMap;

uniform vec4 Color = vec4(1.0);

in vec2 TexPos;



void main()
{

	vec4 texDiffuse = texture(DiffuseMap, TexPos);

	gl_FragColor = texDiffuse;
};