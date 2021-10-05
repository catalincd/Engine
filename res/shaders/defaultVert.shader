#version 330 core
uniform mat4 MVP = mat4(1.0f);


layout(location = 0) in vec3 vPos;
layout(location = 1) in vec4 vColor;
layout(location = 2) in vec2 vTexPos;
layout(location = 3) in float vTextureID;

out float TextureID;
out vec2 TexPos;
out vec4 Color;


void main()
{
    TextureID = vTextureID;
    TexPos = vTexPos;
    Color = vColor;

    gl_Position = MVP * vec4(vPos.x, vPos.y, 0.0, 1.0);
};