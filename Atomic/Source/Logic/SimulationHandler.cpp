#include "SimulationHandler.h"


SimulationHandler::SimulationHandler()
{
	baseGrid = new Grid();
	updatedGrid = new Grid();
	axisLength = baseGrid->axisLength;
}

void SimulationHandler::Update()
{
	if (pauseCheck() == true) return;

	generation++;

	for (int y = 1; y < axisLength + 1; y++)
	{
		for (int x = 1; x < axisLength + 1; x++)
		{
			int neighbours = CheckNeighbours(x, y);
			Colour cellColour = ReturnState(baseGrid->GetCoordColour(x, y), neighbours);

			updatedGrid->SetCoordColour(x, y, cellColour);
		}
	}

	SwapGrids();
}


void SimulationHandler::SetGrid(bool killClear)
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

	generation = 0;
}

void SimulationHandler::RandomGrid()
{
	std::random_device random;
	std::uniform_int_distribution<int> dist(0, 1);

	for (int y = 1; y < axisLength + 1; y++)
	{
		for (int x = 1; x < axisLength + 1; x++)
		{
			Colour colour;

			if (dist(random) == 0) colour = dead;
			else colour = alive;

			baseGrid->SetCoordColour(x, y, colour);
		}
	}

	generation = 0;
}

void SimulationHandler::SetStateColours(Colour newAlive, Colour newDead)
{
	for (int y = 1; y < axisLength + 1; y++)
	{
		for (int x = 1; x < axisLength + 1; x++)
		{
			if (baseGrid->GetCoordColour(x, y) == alive)
			{
				baseGrid->SetCoordColour(x, y, newAlive);
			}
			else
			{
				baseGrid->SetCoordColour(x, y, newDead);
			}
		}
	}

	alive = newAlive;
	dead = newDead;
}

void SimulationHandler::GetStateColours(Colour* returnAlive, Colour* returnDead)
{
	*returnAlive = alive;
	*returnDead = dead;
}

std::string SimulationHandler::GetRuleString()
{
	return birthRule + "/" + surviveRule;
}

void SimulationHandler::SetRuleString(std::string ruleString)
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

void SimulationHandler::SetRuleString(std::string ruleString, Neighbourhood newNeighbourhoodRule)
{
	SetRuleString(ruleString);
	neighbourhoodRule = newNeighbourhoodRule;
}

void SimulationHandler::SwapGrids() { *baseGrid = *updatedGrid; }

bool SimulationHandler::pauseCheck()
{
	if (pauseSimulation)
	{
		if (pauseTimer == 0)
		{
			pauseSimulation = false;
			pauseTimer = pauseTimerDefault;
		}

		else pauseTimer--;

		return true;
	}
	else return false;
}

Colour SimulationHandler::ReturnState(Colour state, unsigned int neighbours)
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

int SimulationHandler::CheckNeighbours(int x, int y)
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