#pragma once
#include "..\Utilities\DataTypes.h"

class Grid
{
private:
	unsigned int axisLength = 80;
	float cellSize;
	float gapSize;

public:
	unsigned int cellArrayCount = axisLength * axisLength;
	Cell cellArray[6400];

public:
	Grid();
	void SetCoordColour(unsigned int x, unsigned int y, float colour);
	void SetCoordColour(unsigned int index, float colour);
	void SetCoordColour(unsigned int x, unsigned int y, float r, float g, float b);
	void SetCoordColour(unsigned int index, float r, float g, float b);
};