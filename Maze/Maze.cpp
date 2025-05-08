#include"pch.h"
#include "Board.h"
#include "Player.h"
#include "CaStack.h"

Board board;
Player player;

int main()
{
	CaStack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	int a = st.top();
	st.pop();
	int b = st.top();
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
