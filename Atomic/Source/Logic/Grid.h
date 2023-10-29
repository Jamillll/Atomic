#pragma once
#include "..\Utilities\DataTypes.h"

class Grid
{
private:
	float cellSize;
	float gapSize;

public:
	unsigned int axisLength = 1000;
	unsigned int cellArrayCount = axisLength * axisLength;
	Cell cellArray[1000000];

public:
	Grid();

	void SetCoordColour(unsigned int x, unsigned int y, float colour);
	void SetCoordColour(unsigned int x, unsigned int y, float r, float g, float b);
	float GetCoordColour(unsigned int x, unsigned int y);
};