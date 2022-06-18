#include "Sprite.h"
#include "../renderer/SpriteRenderer.h"
#include "../utils/math.h"

extern Core::SpriteRenderer G_SpriteRenderer;
extern Core::TextureManager G_TextureManager;


namespace Core
{
	Math math;

	Sprite::Sprite(std::string path, vector2 position, vector2 size, Color color = Color(0xFFFFFFFF), float angle = 0)
	{
		m_path = path;
		m_position = position;
		m_size = size;
		m_color = color;
		m_angle = angle;
	}

	GLuint Sprite::GetTextureID() const
	{
		return m_textureID;
	}

	

	void Sprite::Load()
	{
		m_textureID = G_TextureManager.LoadTexture(m_path);
		GenerateVertices();
	}

	void Sprite::GenerateVertices()
	{
		vector2 pivot = m_size * m_origin;
		vector2 secondPivot = m_size * (vector2(1.0f) - m_origin);	
		

		topLeft = m_position - pivot;
		bottomRight = m_position + secondPivot;
		topRight = vector2(bottomRight.x, topLeft.y);
		bottomLeft = vector2(topLeft.x, bottomRight.y);


		float angle = math.DegreeToRadian(m_angle);

		topLeft =		math.RotatePointAround(topLeft,		m_position, angle);
		topRight =		math.RotatePointAround(topRight,	m_position, angle);
		bottomLeft =	math.RotatePointAround(bottomLeft,	m_position, angle);
		bottomRight =	math.RotatePointAround(bottomRight, m_position, angle);

		m_vertices[0] =	{ topLeft.x,		topLeft.y,		0.0f, m_color.r, m_color.g, m_color.b, m_color.a, 0.0f, 0.0f, 0 };
		m_vertices[1] = { topRight.x,		topRight.y,		0.0f, m_color.r, m_color.g, m_color.b, m_color.a, 1.0f, 0.0f, 0 };
		m_vertices[2] = { bottomRight.x,	bottomRight.y,	0.0f, m_color.r, m_color.g, m_color.b, m_color.a, 1.0f, 1.0f, 0 };
		m_vertices[3] = { bottomLeft.x,		bottomLeft.y,	0.0f, m_color.r, m_color.g, m_color.b, m_color.a, 0.0f, 1.0f, 0 };

		//std::copy(newVertices, newVertices + 4 * FLOATS_PER_VERTEX, m_vertices);
	}
	
	UIVertex Sprite::GetVertex(int id)
	{
		return m_vertices[id];
	}

	void Sprite::Draw()
	{
		GenerateVertices();
		G_SpriteRenderer.DrawSprite(this);
	}

	void Sprite::Draw(vector2 position, vector2 size, Color color = Color(0xFFFFFFFF), float angle = 0)
	{
		m_position = position;
		m_size = size;
		m_color = color;
		m_angle = angle;

		Draw();
	}

	void Sprite::SetOrigin(vector2 origin)
	{
		m_origin = origin;
		GenerateVertices();
	}

	void Sprite::SetColor(Color color)
	{
		m_color = color;
		GenerateVertices();
	}

	void Sprite::SetAngle(float angle)
	{
		m_angle = angle;
		GenerateVertices();
	}
	
}