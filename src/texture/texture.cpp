#include "texture.h"
#include "stb/stb_image.h"

namespace Core
{
	Texture::Texture(std::string path) : m_path(path)
	{
		
	}

	void Texture::Bind(int slot)
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_textureID);
	}

	void Texture::Unbind(int slot)
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::Load()
	{
		glGenTextures(1, &m_textureID);
		glBindTexture(GL_TEXTURE_2D, m_textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_CLAMP_TO_EDGE, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_CLAMP_TO_EDGE, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		unsigned char* data = stbi_load(m_path.c_str(), &m_width, &m_height, &m_channels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			std::cout << "Loaded " << m_path << std::endl;
		}
		else
		{
			std::cout << "Failed to load texture " << m_path << std::endl;
		}
		stbi_image_free(data);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::LoadJPG()
	{
		glGenTextures(1, &m_textureID);
		glBindTexture(GL_TEXTURE_2D, m_textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		unsigned char* data = stbi_load(m_path.c_str(), &m_width, &m_height, &m_channels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			std::cout << "Loaded " << m_path << std::endl;
		}
		else
		{
			std::cout << "Failed to load texture " << m_path << std::endl;
		}
		stbi_image_free(data);
	}
}