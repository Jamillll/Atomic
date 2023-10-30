#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Rendering/Renderer.h"
#include "Logic/SimulationHandler.h"
#include <iostream>
#include <windows.h>

int main(void)
{
    Renderer renderer;
    if (!renderer.success) 
        return renderer.Terminate();

    SimulationHandler simulation;
    simulation.baseGrid->RandomGrid();

    renderer.SetGrid(simulation.baseGrid->cellArray, sizeof(Cell) * simulation.baseGrid->cellArrayCount);
    renderer.DrawCall();

    bool paused = false;
    while (!glfwWindowShouldClose(renderer.window))
    {
        simulation.Update();

        renderer.DrawCall();
    }
}