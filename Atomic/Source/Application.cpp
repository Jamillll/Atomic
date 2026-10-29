#include "Application.h"
#include <assert.h>

#include <array>

Application::Application()
{
    // Window Set up
    assert(glewInit());
    assert(glfwInit());

    m_window = glfwCreateWindow(640, 480, "Atomic", NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);

    glClearColor(0.24f, 0.24f, 0.24f, 1.0f);

    // Temp Grid Data
    std::array<cell, 2500> tempGrid;

    float cellLength = 2.0f / (50);

    float startingY = 1.05f;
    float startingX = -0.95f;

    float currentY = startingY;
    for (int y = 0; y < 50; y++)
    {
        float currentX = startingX;
        for (int x = 0; x < 50; x++)
        {
            unsigned int index = (y * 50) + x;

            tempGrid[index].vertices[0].x = currentX;
            tempGrid[index].vertices[0].y = currentY;

            tempGrid[index].vertices[1].x = currentX + cellLength;
            tempGrid[index].vertices[1].y = currentY;

            tempGrid[index].vertices[2].x = currentX;
            tempGrid[index].vertices[2].y = currentY - cellLength;

            tempGrid[index].vertices[3].x = currentX;
            tempGrid[index].vertices[3].y = currentY - cellLength;

            tempGrid[index].vertices[4].x = currentX + cellLength;
            tempGrid[index].vertices[4].y = currentY - cellLength;

            tempGrid[index].vertices[5].x = currentX + cellLength;
            tempGrid[index].vertices[5].y = currentY;

            currentX += cellLength - (cellLength / 3);
        }

        currentY -= cellLength;
    }

    // Setting up the renderer
    m_renderer = new Renderer();
    m_renderer->SetGrid(50, 50, tempGrid.data());
}

Application::~Application()
{
    glfwTerminate();
}

void Application::Run()
{
	m_isRunning = true;

	while (m_isRunning)
	{
        if (glfwWindowShouldClose(m_window)) m_isRunning = false;

        m_renderer->Draw();

        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(m_window);

        glfwPollEvents();
	}
}
