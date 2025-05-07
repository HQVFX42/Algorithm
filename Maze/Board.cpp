#include "pch.h"
#include "Board.h"

const char* TILE = "бс";

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size)
{
	_size = size;
	GenerateMap();
}

void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);

	for (int32 y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			EConsoleColor color = GetTileColor(Pos(y, x));
			ConsoleHelper::SetCursorColor(color);
			std::cout << TILE;
		}

		std::cout << "\n";
	}
}

void Board::GenerateMap()
{
}

ETileType Board::GetTileType(Pos pos)
{
	return ETileType::None;
}

EConsoleColor Board::GetTileColor(Pos pos)
{
	return EConsoleColor::Red;
}
