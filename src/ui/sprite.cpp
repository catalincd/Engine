#include "sprite.h"
#include "../renderer/SpriteRenderer.h"
#include "../utils/math.h"

extern Core::SpriteRenderer G_SpriteRenderer;


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

		Load();
		GenerateVertices();
	}

	GLuint Sprite::GetTextureID() const
	{
		return m_texture->GetID();
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

	void Sprite::Load()
	{
		m_texture = new Texture(m_path);

		if(FileSystem::GetFileExtension(m_path) == "png")
			m_texture->Load();
		else
			m_texture->LoadJPG();
	}

	void Sprite::GenerateVertices()
	{
		vector2 pivot = m_size * m_origin;
		vector2 secondPivot = m_size * (vector2(1.0f) - m_origin);	
		

		vector2 topLeft = m_position - pivot;
		vector2 bottomRight = m_position + secondPivot;
		vector2 topRight = vector2(bottomRight.x, topLeft.y);
		vector2 bottomLeft = vector2(topLeft.x, bottomRight.y);


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
	
	Vertex Sprite::GetVertices(int id)
	{
		return m_vertices[id];
	}

	void Sprite::SetAngle(float angle)
	{
		m_angle = angle;
		GenerateVertices();
	}

	void Sprite::Draw()
	{
		G_SpriteRenderer.SubmitSprite(this);
	}

	void Sprite::Draw(vector2 position, vector2 size, Color color = Color(0xFFFFFFFF), float angle = 0)
	{
		m_position = position;
		m_size = size;
		m_color = color;
		m_angle = angle;

		GenerateVertices();
		Draw();
	}
	
}