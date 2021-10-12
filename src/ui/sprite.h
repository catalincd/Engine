#pragma once
#include "../basic.h"
#include "../Texture/TextureManager.h"
#include "Element.h"

namespace Core
{
	class Sprite : public Element
	{
	protected:
		vector2 m_position;
		vector2 m_size;
		vector2 m_origin = vector2(0.0f);
		Color m_color;
		float m_angle;
		std::string m_path;
		uint m_textureID;
		UIVertex m_vertices[4];

		vector2 topLeft;
		vector2 bottomLeft;
		vector2 topRight;
		vector2 bottomRight;

	public:
		explicit Sprite(std::string path, vector2 position, vector2 size, Color color, float angle);

		void Load();

		void GenerateVertices();


		UIVertex GetVertex(int id);

		GLuint GetTextureID() const;
		
		void Draw();

		void Draw(vector2 position, vector2 size, Color color, float angle);
	
		void SetOrigin(vector2 origin);
		void SetAngle(float angle);
		void SetColor(Color color);
	};
}