#include "TextRenderer.h"
#include "../shaders/ShaderManager.h"


extern Core::ShaderManager G_ShaderManager;
extern Core::Window G_Window;
Core::TextRenderer G_TextRenderer;

namespace Core
{
	void TextRenderer::Initialize()
	{
		for (int i = 0; i < 1024; i++)
		{
			for (int t = 0; t < 6; t++)
			{
				indices[i * 6 + t] = defaultIndices[t] + 4 * i;
			}
		}

		int vertexSize = sizeof(float) * 5;

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
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vertexSize, (void*)(sizeof(float) * 3));

		SamplerLocation = glGetUniformLocation(G_ShaderManager.GetShaderID("defaultText"), "u_Texture");
		ColorLocation = glGetUniformLocation(G_ShaderManager.GetShaderID("defaultText"), "u_Color");
		std::cout << "SamplerLocation: " << SamplerLocation << std::endl;

	}

	void TextRenderer::Draw(Text text)
	{
		Texture* texture = text.GetFont().GetTexture();
		
		
		int Length = text.GetLength();
		Color color = text.GetColor();

		for (int i = 0; i < 4 * Length; i++)
		{
			m_vertices[i] = text.GetVertex(i);
		}
		
		vector2 WindowSize = G_Window.GetWindowSize();
		glViewport(0, 0, WindowSize.x, WindowSize.y);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, (20 * Length) * sizeof(float), m_vertices, GL_DYNAMIC_DRAW);



		glUseProgram(G_ShaderManager.GetShaderID("defaultText"));
		G_ShaderManager.SetOrthographicMatrix("defaultText", 0.0f, WindowSize.x, WindowSize.y, 0.0f, 1.0f, -1.0f);

		texture->Bind(1);
		glUniform1i(SamplerLocation, 1);
		glUniform4f(ColorLocation, color.r, color.g, color.b, color.a);
		
		glDrawElements(GL_TRIANGLES, 6 * Length, GL_UNSIGNED_SHORT, 0);

		texture->Unbind(1);
	}
}