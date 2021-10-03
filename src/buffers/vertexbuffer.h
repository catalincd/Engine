#pragma once

#include "../basic.h"

namespace Core
{
	class VertexBuffer
	{
		GLuint m_bufferID;
		GLsizei m_count;
		GLsizei m_componentCount;
	public:

		VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount);


		void bind();
		void unbind();
		GLuint GetComponentCount();
	};
}