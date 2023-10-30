#pragma once

struct Colour
{
	float r, g, b;

	bool operator==(const Colour& target) const
	{
		if (r == target.r && g == target.g && b == target.b)
		{
			return true;
		}

		else return false;
	}
};

struct Vertex
{
	float x, y;
	Colour colour;
};

struct Cell
{
	Vertex vertices[6];
};

enum Neighbourhood
{
	Moore = 0,
	Neumann = 1
};

enum PresetNames
{
	GameofLife,
	Island,
	Gliders,
	Decay,
	AntiLife,
	MazeRunner,
	SquareFractal,
	Geology,
	Infestation
};