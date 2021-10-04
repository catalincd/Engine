#include "renderer.h"
#include "../basic.h"
#include "../buffers/buffers.h"


Core::Renderer G_Renderer;

namespace Core
{
	void printVertexArray(GLfloat* arr)
	{
		for (int i = 0; i < 36; i++)
		{
			if (!(i % 9))
				std::cout << std::endl;
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;
	}

	void Renderer::Init(Window* window)
	{
		m_window = window;
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &MaxBatchSize);
		std::cout << "GL_MAX_TEXTURE_IMAGE_UNITS: " << MaxBatchSize << std::endl;

		m_shaderManager.LoadShaders();


		

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 1024, m_vertices, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, position));

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, color));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, texturePosition));

		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, textureId));

		m_vertices = new GLfloat[TOTAL_FLOATS];

		for (int i = 0; i < 1024; i++)
		{
			for (int t = 0; t < 6; t++)
			{
				indices[i * 6 + t] = defaultIndices[t] + 4 * i;
			}
		}

		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
	}


	void Renderer::SubmitSprite(Sprite* sprite)
	{



		GLfloat* vertices = sprite->GetVertices();
		printVertexArray(vertices);
		std::copy(vertices, vertices + 36, m_vertices+lastVertex);

		lastVertex += 36;
		SpritesNum++;
	}

	

	void Renderer::Flush()
	{
		

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * 36 * SpritesNum, m_vertices);
		
		int width, height;
		glfwGetFramebufferSize(m_window->Get(), &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(m_shaderManager.GetShaderID("default"));
		m_shaderManager.SetOrtographicMatrix("default", 0.0f, 640.0f, 480.0f, 0.0f, 1.0f, -1.0f);



		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6 * SpritesNum, GL_UNSIGNED_SHORT, 0);

		SpritesNum = 0;
		lastVertex = 0;
		delete m_vertices;
		m_vertices = new GLfloat[TOTAL_FLOATS];
	}
}