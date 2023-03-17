#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class A
{
public:
	A();
	~A();

	virtual void print();

private:

};

A::A()
{
	cout << "A()\n";
}

A::~A()
{
	cout << "~A()\n";
}

void A::print()
{
	cout << "AAA\n";
}

class B : A
{
public:
	B();
	~B();

	virtual void print();

private:

};

B::B()
{
	cout << "B()\n";
}

B::~B()
{
	cout << "~B()\n";
}

void B::print()
{
	cout << "BBB\n";
}

int main()
{
	//fastIO();
	A* ptrA = new A;
	B* ptrB = new B;

	ptrA->print();
	ptrB->print();

	delete ptrA;
	delete ptrB;
}