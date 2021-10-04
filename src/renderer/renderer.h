#pragma once
#include "../basic.h"
#include "../display/window.h"
#include "../texture/sprite.h"
#include "../shaders/ShaderManager.h"



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
		GLuint VAO, VBO, IBO;
		int SpritesNum = 0;
		uint indices[1024 * 6];
		const uint defaultIndices[6] = { 0, 1, 2, 2, 3, 0 };
	public:

		void Init(Window* window);

		void SubmitSprite(Sprite* sprite);

		void Flush();

	};
}