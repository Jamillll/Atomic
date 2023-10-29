#include "Grid.h"

Grid::Grid()
{
    cellSize = 2.0 / (axisLength + (axisLength / 10));
    gapSize = cellSize / 10;

    float currentY = 1.0f - gapSize;
    for (int y = 0; y < axisLength; y++)
    {
        float currentX = -1.0f + gapSize;
        for (int x = 0; x < axisLength; x++)
        {
            unsigned int index = (y * axisLength) + x;

            cellArray[index].vertices[0].x = currentX;
            cellArray[index].vertices[0].y = currentY;

            cellArray[index].vertices[1].x = currentX + cellSize;
            cellArray[index].vertices[1].y = currentY;

            cellArray[index].vertices[2].x = currentX;
            cellArray[index].vertices[2].y = currentY - cellSize;

            cellArray[index].vertices[3].x = currentX;
            cellArray[index].vertices[3].y = currentY - cellSize;

            cellArray[index].vertices[4].x = currentX + cellSize;
            cellArray[index].vertices[4].y = currentY - cellSize;

            cellArray[index].vertices[5].x = currentX + cellSize;
            cellArray[index].vertices[5].y = currentY;

            for (int i = 0; i < 6; i++)
            {
                cellArray[index].vertices[i].r = 0.0f;
                cellArray[index].vertices[i].g = 0.0f;
                cellArray[index].vertices[i].b = 0.0f;
            }

            currentX += cellSize + gapSize;
        }

        currentY -= cellSize + gapSize;
    }
}

void Grid::SetCoordColour(unsigned int x, unsigned int y, float colour)
{
    unsigned int index = ((y - 1) * axisLength) + (x - 1);

    for (int i = 0; i < 6; i++)
    {
        cellArray[index].vertices[i].r = colour;
        cellArray[index].vertices[i].g = colour;
        cellArray[index].vertices[i].b = colour;
    }
}

void Grid::SetCoordColour(unsigned int x, unsigned int y, float r, float g, float b)
{
    unsigned int index = ((y - 1) * axisLength) + (x - 1);

    for (int i = 0; i < 6; i++)
    {
        cellArray[index].vertices[i].r = r;
        cellArray[index].vertices[i].g = g;
        cellArray[index].vertices[i].b = b;
    }
}

float Grid::GetCoordColour(unsigned int x, unsigned int y)
{
    unsigned int index = ((y - 1) * axisLength) + (x - 1);

    return cellArray[index].vertices[0].r;
}