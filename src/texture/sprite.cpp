#include "sprite.h"
#include "../renderer/renderer.h"
#include "../buffers/buffers.h"
#include <math.h>

extern Core::Renderer G_Renderer;


namespace Core
{
	

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

	void Sprite::SetOrigin(vector2 origin)
	{
		m_origin = origin;
	}

	void Sprite::Load()
	{
		m_texture = new Texture(m_path);
		m_texture->Load();
	}

	void Sprite::GenerateVertices()
	{
		float angleSin = sin(m_angle);
		float angleCos = cos(m_angle);
		vector2 pivot = m_size * m_origin;
		vector2 secondPivot = m_size * (vector2(1.0f) - m_origin);
		//vector2 absolute_position = m_position - vector2(pivot.x * angleCos - pivot.y * angleSin, pivot.x * angleSin + pivot.y * angleCos);
		//vector2 absolute_position_complete = m_position + vector2(secondPivot.x * angleCos - secondPivot.y * angleSin, secondPivot.x * angleSin + secondPivot.y * angleCos);
	
		

		vector2 absolute_position = m_position - pivot;
		vector2 absolute_position_complete = m_position + secondPivot;

		std::cout << "X:" << absolute_position.x << "Y:" << absolute_position.y << std::endl;

		float id = m_texture->GetID();

		GLfloat newVertices[] = 
		{   absolute_position.x,		  absolute_position.y, m_color.r, m_color.g, m_color.b, m_color.a, 0.0f, 0.0f, id,
			absolute_position_complete.x, absolute_position.y, m_color.r, m_color.g, m_color.b, m_color.a, 0.0f, 1.0f, id,
			absolute_position_complete.x, absolute_position_complete.y, m_color.r, m_color.g, m_color.b, m_color.a, 1.0f, 1.0f, id,
			absolute_position.x,		  absolute_position_complete.y, m_color.r, m_color.g, m_color.b, m_color.a, 1.0f, 0.0f, id};

		std::copy(newVertices, newVertices + 36, m_vertices);
	}
	
	GLfloat* Sprite::GetVertices()
	{
		return m_vertices;
	}


	void Sprite::Draw()
	{
		G_Renderer.SubmitSprite(this);
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