#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Rendering/Renderer.h"
#include "Logic/SimulationHandler.h"
#include "Logic/Presets.h"
#include "UI/UIHandler.h"

int main(void)
{
    SimulationHandler simulation;
    Presets::SetPreset(&simulation, GameofLife);

    Renderer renderer;
    if (!renderer.success)
        return renderer.Terminate();

    renderer.SetGrid(simulation.baseGrid->cellArray, sizeof(Cell) * simulation.baseGrid->cellArrayCount);
    renderer.DrawCall();

    UIHandler ui(renderer.window, renderer.openGLVersion, &simulation);

    while (!glfwWindowShouldClose(renderer.window))
    {
        simulation.Update();

        renderer.DrawCall();

        ui.Update(renderer.window);
    }
}