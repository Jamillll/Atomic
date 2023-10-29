#pragma once
#include "Grid.h"
#include <iostream>

class SimulationHandler
{
private:
	const float alive = 1.0f;
	const float dead = 0.0f;

public:
	Grid* baseGrid = new Grid();
	Grid* updatedGrid = new Grid();
	int generation = 0;

private:

	void SwapGrids() { *baseGrid = *updatedGrid; }

	float ReturnState(float state, unsigned int neighbours)
	{
		if (state == alive)
		{
			if (neighbours == 3)
			{
				return alive;
			}
			else if (neighbours == 2)
			{
				return alive;
			}
			else
			{
				return dead;
			}
		}
		else
		{
			if (neighbours == 3)
			{
				return alive;
			}
			else
			{
				return dead;
			}
		}
	}

public:

	void Update()
	{

		generation++;

		int axisLength = baseGrid->axisLength;
		for (int y = 1; y < axisLength + 1; y++)
		{
			for (int x = 1; x < axisLength + 1; x++)
			{
				int neighbours = 0;

				for (int iy = -1; iy < 2; iy++)
				{
					for (int ix = -1; ix < 2; ix++)
					{
						if (ix == 0 && iy == 0)
						{
							continue;
						}

						if (y + iy <= 0 || y + iy > axisLength)
						{
							break;
						}
						else if (x + ix <= 0 || x + ix > axisLength)
						{
							continue;
						}

						if (baseGrid->GetCoordColour(x + ix, y + iy) == alive)
						{
							neighbours++;
						}
					}
				}

				updatedGrid->SetCoordColour(x, y, ReturnState(baseGrid->GetCoordColour(x, y), neighbours));
				//std::cout << "Neighbours: " << neighbours << ", X: " << x << ", Y: " << y << std::endl;
			}
		}

		SwapGrids();
		std::cout << generation << std::endl;
	}
};