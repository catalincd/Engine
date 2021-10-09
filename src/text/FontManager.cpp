#include "Font.h"
#include "FontManager.h"


Core::FontManager G_FontManager;
Core::Font Verdana("Verdana");
Core::Font VerdanaBold("VerdanaBold");

namespace Core
{
	

	void FontManager::Initialize()
	{
		AddFont(Verdana);
		AddFont(VerdanaBold);

		LoadFonts();
	}

	void FontManager::LoadFonts()
	{
		for (int i = 0; i < m_fonts.size(); i++)
			m_fonts[i].Load();
	}

	void FontManager::AddFont(Font font)
	{
		m_fonts.push_back(font);
	}

	const Font& FontManager::GetFont(int idx)
	{
		return m_fonts[idx];
	}

	const Font& FontManager::GetFont(std::string name)
	{
		for (int i = 0; i < m_fonts.size(); i++)
			if (m_fonts[i].GetName() == name)
				return m_fonts[i];

		return Verdana;
	}
}