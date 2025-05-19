#include"pch.h"
#include "Board.h"
#include "Player.h"

#include "CaList.h"

Board board;
Player player;

int main()
{
	CaVector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(10);

	for (CaVector<int>::iterator it = v.begin(); it != v.end();)
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << std::endl;

	CaList<int> l;
	l.AddAtTail(10);
	l.AddAtTail(20);
	l.AddAtTail(10);

	for (CaList<int>::iterator it = l.begin(); it != l.end();)
	{
		std::cout << *it << std::endl;
		it++;
	}

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
}
