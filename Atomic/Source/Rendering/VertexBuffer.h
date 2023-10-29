#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class VertexBuffer
{
public:
	unsigned int count;

private:
	unsigned int id;
	void* data;
	unsigned int size;

public:
	VertexBuffer() { }

	VertexBuffer(void* data, unsigned int inputSize)
	{
		InitVertexBuffer(data, inputSize);
	}

	void InitVertexBuffer(void* inputData, unsigned int inputSize)
	{
		data = inputData;
		size = inputSize;
		count = size / sizeof(float);

		glGenBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
	}

	void ChangeData(void* inputData) { data = inputData; }

	void Update() { glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW); }
};