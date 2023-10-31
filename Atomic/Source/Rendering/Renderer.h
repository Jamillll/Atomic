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

    int windowHeight = 810;
    int windowWidth = 1200;

public:
    GLFWwindow* window;
    bool success = false;
    const char* openGLVersion = "#version 330";

    Renderer();

    void SetGrid(void* data, unsigned int size);

    void DrawCall();

    int Terminate();
};