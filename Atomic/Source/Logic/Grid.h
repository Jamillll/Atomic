#pragma once
#include "..\Utilities\DataTypes.h"
#include <random>

class Grid
{
private:
	float cellSize;
	float gapSize;

public:
	unsigned int axisLength = 900;
	unsigned int cellArrayCount = axisLength * axisLength;
	Cell cellArray[810000]; //810000

public:
	Grid();

	void RandomGrid();
	void SetCoordColour(unsigned int x, unsigned int y, float colour);
	void SetCoordColour(unsigned int x, unsigned int y, float r, float g, float b);
	float GetCoordColour(unsigned int x, unsigned int y);
};