#pragma once
#include "../basic.h"
#include "../display/window.h"
#include "../ui/sprite.h"
#include "../shaders/ShaderManager.h"

#define MAX_VERTICES 2048
#define FLOATS_PER_VERTEX 10
#define TOTAL_FLOATS MAX_VERTICES*FLOATS_PER_VERTEX

namespace Core
{
	class SpriteRenderer
	{
		int MAX_VERTICES_BYTES_SIZE;
		int lastVertex;
		int SpritesNum = 0;
		int MaxBatchSize;

		//Containers
		std::vector<Sprite*> sprites;
		Vertex m_vertices[2048];
		GLuint VAO, VBO, IBO;
		//IBO
		GLushort indices[1024 * 6];
		const uint defaultIndices[6] = { 0, 1, 2, 2, 3, 0 };
		//Samplers
		int TextureID[1024];
		int TextureArray[1024];
		GLint samplersLocation;
		
	public:

		void Initialize();

		void SubmitSprite(Sprite* sprite);

		void Flush();

	};
}