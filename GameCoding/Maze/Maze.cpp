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
	//::srand(static_cast<uint32>(time(nullptr)));

	//board.Init(25, &player);
	//player.Init(&board);

	//uint64 lastTick = 0;
	//while (true)
	//{
	//	const uint64 currentTick = ::GetTickCount64();
	//	const uint64 deltaTick = currentTick - lastTick;
	//	lastTick = currentTick;

	//	// Input

	//	// Logic
	//	player.Update(deltaTick);

	//	// Render
	//	board.Render();
	//}

	CaPriorityQueue<int> pq;
	pq.push(1);
	pq.push(4);
	pq.push(3);
	pq.push(5);
	pq.push(2);

	int value = pq.top();
	std::cout << "Top value: " << value << std::endl;
	pq.pop();
	value = pq.top();
	std::cout << "Top value: " << value << std::endl;
}
