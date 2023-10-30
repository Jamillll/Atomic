#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "VertexBuffer.h"
#include "Shader.h"

class Renderer
{
private:
    VertexBuffer vertexBuffer;
    Shader shader;

    int windowHeight = 900;
    int windowWidth = 900;

public:
    GLFWwindow* window;
    bool success = false;

    Renderer();

    void SetGrid(void* data, unsigned int size);

    void DrawCall();

    int Terminate();
};