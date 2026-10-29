#pragma once
#include "ShaderProgram.h"
#include "VAO.h"

class GridObject
{
private:
	ShaderProgram m_shaders;
	VAO m_vao;

public:
	GridObject();
	~GridObject();

	void SetData(void* data, int size);
	void Draw();

};