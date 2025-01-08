//
//  main.cpp
//  Algothingy
//
//  Created by carroll on 12/3/23.
//

#include <bits/stdc++.h>

using namespace std;

struct A
{
	int n;
	A(int n = 1) : n(n) { cout << "Constructor" << '\n'; }
	~A() { cout << "Destructor" << '\n'; }
	A(const A & a) : n(a.n) { cout << "Copy" << '\n'; } // user-defined copy constructor
	A(A &&) { cout << "Move" << '\n'; }
};

struct B : A
{
	// implicit default constructor B::B()
	// implicit copy constructor B::B(const B&)
};

A F1(A a)
{
	return a;
}

A F2(A & a)
{
	return a;
}

int main()
{
	A a1(7);
	A a2(a1); // calls the copy constructor
	A a3 = F1(a2);
	A a4 = F2(a3);

	cout << "---" << '\n';

	B b;
	B b2 = b;
	A a5 = b; // conversion to A& and copy constructor

	cout << "---" << '\n';

	return 0;
}