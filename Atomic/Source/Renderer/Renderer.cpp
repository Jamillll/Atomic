#include "Renderer.h"

Renderer::Renderer()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	std::string vertexShaderPath = "Resources\\Shaders\\Vertex.shader";
	std::string fragmentShaderPath = "Resources\\Shaders\\Fragment.shader";
	m_shaders.InitShader(vertexShaderPath, fragmentShaderPath);
}

Renderer::~Renderer()
{
}

void Renderer::SetGrid(int xWidth, int yWidth, void* data)
{
	glBufferData(GL_ARRAY_BUFFER, (sizeof(float) * 12) * 2500, data, GL_DYNAMIC_DRAW);
}

void Renderer::Draw()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 15000);
}
