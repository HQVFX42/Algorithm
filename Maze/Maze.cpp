#include"pch.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

int main()
{
	::srand(static_cast<uint32>(time(nullptr)));

	board.Init(25);

	while (true)
	{
		// Input

		// Logic

		// Render
		board.Render();
	}
}
