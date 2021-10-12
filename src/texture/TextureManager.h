#pragma once
#include "../basic.h"

namespace Core
{
	struct Texture
	{
		uint TextureID;
		int Width;
		int Height;
		int Channels;
	};

	class TextureManager
	{
		std::vector<Texture> Textures;
		Map TextureMap;

	public:

		TextureManager();
		uint LoadTexture(std::string path);

		uint GetTextureID(std::string path);
		Texture GetTexture(std::string path);


	};
}