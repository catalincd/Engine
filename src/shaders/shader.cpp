#include "shader.h"
#include <queue>

namespace Core
{
	GLuint Shader::GetId() const
	{
		return m_shaderID;
	}

	std::string Shader::GetName() const
	{
		return m_name;
	}

	GLuint Shader::GetUniform(const char* name)
	{
		GLuint id = glGetUniformLocation(m_shaderID, name);
		if (!id)
			ErrorHandler::Log("Uniform not found: " + (std::string)name);

		return id;
	}

	GLuint Shader::GetAttrib(const char* name)
	{
		GLuint id = glGetAttribLocation(m_shaderID, name);
		if (!id)
			ErrorHandler::Log("Attrib not found " + (std::string)name);

		return id;
	}

	Shader::Shader(std::string name, std::vector<ShaderVar> shaders)
	{
		m_shaders = shaders;
		m_name = name;
	}

	GLint Shader::GetMVPLocation() const
	{
		return m_MVPLocation;
	}

	void Shader::Load()
	{
		std::queue<GLuint> shadersQueue;

		for (int i = 0; i < m_shaders.size(); i++)
		{
			GLuint tempID;
			std::string shaderString = FileSystem::ReadFile(m_shaders[i].path);
			const char* shaderText = shaderString.c_str();

			tempID = glCreateShader(m_shaders[i].shaderType);
			glShaderSource(tempID, 1, &shaderText, NULL);
			glCompileShader(tempID);


			GLint isCompiled = 0;
			glGetShaderiv(tempID, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(tempID, GL_INFO_LOG_LENGTH, &maxLength);
				std::vector<GLchar> errorLog(maxLength);
				glGetShaderInfoLog(tempID, maxLength, &maxLength, &errorLog[0]);
				ErrorHandler::Log("Error shader file: " + m_shaders[i].path);
				ErrorHandler::Log(errorLog);
				glDeleteShader(tempID);
				continue;
			}

			shadersQueue.push(tempID);
		}

		m_shaderID = glCreateProgram();

		while (!shadersQueue.empty())
		{
			glAttachShader(m_shaderID, shadersQueue.front());
			glDeleteShader(shadersQueue.front());
			shadersQueue.pop();
		}

		glLinkProgram(m_shaderID);

		m_MVPLocation = glGetUniformLocation(m_shaderID, "MVP");
	}
}