#pragma once
#include "Grid.h"
#include "..\Utilities\DataTypes.h"
#include <iostream>
#include <string>

class SimulationHandler
{
private:
	const float alive = 1.0f;
	const float dead = 0.0f;
	int axisLength;

	std::string birthRule = "B3";
	std::string surviveRule = "S23";
	Neighbourhood neighbourhoodRule = Moore;

public:
	Grid* baseGrid = nullptr;
	Grid* updatedGrid = nullptr;
	int generation = 0;

public:
	SimulationHandler()
	{
		baseGrid = new Grid();
		updatedGrid = new Grid();
		axisLength = baseGrid->axisLength;
	}

	void setRuleString(std::string ruleString)
	{
		birthRule = "";
		surviveRule = "";

		bool birthRuleFinished = false;
		for (int i = 0; i < ruleString.size(); i++)
		{
			if (ruleString[i] == '/' || ruleString[i] == '\\')
			{
				birthRuleFinished = true;
				continue;
			}

			if (!birthRuleFinished)
			{
				birthRule += ruleString[i];
			}
			else 
			{
				surviveRule += ruleString[i];
			}
		}
	}

	void setRuleString(std::string ruleString, Neighbourhood newNeighbourhoodRule)
	{
		setRuleString(ruleString);
		neighbourhoodRule = newNeighbourhoodRule;
	}

	void Update()
	{
		generation++;

		for (int y = 1; y < axisLength + 1; y++)
		{
			for (int x = 1; x < axisLength + 1; x++)
			{
				int neighbours = CheckNeighbours(x, y);
				float cellColour = ReturnState(baseGrid->GetCoordColour(x, y), neighbours);

				updatedGrid->SetCoordColour(x, y, cellColour);
				//std::cout << "Neighbours: " << neighbours << ", X: " << x << ", Y: " << y << std::endl;
			}
		}

		SwapGrids();
		std::cout << generation << std::endl;
	}

private:
	void SwapGrids() { *baseGrid = *updatedGrid; }

	float ReturnState(float state, unsigned int neighbours)
	{
		if (state == dead)
		{
			for (int i = 1; i < birthRule.size(); i++)
			{
				if (neighbours == (int)birthRule[i] - 48)
				{
					return alive;
				}
			}
		}
		else
		{
			for (int i = 1; i < surviveRule.size(); i++)
			{
				if (neighbours == (int)surviveRule[i] - 48)
				{
					return alive;
				}
			}
		}

		return dead;
	}

	int CheckNeighbours(int x, int y)
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

				if (neighbourhoodRule == Neumann)
				{
					if (ix == -1 && iy == -1)
					{
						continue;
					}
					else if (ix == 1 && iy == -1)
					{
						continue;
					}
					else if (ix == -1 && iy == 1)
					{
						continue;
					}
					else if (ix == 1 && iy == 1)
					{
						continue;
					}
				}

				if (baseGrid->GetCoordColour(x + ix, y + iy) == alive)
				{
					neighbours++;
				}
			}
		}

		return neighbours;
	}
};