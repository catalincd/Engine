#include "Renderer.h"
#include "../shaders/ShaderManager.h"
#include "../display/Window.h"
#include "../World/World.h"

Core::Renderer G_Renderer;
extern Core::Window G_Window;
extern Core::ShaderManager G_ShaderManager;
extern Core::World G_World;

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

		LocationColor = glGetUniformLocation(ShaderID, "vColor");
		LocationLightsNum = glGetUniformLocation(ShaderID, "LightsNum");
		LocationResolution = glGetUniformLocation(ShaderID, "Resolution");
		LocationAmbient = glGetUniformLocation(ShaderID, "Ambient"); 
		LocationSpecularScale = glGetUniformLocation(ShaderID, "SpecularScale"); 
		LocationApplyLightType = glGetUniformLocation(ShaderID, "ApplyLightType");

		for (int i = 0; i < MAX_LIGHTS; i++)
		{
			std::string iStr = "Lights[" + std::to_string(i) + "].";
	
			LocationLightFalloffs[i] = glGetUniformLocation(ShaderID, (iStr + "Falloff").c_str());
			LocationLightPositions[i] = glGetUniformLocation(ShaderID, (iStr + "Position").c_str());
			LocationLightColors[i] = glGetUniformLocation(ShaderID, (iStr + "Color").c_str());

			std::cout << LocationLightColors[i] << ' ' << LocationLightFalloffs[i] << ' ' << LocationLightPositions[i] << '\n';
		}

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
		Color ambient = G_World.GetAmbientColor();

		EntityVertex vertices[4];
		for (int i = 0; i < 4; i++)
		{
			vertices[i] = entity.GetVertex(i);
		}

		vector2 WindowSize = G_Window.GetWindowSize();

		glUseProgram(ShaderID);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, entity.GetDiffuseID());
		glUniform1i(LocationDiffuse, 0);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, entity.GetNormalID());
		glUniform1i(LocationNormal, 1);

		glActiveTexture(GL_TEXTURE0 + 2);
		glBindTexture(GL_TEXTURE_2D, entity.GetSpecularID());
		glUniform1i(LocationSpecular, 2);

		Color color = entity.GetColor();
		glUniform4f(LocationColor, color.r, color.g, color.b, color.a);

		LightStack lightStack = G_World.GetLights(entity);
		for (int i = 0; i < lightStack.LightCount; i++)
		{
			vector4 c = lightStack.Lights[i].Color;
			glUniform4f(LocationLightColors[i], c.x, c.y, c.z, c.w);

			vector3 p = lightStack.Lights[i].Position;
			glUniform3f(LocationLightPositions[i], p.x, p.y, p.z);

			vector3 f = lightStack.Lights[i].Falloff;
			glUniform3f(LocationLightFalloffs[i], f.x, f.y, f.z);
		}

		
		glUniform1f(LocationSpecularScale, entity.GetSpacularScale());
		glUniform1i(LocationApplyLightType, entity.GetApplyLightType());
		glUniform1i(LocationLightsNum, lightStack.LightCount); 
		glUniform2f(LocationResolution, WindowSize.x, WindowSize.y);
		glUniform4f(LocationAmbient, ambient.r, ambient.g, ambient.b, ambient.a);
		
		G_ShaderManager.SetOrthographicMatrix("entity", 0.0f, WindowSize.x, WindowSize.y, 0.0f, 1.0f, -1.0f);
		
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
		
	}

	void Renderer::Update()
	{
		Color bg = G_World.GetBackgroundColor();
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(bg.r, bg.g, bg.b, bg.a);
	}
}