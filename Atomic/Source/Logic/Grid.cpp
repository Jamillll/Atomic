#include "Grid.h"

Grid::Grid()
{
    cellLength = 2.0f / (axisLength);

    float startingY = 1.05f;
    float startingX = -0.95f;

    float currentY = startingY;
    for (int y = 0; y < axisLength; y++)
    {
        float currentX = startingX;
        for (int x = 0; x < axisLength; x++)
        {
            unsigned int index = (y * axisLength) + x;

            cellArray[index].vertices[0].x = currentX;
            cellArray[index].vertices[0].y = currentY;

            cellArray[index].vertices[1].x = currentX + cellLength;
            cellArray[index].vertices[1].y = currentY;

            cellArray[index].vertices[2].x = currentX;
            cellArray[index].vertices[2].y = currentY - cellLength;

            cellArray[index].vertices[3].x = currentX;
            cellArray[index].vertices[3].y = currentY - cellLength;

            cellArray[index].vertices[4].x = currentX + cellLength;
            cellArray[index].vertices[4].y = currentY - cellLength;

            cellArray[index].vertices[5].x = currentX + cellLength;
            cellArray[index].vertices[5].y = currentY;

            for (int i = 0; i < 6; i++)
            {
                cellArray[index].vertices[i].colour.r = 0.0f;
                cellArray[index].vertices[i].colour.g = 0.0f;
                cellArray[index].vertices[i].colour.b = 0.0f;
            }

            currentX += cellLength - (cellLength / 3);
        }

        currentY -= cellLength;
    }
}

void Grid::SetCoordColour(unsigned int x, unsigned int y, Colour colour)
{
    unsigned int index = ((y - 1) * axisLength) + (x - 1);

    for (int i = 0; i < 6; i++)
    {
        cellArray[index].vertices[i].colour.r = colour.r;
        cellArray[index].vertices[i].colour.g = colour.g;
        cellArray[index].vertices[i].colour.b = colour.b;
    }
}

Colour Grid::GetCoordColour(unsigned int x, unsigned int y)
{
    unsigned int index = ((y - 1) * axisLength) + (x - 1);

    return
    {
        cellArray[index].vertices[0].colour.r,
        cellArray[index].vertices[0].colour.g,
        cellArray[index].vertices[0].colour.b,
    };
} 