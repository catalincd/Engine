#include "renderer.h"
#include "../basic.h"



Core::Renderer G_Renderer;

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

	void Renderer::Init(Window* window)
	{
		m_window = window;
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &MaxBatchSize);
		std::cout << "GL_MAX_TEXTURE_IMAGE_UNITS: " << MaxBatchSize << std::endl;

		m_shaderManager.LoadShaders();

		memset(TextureID, 0, sizeof(TextureID));

		GLuint program = m_shaderManager.GetShaderID("default");
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

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//glBufferData(GL_ARRAY_BUFFER, MAX_VERTICES_BYTES_SIZE, &vertices[0], GL_DYNAMIC_DRAW);
		 
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


	void Renderer::SubmitSprite(Sprite* sprite)
	{


		int offset = SpritesNum * 4;

		TextureID[SpritesNum] = sprite->GetTextureID();

		for (int i = 0; i < 4; i++)
		{
			m_vertices[offset + i] = (sprite->GetVertices(i));
			m_vertices[offset + i].ti = SpritesNum;
		}
		
		SpritesNum++;


		

		

		//std::cout << SpritesNum << std::endl;
	}

	

	void Renderer::Flush()
	{
		float ratio;
		int width, height;
		mat4x4 m, p, mvp;

		glfwGetFramebufferSize(m_window->Get(), &width, &height);
		ratio = width / (float)height;


		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, MAX_VERTICES_BYTES_SIZE, m_vertices, GL_DYNAMIC_DRAW);

		


		//remove this from update
		

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		mat4x4_identity(m);

		mat4x4_ortho(p, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f, -1.0f);
		mat4x4_mul(mvp, p, m);

		glUseProgram(m_shaderManager.GetShaderID("default"));
		m_shaderManager.SetOrtographicMatrix("default", 0.0f, 640.0f, 480.0f, 0.0f, 1.0f, -1.0f);

		glUniform1iv(2, 64, TextureID);

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