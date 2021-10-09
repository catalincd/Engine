#pragma once
#include <vector>
#include <sstream>
#include "Font.h"

namespace Core
{
	class FontManager
	{
		std::vector<Font> m_fonts;

	public:
		void Initialize();

		void LoadFonts();

		void AddFont(Font font);

		const Font& GetFont(int idx);

		const Font& GetFont(std::string name);
	};
}