#include "Renderer.h"
#include "../shaders/ShaderManager.h"
#include "../display/Window.h"

Core::Renderer G_Renderer;
extern Core::Window G_Window;
extern Core::ShaderManager G_ShaderManager;

#define MAX_ENTITIES 1024
#define MAX_VERTICES MAX_ENTITIES * 4

namespace Core
{
	void Renderer::Initialize()
	{
		ShaderID = G_ShaderManager.GetShaderID("entity");
		glUseProgram(ShaderID);

		LocationDiffuse = glGetUniformLocation(ShaderID, "DiffuseMap");
		LocationSpecular = glGetUniformLocation(ShaderID, "SpecularMap");
		LocationNormal = glGetUniformLocation(ShaderID, "NormalMap"); 
		LocationColor = glGetUniformLocation(ShaderID, "Color");

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(EntityVertex), (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(EntityVertex), (void*)(sizeof(float) * 3));
	}

	void Renderer::DrawEntity(const Entity& entity)
	{
		EntityVertex vertices[4];
		for (int i = 0; i < 4; i++)
		{
			vertices[i] = entity.GetVertex(i);
		}

		vector2 WindowSize = G_Window.GetWindowSize();

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, entity.GetDiffuseID());

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, entity.GetSpecularID());

		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, entity.GetNormalID());

		Color color = entity.GetColor();
		glUniform4f(LocationColor, color.r, color.g, color.b, color.a);
		
		glUseProgram(ShaderID);
		G_ShaderManager.SetOrthographicMatrix("entity", 0.0f, WindowSize.x, WindowSize.y, 0.0f, 1.0f, -1.0f);
		
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
		
	}

	void Renderer::Update()
	{

	}
}