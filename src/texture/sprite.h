#pragma once
#include "../basic.h"
#include "../buffers/buffers.h"
#include "texture.h"

#define MAX_VERTICES 2048
#define FLOATS_PER_VERTEX 9
#define TOTAL_FLOATS MAX_VERTICES*FLOATS_PER_VERTEX

namespace Core
{
	class Sprite
	{
		vector2 m_position;
		vector2 m_size;
		vector2 m_origin = vector2(0.0f);
		Color m_color;
		float m_angle;
		std::string m_path;
		Texture* m_texture;
		GLfloat m_vertices[4 * FLOATS_PER_VERTEX];

	public:
		Sprite(std::string path, vector2 position, vector2 size, Color color, float angle);

		void SetOrigin(vector2 origin);

		void Load();

		void GenerateVertices();

		GLfloat* GetVertices();
		
		void Draw();

		void Draw(vector2 position, vector2 size, Color color, float angle);
	

	};
}