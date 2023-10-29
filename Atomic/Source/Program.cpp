#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Rendering/Renderer.h"
#include "Logic/SimulationHandler.h"
#include <iostream>
#include <windows.h>

int main(void)
{
    SimulationHandler simulation;

    Renderer renderer;
    if (!renderer.success) 
        return renderer.Terminate();

    Vertex triangle[3] =
    {
        0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
    };

    simulation.baseGrid->SetCoordColour(3, 2, 1.0f);
    simulation.baseGrid->SetCoordColour(4, 3, 1.0f);
    simulation.baseGrid->SetCoordColour(2, 4, 1.0f);
    simulation.baseGrid->SetCoordColour(3, 4, 1.0f);
    simulation.baseGrid->SetCoordColour(4, 4, 1.0f);
                       
    simulation.baseGrid->SetCoordColour(20, 20, 1.0f);
    simulation.baseGrid->SetCoordColour(21, 20, 1.0f);
    simulation.baseGrid->SetCoordColour(22, 20, 1.0f);

    renderer.SetGrid(simulation.baseGrid->cellArray, sizeof(Cell) * simulation.baseGrid->cellArrayCount);
    renderer.DrawCall();

    bool paused = false;
    while (!glfwWindowShouldClose(renderer.window))
    {
        simulation.Update();

        renderer.DrawCall();

        Sleep(75);
    }
}