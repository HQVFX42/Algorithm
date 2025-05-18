#include <iostream>
#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include <vector>
#include <queue>

int Add(int a, int b)
{
	return a + b;
}

// `행동` 자체를 인자로 넘기고 싶을 때
// int Add(int a, int b) -> int(*)(int, int)
using FuncPtrType = int(*)(int, int);
int Foo(int a, int b, FuncPtrType func)
{
	return func(a, b);
}

/**
 * 콜백 함수
 * ex) UI, 서버 연동시, 키맵핑.
 */
void Fire()
{

}

void Jump()
{

}

/**
 * 인벤토리의 아이템을 여러 타입에 따라 탐색이나 정렬이 필요할 때. 
 */
class Item
{
public:

public:
	int _itemId = 0;
	int _rarity = 0;
	int _ownerId = 0;
};

using ItemSelectorType = bool(*)(Item* item);
Item* FindItem(Item items[], int itemCount, ItemSelectorType selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (item->_rarity == 1)
		{
			return item;
		}
	}

	return nullptr;
}

bool IsRare(Item* item)
{
	return item->_rarity == 1;
}

// 멤버함수 포인터 (함수호출 규약에 따라 정적/전역 함수랑은 다름)
// 일반함수: cdecl, 멤버함수: thiscall
class Test
{
public:
	void Print()
	{
		std::cout << "Hello" << std::endl;
	}
};

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

	Foo(10, 20, &Add);
	Foo(10, 20, [](int a, int b) { return a - b; });

	//
	using OnClickKeyboard = void(*)();
	OnClickKeyboard leftB = &Fire;
	OnClickKeyboard spaceB = &Jump;

	//
	Item items[10];
	items[3]._itemId = 111;
	items[3]._rarity = 1;
	items[3]._ownerId = 42;

	Item* foundItem = FindItem(items, 10, IsRare);

	//
	using memberFuncPtrType = void(Test::*)();
	memberFuncPtrType memFuncPtr = &Test::Print;

	Test t;
	(t.*memFuncPtr)();

	Test* t2 = &t;
	(t2->*memFuncPtr)();
}
