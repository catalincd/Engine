#pragma once
#include "../basic.h"

namespace Core
{
	struct UIVertex
	{
		float x, y, z;
		float r, g, b, a;
		float tx, ty;
		float ti;
	};

	class Element
	{
	protected:
		vector2 m_position;
		vector2 m_size;
		vector2 m_origin = vector2(0.0f);
		Color m_color;
		float m_angle;
	public:
		Element();
		Element(vector2 position, vector2 size, Color color = Color(0xFFFFFFFF), float angle = 0);

		virtual void Load();
		virtual void Draw();
		virtual void GenerateVertices();	
	};
}