#include "TextureManager.h"

Core::TextureManager G_TextureManager;

namespace Core
{
	TextureManager::TextureManager()
	{
		Textures.clear();
		TextureMap.clear();

		Texture newTexture = { 0, 0, 0, 0 };
		Textures.push_back(newTexture);
		//TextureMap.insert(std::pair<std::string, int>("", 0));
	}

	uint TextureManager::LoadTexture(std::string path)
	{
		Map::iterator it = TextureMap.find(path);

		if (it != TextureMap.end())
		{
			//std::cout << "Already loaded texure: " << path << std::endl;
			return Textures[(*it).second].TextureID;
		}

		if (!FileSystem::Exists(path))
			return 0;

		uint textureID = 0;
		int width = 0;
		int height = 0;
		int channels = 0;

		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_CLAMP_TO_EDGE, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_CLAMP_TO_EDGE, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);

		bool PNG = (channels == 4);

		if (data)
		{
			if (channels == 4)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			else if (channels == 3)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			else if (channels == 1)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
			else
			{
				std::cout << "Failed to load texture channels: " << path << std::endl;
				glBindTexture(GL_TEXTURE_2D, 0);
				return 0;
			}

			glGenerateMipmap(GL_TEXTURE_2D);
			std::cout << "Loaded " << path << " Channels: " << channels << std::endl;
		}
		else
		{
			std::cout << "Failed to load texture: " << path << std::endl;
			glBindTexture(GL_TEXTURE_2D, 0);
			return 0;
		}


		stbi_image_free(data);

		glBindTexture(GL_TEXTURE_2D, 0);

		Texture newTexture = { textureID, width, height, channels };
		Textures.push_back(newTexture);

		int index = Textures.size() - 1;	
		MapPair xpair = MapPair(path, index);
		TextureMap.insert(xpair);

		std::cout << "Loaded tex " << textureID <<std::endl;

		return textureID;
	}

	uint TextureManager::GetTextureID(std::string path)
	{
		std::cout << "ID: " << Textures[TextureMap[path]].TextureID;
		return Textures[TextureMap[path]].TextureID;
	}

	Texture TextureManager::GetTexture(std::string path)
	{
		return Textures[TextureMap[path]];
	}
}