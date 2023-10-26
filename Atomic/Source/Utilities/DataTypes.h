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