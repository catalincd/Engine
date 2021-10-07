#include "ShaderManager.h"

Core::ShaderManager G_ShaderManager;

namespace Core
{
	ShaderVar defaultVertexShader = { "res/shaders/defaultVert.shader", GL_VERTEX_SHADER };
	ShaderVar defaultFragmentShader = { "res/shaders/defaultFrag.shader", GL_FRAGMENT_SHADER };

	ShaderVar defaultTextVertexShader = { "res/shaders/defaultTextVert.shader", GL_VERTEX_SHADER };
	ShaderVar defaultTextFragmentShader = { "res/shaders/defaultTextFrag.shader", GL_FRAGMENT_SHADER };

	Shader* defaultShader = new Shader("default", { defaultVertexShader, defaultFragmentShader });
	Shader* defaultTextShader = new Shader("defaultText", { defaultTextVertexShader, defaultTextFragmentShader });


	void ShaderManager::InitList()
	{
		Shaders.clear();
		ShadersMap.clear();

		Shaders.push_back(defaultShader);
		Shaders.push_back(defaultTextShader);
	}


	void ShaderManager::LoadShaders()
	{
		InitList();

		for (int i = 0; i < Shaders.size(); i++)
		{
			Shaders[i]->Load();
			ShadersMap.insert(std::pair<std::string, int>(Shaders[i]->GetName(), i));
		}
	}

	void ShaderManager::DeleteShaders()
	{
		for (int i = 0; i < Shaders.size(); i++)
			delete Shaders[i];

		Shaders.clear();
	}

	uint ShaderManager::GetShaderCount() const
	{
		return Shaders.size();
	}

	GLuint ShaderManager::GetShaderID(const std::string name)
	{
		std::map<std::string, int>::iterator it = ShadersMap.find(name);
		return (it == ShadersMap.end() ? 0 : Shaders[(*it).second]->GetId());
	}

	Shader* ShaderManager::GetShader(const std::string name)
	{
		std::map<std::string, int>::iterator it = ShadersMap.find(name);
		return (it == ShadersMap.end()? nullptr : Shaders[(*it).second]);
	}

	void ShaderManager::SetOrthographicMatrix(const std::string name, float l, float r, float b, float t, float n, float f)
	{
		mat4x4 matrix;
		mat4x4_ortho(matrix, l, r, b, t, n, f);

		GLuint shaderId = GetShaderID(name);

		GLint orthoLocation = glGetUniformLocation(shaderId, "MVP");

		glUniformMatrix4fv(orthoLocation, 1, GL_FALSE, (const GLfloat*)matrix);
	}

	void ShaderManager::SetOrthographicMatrix(float l, float r, float b, float t, float n, float f)
	{
		mat4x4 matrix;
		mat4x4_ortho(matrix, l, r, b, t, n, f);


		for (int i = 0; i < Shaders.size(); i++)
		{
			GLint orthoLocation = Shaders[i]->GetMVPLocation();
			glUniformMatrix4fv(orthoLocation, 1, GL_FALSE, (const GLfloat*)matrix);
		}
		
	}
}