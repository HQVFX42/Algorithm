#include "Map.h"
#include "Helper.h"
#include <iostream>

int GMap1D[MAP_SIZE] =
{
	1, 1, 0, 1, 1,
	1, 0, 0, 0, 1,
	1, 0, 2, 0, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1
};

int GMap2D[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 1, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 1 },
	{ 1, 0, 2, 0, 1 },
	{ 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1 }
};

void PrintMap1D()
{
	SetCursorPosition(0, 0);

	for (size_t i = 0; i < MAP_SIZE; i++)
	{
		switch (GMap1D[i])
		{
		case 0:
			std::cout << " ";
			break;
		case 1:
			std::cout << "#";
			break;
		case 2:
			std::cout << "P";
			break;
		default:
			break;
		}

		if ((i + 1) % MAP_WIDTH == 0)
		{
			std::cout << '\n';
		}
	}
}

void PrintMap2D()
{
	SetCursorPosition(0, 0);
	for (size_t y = 0; y < MAP_HEIGHT; y++)
	{
		for (size_t x = 0; x < MAP_WIDTH; x++)
		{
			switch (GMap2D[y][x])
			{
			case 0:
				std::cout << " ";
				break;
			case 1:
				std::cout << "#";
				break;
			case 2:
				std::cout << "P";
				break;
			default:
				break;
			}
		}
		std::cout << '\n';
	}
}