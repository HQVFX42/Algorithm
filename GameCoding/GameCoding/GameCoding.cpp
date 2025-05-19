#include <iostream>
#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include <vector>
#include <queue>

// 함수가 호출될 때마다 실질적으로 복사가 일어나므로 복사비용을 아끼려면 주소값을 넘겨야한다
//void Print(std::vector<int> v)
void Print(std::vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
}

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

	// std::vector
	// 추가
	// 삭제
	// 순회
	// 검색
	// size: resize
	// capacity: reserve
	// 삽입or삭제
	// - 시작: O(n)
	// - 중간: O(n)
	// - 끝: O(1)
	// push_back, front, back: O(1)
	// 임의접근 v[i]: O(1)

	std::vector<int> v{ 1,2,3,4,5 };
	Print(v);
	std::cout << "------------------" << std::endl;

	std::vector<int> v2 = v;
	v2[0] = 100;	// 복사가 일어나므로 v의 값은 변경되지 않음
	Print(v2);
	std::cout << "------------------" << std::endl;

	//
	int* a = &v[0];
	int value = *a;
	std::cout << value << std::endl;
	a++;
	std::cout << *a << std::endl;
	a++;
	std::cout << *a << std::endl;
	std::cout << "------------------" << std::endl;

	//
	int* ptr = &v[0];
	int* ptrEnd = &v[4] + 1;
	while (ptr != ptrEnd)
	{
		std::cout << *ptr << std::endl;
		ptr++;
	}
	std::cout << "------------------" << std::endl;

	for (std::vector<int>::iterator it = v.begin(); it != v.end();)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "------------------" << std::endl;

	for (std::vector<int>::iterator it = v.begin(); it != v.end();)
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		if (*it == 5)
		{
			it = v.erase(it);
		}
		else
		{
			it++;
		}
	}
	for (std::vector<int>::iterator it = v.begin(); it != v.end();)
	{
		std::cout << *it << std::endl;
		it++;
	}
}
