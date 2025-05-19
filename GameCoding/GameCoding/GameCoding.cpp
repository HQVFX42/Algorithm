#include <iostream>
#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include <vector>
#include <queue>
#include <list>

int main()
{
	//SetCursorOnOff(false);

	//while (true)
	//{
	//	// Input
	//	HandleKeyInput();

	//	// Logic
	//	HandleMove();

	//	// Output
	//	PrintMap2D();
	//}

	// 추가
	// 삭제
	// 순회
	// 검색
	// std::list
	// size: resize
	// 삽입or삭제
	// - 시작: O(1)
	// - 중간: O(1)	해당 위치를 알고 있다면
	// - 끝: O(1)
	// front: O(1)
	// back: O(1)
	// push_front: O(1)
	// push_back: O(1)
	// remove(value)
	// 임의접근 l[i]: X

	std::list<int> l{ 1,2,3,4,5 };

	for (std::list<int>::iterator it = l.begin(); it != l.end();)
	{
		std::cout << *it << std::endl;
		it++;
	}
	for (std::list<int>::iterator it = l.begin(); it != l.end();)
	{
		if (*it % 2 == 0)
		{
			it = l.erase(it);
		}
		if (*it == 5)
		{
			it = l.erase(it);
		}
		else
		{
			it++;
		}
	}

	std::cout << std::endl;
	for (std::list<int>::iterator it = l.begin(); it != l.end();)
	{
		std::cout << *it << std::endl;
		it++;
	}

}
