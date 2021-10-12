#include "Element.h"

namespace Core
{
	Element::Element()
	{

	}

	Element::Element(vector2 position, vector2 size, Color color, float angle)
	{
		m_position = position;
		m_size = size;
		m_color = color;
		m_angle = angle;
	}

	void Element::Load() {}

	void Element::Draw() {}

	void Element::GenerateVertices() {}
}