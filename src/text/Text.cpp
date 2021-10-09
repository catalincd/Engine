#include "Text.h"
#include "TextRenderer.h"

extern Core::FontManager G_FontManager;
extern Core::TextRenderer G_TextRenderer;

namespace Core
{
	Text::Text(std::string text, vector2 position, std::string font, Color color)
	{
		m_text = text;
		m_position = position;
		m_font = font;
		m_origin = vector2(0.0f);
		m_color = color;
		m_fontRef = G_FontManager.GetFont(font);

		CalculateVertices();
	}

	void Text::CalculateVertices()
	{
		m_size = m_fontRef.ComputeTextSize(m_text) * m_scale;
		vector2 m_absolutePosition = m_position - (m_size * m_origin);

		m_vertices.clear();

		float x = m_absolutePosition.x;
		float y = m_absolutePosition.y;

		for (int i = 0; i < m_text.length(); i++)
		{
			vector2 o = m_fontRef.GetOffset(m_text[i]) * m_scale.x;
			vector2 topLeftPosition = m_fontRef.GetPosition(m_text[i]);
			vector2 bottomRightPosition = m_fontRef.GetBottom(m_text[i]);
			vector2 s = m_fontRef.GetSize(m_text[i]) * m_scale;

			float _x = x + o.x;
			float _y = y + o.y ;

			TextVertex topLeft = { _x, _y, m_Z, topLeftPosition.x, topLeftPosition.y};
			TextVertex topRight = { _x + s.x, _y, m_Z, bottomRightPosition.x, topLeftPosition.y };
			TextVertex bottomRight = { _x + s.x, _y + s.y, m_Z, bottomRightPosition.x, bottomRightPosition.y };
			TextVertex bottomLeft = { _x, _y + s.y, m_Z, topLeftPosition.x, bottomRightPosition.y};

			m_vertices.push_back(topLeft);
			m_vertices.push_back(topRight);
			m_vertices.push_back(bottomRight);
			m_vertices.push_back(bottomLeft);

			x += m_fontRef.GetAdvance(m_text[i]) * m_scale.x;

			//std::cout<< m_size2D.x<<' ';
		}
	}

	void Text::Draw()
	{
		CalculateVertices();
		G_TextRenderer.Draw(*this);
	}

	TextVertex Text::GetVertex(int idx)
	{
		return m_vertices[idx];
	}

	uint Text::GetLength() const
	{
		return m_text.length();
	}

	Font Text::GetFont()
	{
		return m_fontRef;
	}

	void Text::SetOrigin(vector2 origin)
	{
		m_origin = origin;
	}

	void Text::SetScale(vector2 scale)
	{
		m_scale = scale;
	}

	void Text::SetScale(float scale)
	{
		m_scale = vector2(scale);
	}

	void Text::SetPosition(vector2 position)
	{
		m_position = position;
	}

	void Text::SetColor(Color color)
	{
		m_color = color;
	}

	void Text::SetText(std::string text)
	{
		m_text = text;
	}

	Color Text::GetColor() const
	{
		return m_color;
	}
}