#include <iostream>
#include "Helper.h"
#include "GameCoding.h"

const int MAP_WIDTH = 5;
const int MAP_HEIGHT = 5;
const int MAP_SIZE = MAP_WIDTH * MAP_HEIGHT;

int GMap1D[MAP_SIZE] =
{
	1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 0, 2, 0, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1
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

int main()
{
	SetCursorOnOff(false);

	PrintMap1D();

	while (true)
	{

	}
}
