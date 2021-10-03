#pragma once
#include "../basic.h"
#include "../display/window.h"
#include "../texture/sprite.h"
#include "../shaders/ShaderManager.h"

#define MAX_VERTICES 2048
#define FLOATS_PER_VERTEX 9
#define TOTAL_FLOATS MAX_VERTICES*FLOATS_PER_VERTEX

namespace Core
{
	class Renderer
	{
		int MaxBatchSize;
		Window* m_window;
		ShaderManager m_shaderManager;
		std::vector<Sprite*> sprites;
		GLfloat* m_vertices;
		int lastVertex;
		GLuint VAO, VBO;
		int SpritesNum = 0;
	public:

		void Init(Window* window);

		void SubmitVertex(const Vertex& v);

		void SubmitSprite(Sprite* sprite);

		void Flush();

	};
}