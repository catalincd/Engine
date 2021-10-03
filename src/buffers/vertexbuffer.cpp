#include "vertexbuffer.h"

namespace Core
{
	VertexBuffer::VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount)
		:m_count(count), m_componentCount(componentCount)
	{
		glGenBuffers(1, &m_bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GL_FLOAT), data, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


	void VertexBuffer::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
	}

	void VertexBuffer::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	GLuint VertexBuffer::GetComponentCount()
	{
		return m_componentCount;
	}
}