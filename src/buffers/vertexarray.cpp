#include "vertexarray.h"

namespace Core
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_arrayID);
	}

	VertexArray::~VertexArray()
	{
		for (int i = 0; i < m_vboArray.size(); i++)
		{
			delete m_vboArray[i];
		}
	}

	void VertexArray::bind()
	{
		glBindVertexArray(m_arrayID);
	}

	void VertexArray::unbind()
	{
		glBindVertexArray(0);
	}

	void VertexArray::AddBuffer(VertexBuffer* m_vbo, GLuint index)
	{
		bind();
		m_vbo->bind();
		
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, m_vbo->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

		m_vbo->unbind();
		unbind();

		m_vboArray.push_back(m_vbo);
	}
}
