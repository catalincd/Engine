#pragma once
#include "../basic.h"
#include "shader.h"

namespace Core
{
	class ShaderManager
	{
		std::map<std::string, int> ShadersMap;
		std::vector<Shader*> Shaders;

	public:
		void InitList();

		void LoadShaders();

		void DeleteShaders();

		uint GetShaderCount() const;

		Shader* GetShader(const std::string name);
		GLuint GetShaderID(const std::string name);

		void SetOrtographicMatrix(const std::string name, float l, float r, float b, float t, float n, float f);
	};
}