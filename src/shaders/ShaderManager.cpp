#include "ShaderManager.h"

Core::ShaderManager G_ShaderManager;

namespace Core
{
	ShaderVar defaultVertexShader = { "res/shaders/defaultVert.glsl", GL_VERTEX_SHADER };
	ShaderVar defaultFragmentShader = { "res/shaders/defaultFrag.glsl", GL_FRAGMENT_SHADER };

	ShaderVar defaultTextVertexShader = { "res/shaders/defaultTextVert.glsl", GL_VERTEX_SHADER };
	ShaderVar defaultTextFragmentShader = { "res/shaders/defaultTextFrag.glsl", GL_FRAGMENT_SHADER };

	ShaderVar entityVertex = { "res/shaders/entityVert.glsl", GL_VERTEX_SHADER };
	ShaderVar entityFragment = { "res/shaders/entityFrag.glsl", GL_FRAGMENT_SHADER };

	Shader* defaultShader = new Shader("default", { defaultVertexShader, defaultFragmentShader });
	Shader* defaultTextShader = new Shader("defaultText", { defaultTextVertexShader, defaultTextFragmentShader });
	Shader* entityShader = new Shader("entity", { entityVertex, entityFragment });

	void ShaderManager::InitList()
	{
		Shaders.clear();
		ShadersMap.clear();

		Shaders.push_back(defaultShader);
		Shaders.push_back(defaultTextShader);
		Shaders.push_back(entityShader);
	}


	void ShaderManager::LoadShaders()
	{
		InitList();

		for (int i = 0; i < Shaders.size(); i++)
		{
			Shaders[i]->Load();
			ShadersMap.insert(MapPair(Shaders[i]->GetName(), i));
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
		Map::iterator it = ShadersMap.find(name);
		return (it == ShadersMap.end() ? 0 : Shaders[(*it).second]->GetId());
	}

	Shader* ShaderManager::GetShader(const std::string name)
	{
		Map::iterator it = ShadersMap.find(name);
		return (it == ShadersMap.end()? nullptr : Shaders[(*it).second]);
	}

	void ShaderManager::SetOrthographicMatrix(const std::string name, float l, float r, float b, float t, float n, float f)
	{
		mat4x4 matrix;
		mat4x4_ortho(matrix, l, r, b, t, n, f);

		GLint orthoLocation = GetShader(name)->GetMVPLocation();
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