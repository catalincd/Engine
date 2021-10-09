#version 330 core
uniform sampler2D u_Texture;
uniform vec4 u_Color = vec4(1.0);
in vec2 TexPos;

void main()
{
	gl_FragColor = texture(u_Texture, TexPos) * u_Color;
};