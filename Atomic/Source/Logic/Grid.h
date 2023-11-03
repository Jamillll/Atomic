#pragma once
#include "..\Utilities\DataTypes.h"
#include <random>

class Grid
{
private:
	float cellLength;

public:
	unsigned int axisLength = 400;
	unsigned int cellArrayCount = axisLength * axisLength;
	Cell cellArray[160000]; //640000

public:
	Grid();

	void SetCoordColour(unsigned int x, unsigned int y, Colour colour);
	Colour GetCoordColour(unsigned int x, unsigned int y);
};