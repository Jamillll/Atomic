#pragma once

struct Vertex
{
	float x, y;
	float r, g, b;
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

};