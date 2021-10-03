#pragma once
#include "../basic.h"
#include "vertexbuffer.h"

namespace Core
{
	struct Vertex
	{
		vec2 position;
		vec4 color;
		vec2 texturePosition;
		float textureId;
	};

	class VertexArray
	{
		GLuint m_arrayID;
		std::vector<VertexBuffer*> m_vboArray;

	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(VertexBuffer* m_vbo, GLuint index);

		void bind();
		void unbind();
	};
}