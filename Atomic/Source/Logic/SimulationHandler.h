#pragma once
#include "Grid.h"
#include "..\Utilities\DataTypes.h"
#include <iostream>
#include <string>

class SimulationHandler
{
private:
	Colour alive = { 1.0f, 1.0f, 1.0f };
	Colour dead = { 0.0f, 0.0f, 0.0f };
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

	void SetGrid(bool killClear)
	{
		for (int i = 0; i < baseGrid->cellArrayCount; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (killClear)
				{
					baseGrid->cellArray[i].vertices[j].colour = dead;
				}
				else
				{
					baseGrid->cellArray[i].vertices[j].colour = alive;
				}
			}
		}
	}

	void RandomGrid()
	{
		std::random_device random;
		std::uniform_int_distribution<int> dist(0, 1);

		for (int i = 0; i < baseGrid->cellArrayCount; i++)
		{
			Colour colour;

			if (dist(random) == 0) colour = dead;
			else colour = alive;

			for (int j = 0; j < 6; j++)
			{
				baseGrid->cellArray[i].vertices[j].colour = colour;
			}
		}
	}

	void SetStateColours(Colour newAlive, Colour newDead)
	{
		alive = newAlive;
		dead = newDead;
	}

	void SetRuleString(std::string ruleString)
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

	void SetRuleString(std::string ruleString, Neighbourhood newNeighbourhoodRule)
	{
		SetRuleString(ruleString);
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
				Colour cellColour = ReturnState(baseGrid->GetCoordColour(x, y), neighbours);

				updatedGrid->SetCoordColour(x, y, cellColour);
				//std::cout << "Neighbours: " << neighbours << ", X: " << x << ", Y: " << y << std::endl;
			}
		}

		SwapGrids();
		std::cout << generation << std::endl;
	}

private:
	void SwapGrids() { *baseGrid = *updatedGrid; }

	Colour ReturnState(Colour state, unsigned int neighbours)
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