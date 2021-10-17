#pragma once
#include "../basic.h"
#include "../Entity/Entity.h"
#include "../utils/math.h"
#include "../GlobalController/GlobalController.h"
#include "../Light/Light.h"


namespace Core
{
	class Renderer : public GlobalController
	{
		GLuint ShaderID;

		GLuint VAO;
		GLuint VBO;
		GLuint IBO;

		GLint LocationDiffuse;
		GLint LocationSpecular;
		GLint LocationNormal;

		GLint LocationColor;

		/////Lights
		GLint LocationLightPositions[MAX_LIGHTS];
		GLint LocationLightFalloffs[MAX_LIGHTS];
		GLint LocationLightColors[MAX_LIGHTS];
		/////

		GLint LocationSpecularScale;
		GLint LocationLightsNum;
		GLint LocationAmbient;
		GLint LocationResolution; 
		GLint LocationApplyLightType;

		GLushort indices[6] = { 0, 1, 2, 2, 3, 0 };
	public:
		void Initialize();

		void Update();

		void DrawEntity(const Entity& entity);
	};
}