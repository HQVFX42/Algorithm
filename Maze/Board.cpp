#include "pch.h"
#include "Board.h"
#include "Player.h"

const char* TILE = "бс";

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size, Player* player)
{
	_size = size;
	_player = player;
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

// Generate a maze using the binary tree algorithm
// > Mazes For Programmers
void Board::GenerateMap()
{
	// generate walls
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 or y % 2 == 0)
			{
				_tile[y][x] = ETileType::Wall;
			}
			else
			{
				_tile[y][x] = ETileType::Empty;
			}
		}
	}

	// randomly remove walls right or down
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			// skip wall tiles
			if (x % 2 == 0 or y % 2 == 0)
			{
				continue;
			}

			// exclude end pos
			if (x == _size - 2 and y == _size - 2)
			{
				continue;
			}

			// last row -> remove wall to right
			if (y == _size - 2)
			{
				_tile[y][x + 1] = ETileType::Empty;
				continue;
			}

			// last column -> remove wall to down
			if (x == _size - 2)
			{
				_tile[y + 1][x] = ETileType::Empty;
				continue;
			}

			const int32 randVal = ::rand() % 2;
			if (randVal == 0)
			{
				_tile[y][x + 1] = ETileType::Empty;
			}
			else
			{
				_tile[y + 1][x] = ETileType::Empty;
			}
		}
	}
}

ETileType Board::GetTileType(Pos pos)
{
	if (pos.y < 0 || pos.y >= _size || pos.x < 0 || pos.x >= _size)
	{
		return ETileType::None;
	}

	return _tile[pos.y][pos.x];
}

EConsoleColor Board::GetTileColor(Pos pos)
{
	if (_player and _player->GetPos() == pos)
	{
		return EConsoleColor::Yellow;
	}
	if (GetEndPos() == pos)
	{
		return EConsoleColor::Blue;
	}

	ETileType tileType = GetTileType(pos);

	switch (tileType)
	{
	case ETileType::None:
		break;
	case ETileType::Empty:
		return EConsoleColor::Green;
	case ETileType::Wall:
		return EConsoleColor::Red;
	default:
		break;
	}
	return EConsoleColor::White;
}
