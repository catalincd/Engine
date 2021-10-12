#pragma once
#include "../basic.h"
#include "FontManager.h"



extern Core::Font Verdana;

namespace Core
{
	struct TextVertex
	{
		float x, y, z;
		float tx, ty;
	};

	class Text
	{
		std::string m_text;
		std::string m_font;
		vector2 m_position;
		vector2 m_origin;
		vector2 m_scale = vector2(1.0f);
		vector2 m_size;
		Color m_color;
		float m_spacing = 1.0f;
		float m_angle = 0.0f;
		float m_Z = 0.5f;	///text in front of everything

		Font& m_fontRef = Verdana;
		std::vector<TextVertex> m_vertices;
	public:

		Text(std::string text, vector2 position, std::string font = "Verdana", Color color = Color(1.0f, 1.0f, 1.0f, 1.0f));

		void CalculateVertices();

		void Draw();

		Font GetFont();

		uint GetLength() const;

		TextVertex GetVertex(int idx);

		void SetOrigin(vector2 origin);
		void SetScale(vector2 scale);
		void SetScale(float scale);
		void SetPosition(vector2 position);
		void SetColor(Color color);
		void SetText(std::string text);

		Color GetColor() const;
	};
}