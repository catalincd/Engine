#pragma once
#include "../basic.h"
#include "texture.h"



namespace Core
{
	struct Vertex
	{
		float x, y, z;
		float r, g, b, a;
		float tx, ty;
		float ti;
	};

	class Sprite
	{
		vector2 m_position;
		vector2 m_size;
		vector2 m_origin = vector2(0.0f);
		Color m_color;
		float m_angle;
		std::string m_path;
		Texture* m_texture;
		Vertex m_vertices[4];

	public:
		Sprite(std::string path, vector2 position, vector2 size, Color color, float angle);

		void SetOrigin(vector2 origin);

		void Load();

		void GenerateVertices();

		Vertex GetVertices(int id);

		GLuint GetTextureID() const;
		
		void Draw();

		void Draw(vector2 position, vector2 size, Color color, float angle);
	

	};
}