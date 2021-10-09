#version 330 core


uniform float testUniform = 1;
uniform sampler2D u_Textures[64];
in float TextureID;
in vec2 TexPos;
in vec4 Color;



void main()
{
	int index = int(TextureID);

	vec4 texColor = texture(u_Textures[index], TexPos);

	gl_FragColor = texColor * Color;
};