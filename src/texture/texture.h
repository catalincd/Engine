#pragma once
#include "../basic.h"

namespace Core
{
	class Texture
	{
		GLuint m_textureID;
		std::string m_path;
		int m_width;
		int m_height;
		int m_channels;

	public:
		Texture(std::string path);

		void Load();

		inline int Width() const
		{
			return m_width;
		}

		inline int Height() const
		{
			return m_height;
		}

		inline std::string GetPath() const
		{
			return m_path;
		}

		inline GLuint GetID() const
		{
			return m_textureID;
		}
	};
}