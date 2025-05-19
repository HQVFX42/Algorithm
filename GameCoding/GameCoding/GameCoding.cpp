#include <iostream>
#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include <vector>
#include <queue>

//
class Functor
{
public:
	void operator()()
	{
		std::cout << _hp << std::endl;
	}

	void operator()(int n)
	{
		std::cout << "operator()" << std::endl;
		_hp += n;
		std::cout << _hp << std::endl;
	}

public:
	int _hp = 0;
};

//
struct AddStruct
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

template<typename T>
int DoSomething(int a, int b, T func)
{
	return func(a, b);
}

//
template<typename T>
struct Greater
{
	bool operator()(const T& lhs, const T& rhs)
	{
		return lhs > rhs;
	}
};

//
class Input
{
public:
	virtual ~Input() {}
};

class Movement : public Input
{

};

class Jump : public Input
{

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

	//
	Functor func;
	func._hp = 10;
	func();
	func(10);

	//
	AddStruct func2;
	DoSomething(10, 20, func2);

	//
	std::priority_queue<int, std::vector<int>, Greater<int>> pq;
	pq.push(10);
	pq.push(20);
	std::cout << pq.top() << std::endl;

	//
	Input* inputMove = new Movement();
	delete inputMove;
	Input* inputJump = new Jump();

	std::queue<Input*> q;
	q.push(inputMove);
	q.push(inputJump);
}
