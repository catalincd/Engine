#pragma once
#include "Text.h"
#include "FontManager.h"
#include "../display/window.h"

namespace Core
{
	class TextRenderer
	{
		GLuint VAO, VBO, IBO;

		GLint SamplerLocation, ColorLocation;
		TextVertex m_vertices[1024];
		GLushort indices[1024 * 6];
		const uint defaultIndices[6] = { 0, 1, 2, 2, 3, 0 };
	public:
		void Initialize();

		void Draw(Text text);
	};
}

