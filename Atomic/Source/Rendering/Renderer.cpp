#include "Renderer.h"

Renderer::Renderer()
{
    if (!glfwInit()) success = false;

    window = glfwCreateWindow(windowWidth, windowHeight, "Atomic", NULL, NULL);
    if (!window) success = false;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) success = false;

    std::string vertexShaderPath = "Source\\Rendering\\Shaders\\Vertex.shader";
    std::string fragmentShaderPath = "Source\\Rendering\\Shaders\\Fragment.shader";
    shader.InitShader(vertexShaderPath, fragmentShaderPath);

    success = true;
}

void Renderer::SetGrid(void* data, unsigned int size)
{
    vertexBuffer.InitVertexBuffer(data, size);

    //Position Attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, (sizeof(float) * 5), 0);
    glEnableVertexAttribArray(0);
    //Colour Attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, (sizeof(float) * 5), (void*)(sizeof(float) * 2));
    glEnableVertexAttribArray(1);
}

void Renderer::DrawCall()
{
    glClear(GL_COLOR_BUFFER_BIT);

    vertexBuffer.Update();

    glDrawArrays(GL_TRIANGLES, 0, vertexBuffer.count);

    glfwSwapBuffers(window);

    glfwPollEvents();
}

int Renderer::Terminate()
{
    glfwTerminate();
    return -1;
}