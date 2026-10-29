#include "VAO.h"
#include "GL/Glew.h"

VAO::VAO()
{
	glGenBuffers(1, &m_id);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

VAO::~VAO()
{
}

void VAO::SetData(void* data, int size)
{
	m_count = size / sizeof(float);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}

void VAO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}
