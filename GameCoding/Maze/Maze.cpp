#include"pch.h"
#include "Board.h"
#include "Player.h"
#include "CaStack.h"
#include "CaQueue.h"
#include "CaTree.h"
#include "CaPriorityQueue.h"

Board board;
Player player;

int main()
{
	::srand(static_cast<uint32>(time(nullptr)));

	board.Init(25, &player);
	player.Init(&board);

	uint64 lastTick = 0;
	while (true)
	{
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;

		// Input

		// Logic
		player.Update(deltaTick);

		// Render
		board.Render();
	}
}
