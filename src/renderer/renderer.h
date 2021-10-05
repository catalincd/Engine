#pragma once
#include "../basic.h"
#include "../display/window.h"
#include "../texture/sprite.h"
#include "../shaders/ShaderManager.h"

#define MAX_VERTICES 2048
#define FLOATS_PER_VERTEX 10
#define TOTAL_FLOATS MAX_VERTICES*FLOATS_PER_VERTEX

namespace Core
{
	class Renderer
	{
		int MaxBatchSize;
		Window* m_window;
		ShaderManager m_shaderManager;
		std::vector<Sprite*> sprites;
		Vertex m_vertices[2048];
		
		int MAX_VERTICES_BYTES_SIZE;
		int lastVertex;
		GLuint VAO, VBO, IBO;
		int SpritesNum = 0;
		GLushort indices[1024 * 6];
		int TextureID[1024];
		GLint samplersLocation;
		const uint defaultIndices[6] = { 0, 1, 2, 2, 3, 0 };
	public:

		void Init(Window* window);

		void SubmitSprite(Sprite* sprite);

		void Flush();

	};
}