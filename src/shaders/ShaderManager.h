#pragma once
#include "../basic.h"
#include "shader.h"

namespace Core
{
	class ShaderManager
	{
		Map ShadersMap;
		std::vector<Shader*> Shaders;

	public:
		void InitList();

		void LoadShaders();

		void DeleteShaders();

		uint GetShaderCount() const;

		Shader* GetShader(const std::string name);
		GLuint GetShaderID(const std::string name);

		void SetOrthographicMatrix(const std::string name, float l, float r, float b, float t, float n, float f);

		void SetOrthographicMatrix(float l, float r, float b, float t, float n, float f);
	};
}