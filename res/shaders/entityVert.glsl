#version 330 core
uniform mat4 MVP = mat4(1.0f);


layout(location = 0) in vec3 vPos;
layout(location = 1) in vec2 vTexPos;

out vec2 TexPos;


void main()
{
    TexPos = vTexPos;

    gl_Position = MVP * vec4(vPos.x, vPos.y, 0.0, 1.0);
};