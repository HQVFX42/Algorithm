#pragma once

#include "ConsoleHelper.h"

// #define MAX 100�� �� ������� �ʴ´�
// const int MAX 100 ��� ����� �� �ִ� ���
enum
{
	BOARD_MAX_HEIGHT = 100,
	BOARD_MAX_WIDTH = 100,
};

enum class ETileType
{
	None = 0,
	Empty,
	Wall,
};

class Board
{
public:
	Board();
	~Board();

	void Init(int32 size);
	void Render();

	void GenerateMap();
	ETileType GetTileType(Pos pos);
	EConsoleColor GetTileColor(Pos pos);

	Pos GetStartPos() { return Pos(1, 1); }
	Pos GetEndPos() { return Pos(_size - 2, _size - 2); }

private:
	ETileType _tile[BOARD_MAX_HEIGHT][BOARD_MAX_WIDTH];
	int32 _size = 0;

};

