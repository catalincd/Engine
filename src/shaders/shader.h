#pragma once
#include "../basic.h"

namespace Core
{
	struct ShaderVar
	{
		std::string path;
		GLenum shaderType;
	};

	class Shader
	{
		std::string m_name;
		GLuint m_shaderID;
		GLint m_MVPLocation;
		std::vector<ShaderVar> m_shaders;

	public:

		Shader(std::string name, std::vector<ShaderVar> shaders);

		
		void Load();
		std::string GetName() const;
		GLuint GetId() const;
		GLuint GetUniform(const char* name); 
		GLuint GetAttrib(const char* name); 
		GLint GetMVPLocation() const;
	};
}