#include "GridObject.h"

GridObject::GridObject()
{
    std::string vertexShaderPath = "Resources\\Shaders\\Vertex.shader";
    std::string fragmentShaderPath = "Resources\\Shaders\\Fragment.shader";
    m_shaders.InitShader(vertexShaderPath, fragmentShaderPath);
}

GridObject::~GridObject()
{
}

void GridObject::SetData(void* data, int size)
{
}

void GridObject::Draw()
{
    glDrawArrays(GL_TRIANGLES, 0, m_vao.m_count);
}
