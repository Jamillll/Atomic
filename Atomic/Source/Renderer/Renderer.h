#pragma once
#include "GL/glew.h"
//#include "GridObject.h"
#include "ShaderProgram.h"

/*
	The renderer needs to have:
	VBO created when the grid is set
	Shader Program created and stored with this to allow for future features where shaders are changed

	Grid object that holds its VBO and Shader Program
*/

class Renderer
{
private:
	//GridObject* m_currentGrid = nullptr;

	unsigned int vao = 0;
	ShaderProgram m_shaders;

public:
	Renderer();
	~Renderer();

	void SetGrid(int xWidth, int yWidth, void* data);
	void Draw();

};