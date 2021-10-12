#include "SpriteRenderer.h"
#include "../basic.h"


extern Core::Window G_Window;
extern Core::ShaderManager G_ShaderManager;
Core::SpriteRenderer G_SpriteRenderer;

namespace Core
{
	void printVertexArray(GLfloat* arr)
	{
		for (int i = 0; i < 4 * FLOATS_PER_VERTEX; i++)
		{
			if (!(i % FLOATS_PER_VERTEX))
				std::cout << std::endl;
			std::cout << arr[i] << ", ";
		}
		std::cout << std::endl;
	}

	void SpriteRenderer::Initialize()
	{
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &MaxBatchSize);
		std::cout << "GL_MAX_TEXTURE_IMAGE_UNITS: " << MaxBatchSize << std::endl;

		memset(TextureID, 0, sizeof(TextureID));

		GLuint program = G_ShaderManager.GetShaderID("default");
		glUseProgram(program);
		samplersLocation = glGetUniformLocation(program, "u_Textures");
		

		SpritesNum = 0;
		int vertexSize = sizeof(float) * 10;
		MAX_VERTICES_BYTES_SIZE = vertexSize * 2048;



		for (int i = 0; i < 1024; i++)
		{
			for (int t = 0; t < 6; t++)
			{
				indices[i * 6 + t] = defaultIndices[t] + 4 * i;
			}
		}

		for (int i = 0; i < 1024; i++)
		{
			TextureArray[i] = i;
		}

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		 
		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, vertexSize, (void*)(sizeof(float) * 3));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, vertexSize, (void*)(sizeof(float) * 7));

		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, vertexSize, (void*)(sizeof(float) * 9));
	}


	void SpriteRenderer::SubmitSprite(Sprite* sprite)
	{
		int offset = SpritesNum * 4;

		TextureID[SpritesNum] = sprite->GetTextureID();

		for (int i = 0; i < 4; i++)
		{
			m_vertices[offset + i] = (sprite->GetVertex(i));
			m_vertices[offset + i].ti = SpritesNum;
		}
		
		SpritesNum++;
	}

	

	void SpriteRenderer::Flush()
	{
		mat4x4 m, p, mvp;
		vector2 WindowSize = G_Window.GetWindowSize();

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, MAX_VERTICES_BYTES_SIZE, m_vertices, GL_DYNAMIC_DRAW);

		glViewport(0, 0, WindowSize.x, WindowSize.y);
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		
		glUseProgram(G_ShaderManager.GetShaderID("default"));
		
		G_ShaderManager.SetOrthographicMatrix("default", 0.0f, WindowSize.x, WindowSize.y, 0.0f, 1.0f, -1.0f);
		
		glUniform1iv(samplersLocation, 32, TextureArray);
		
		for (int i = 0; i < SpritesNum; i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, TextureID[i]);
		}

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6 * SpritesNum, GL_UNSIGNED_SHORT, 0);

		SpritesNum = 0;
	}
}