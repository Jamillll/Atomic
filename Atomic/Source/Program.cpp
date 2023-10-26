#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Rendering/Renderer.h"
#include "Logic/Grid.h"
#include <iostream>

int main(void)
{
    Grid grid;

    Renderer renderer;
    if (!renderer.success) 
        return renderer.Terminate();

    renderer.SetGrid(grid.cellArray, sizeof(Cell) * grid.cellArrayCount);

    while (!glfwWindowShouldClose(renderer.window))
    {
        

        renderer.DrawCall();
    }
}