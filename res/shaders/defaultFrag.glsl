#version 330 core


uniform float testUniform = 1;
uniform float brightness = 0.0f;
uniform float contrast = 1.0f;
uniform float saturation = 1.0f;
uniform sampler2D u_Textures[64];
in float TextureID;
in vec2 TexPos;
in vec4 Color;

mat4 brightnessMatrix(float brightness)
{
    return mat4(1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        brightness, brightness, brightness, 1);
}

mat4 contrastMatrix(float contrast)
{
    float t = (1.0 - contrast) / 2.0;

    return mat4(contrast, 0, 0, 0,
        0, contrast, 0, 0,
        0, 0, contrast, 0,
        t, t, t, 1);

}

mat4 saturationMatrix(float saturation)
{
    vec3 luminance = vec3(0.3086, 0.6094, 0.0820);

    float oneMinusSat = 1.0 - saturation;

    vec3 red = vec3(luminance.x * oneMinusSat);
    red += vec3(saturation, 0, 0);

    vec3 green = vec3(luminance.y * oneMinusSat);
    green += vec3(0, saturation, 0);

    vec3 blue = vec3(luminance.z * oneMinusSat);
    blue += vec3(0, 0, saturation);

    return mat4(red, 0,
        green, 0,
        blue, 0,
        0, 0, 0, 1);
}

void main()
{
	int index = int(TextureID);

	vec4 texColor = texture(u_Textures[index], TexPos);

	gl_FragColor = brightnessMatrix(brightness) * contrastMatrix(contrast) * saturationMatrix(saturation) * vec4(mix(texColor.xyz, Color.xyz, 0.5), texColor.a * Color.a);
};