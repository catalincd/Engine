#pragma once

#include "../basic.h"

namespace Core
{
	class IndexBuffer
	{
		GLuint m_bufferID;
		GLsizei m_count;
	public:

		IndexBuffer(GLushort* data, GLsizei count);


		void bind();
		void unbind();
		GLsizei GetCount();
	};
}