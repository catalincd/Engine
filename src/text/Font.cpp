#include "Font.h"
#include "math.h"
#include "../Texture/TextureManager.h"
#include <windows.h>

extern Core::TextureManager G_TextureManager;

namespace Core
{
	Font::Font(std::string name)
	{
		m_name = name;
		m_path = FONTS_PATH + name + ".fnt";
		m_texturePath = FONTS_PATH + name + ".png";
	}

	std::string Font::GetName() const
	{
		return m_name;
	}

	void Font::Load()
	{
		std::vector<std::string> lines = FileSystem::ReadLines(m_path);

		std::vector<std::string> fontParams = Split(lines[1]);
		m_size.x = ParseInt(GetValueFromExpression(fontParams[3]));
		m_size.y = ParseInt(GetValueFromExpression(fontParams[4]));

		for (int i = 4; i < lines.size(); i++)
		{
			std::vector<std::string> params = Split(lines[i]);

			int index = ParseInt(GetValueFromExpression(params[1]));

			x[index] = float(ParseInt(GetValueFromExpression(params[2]))) / m_size.x;
			y[index] = float(ParseInt(GetValueFromExpression(params[3]))) / m_size.y;

			width[index] = ParseInt(GetValueFromExpression(params[4]));
			height[index] = ParseInt(GetValueFromExpression(params[5]));

			xS[index] = x[index] + (width[index] / m_size.x);
			yS[index] = y[index] + (height[index] / m_size.y);

			xO[index] = float(ParseInt(GetValueFromExpression(params[6])));
			yO[index] = float(ParseInt(GetValueFromExpression(params[7])));

			advance[index] = ParseInt(GetValueFromExpression(params[8]));

			m_maxHeight = max(m_maxHeight, height[index]);
		}

		m_textureID = G_TextureManager.LoadTexture(m_texturePath);
	}

	vector2 Font::ComputeTextSize(std::string text)
	{
		float x = 0;

		for (int i = 0; i < text.length(); i++)
		{
			x += advance[text[i]];
		}

		return vector2(x, m_maxHeight * 1.5f);
	}

	vector2 Font::GetPosition(char c)
	{
		return vector2(x[c], y[c]);
	}

	vector2 Font::GetSize(char c)
	{
		return vector2(width[c], height[c]);
	}

	vector2 Font::GetOffset(char c)
	{
		return vector2(xO[c], yO[c]);
	}

	float Font::GetAdvance(char c)
	{
		return advance[c];
	}

	vector2 Font::GetBottom(char c)
	{
		return vector2(xS[c], yS[c]);
	}

	uint Font::GetTextureID() const
	{
		return m_textureID;
	}
	
}