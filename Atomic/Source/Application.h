#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Renderer/Renderer.h"

struct vertex
{
	float x, y;
};

struct cell
{
	vertex vertices[6];
};

class Application
{
private:
	bool m_isRunning = false;

	GLFWwindow* m_window = nullptr;
	Renderer* m_renderer = nullptr;

public:
	Application();
	~Application();

	void Run();
};