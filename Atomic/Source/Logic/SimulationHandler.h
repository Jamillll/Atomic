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

	const int pauseTimerDefault = 20;
	int pauseTimer = pauseTimerDefault;

public:
	Grid* baseGrid = nullptr;
	Grid* updatedGrid = nullptr;
	int generation = 0;
	bool pauseSimulation = false;

public:
	SimulationHandler();
	void Update();
	void SetGrid(bool killClear);
	void RandomGrid();
	void SetStateColours(Colour newAlive, Colour newDead);
	void GetStateColours(Colour* returnAlive, Colour* returnDead);
	std::string GetRuleString();
	void SetRuleString(std::string ruleString);
	void SetRuleString(std::string ruleString, Neighbourhood newNeighbourhoodRule);

private:
	void SwapGrids();
	bool pauseCheck();
	Colour ReturnState(Colour state, unsigned int neighbours);
	int CheckNeighbours(int x, int y);
};