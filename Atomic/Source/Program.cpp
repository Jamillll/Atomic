#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Rendering/Renderer.h"
#include "Logic/SimulationHandler.h"
#include "Logic/Presets.h"

int main(void)
{
    Renderer renderer;
    if (!renderer.success) 
        return renderer.Terminate();

    SimulationHandler simulation;
    Presets::SetPreset(&simulation, Infestation);

    renderer.SetGrid(simulation.baseGrid->cellArray, sizeof(Cell) * simulation.baseGrid->cellArrayCount);
    renderer.DrawCall();

    while (!glfwWindowShouldClose(renderer.window))
    {
        simulation.Update();

        renderer.DrawCall();
    }
}