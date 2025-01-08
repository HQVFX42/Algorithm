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
	A(int n = 1) : n(n) { cout << "A Constructor" << '\n'; }
	~A() { cout << "A Destructor" << '\n'; }
	A(const A & a) : n(a.n) { cout << "A Copy" << '\n'; } // user-defined copy constructor
	A(A &&) { cout << "A Move" << '\n'; }
};

struct B : A
{
	int n;
	// implicit default constructor B::B()
	B(int n = 1) : n(n) { cout << "B Constructor" << '\n'; }
	~B() { cout << "B Destructor" << '\n'; }
	// implicit copy constructor B::B(const B&)
	B(const B & b) : n(b.n) { cout << "B Copy" << '\n'; }
	B(B &&) { cout << "B Move" << '\n'; }
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

	B b1;
	B b2 = b1;
	A a5 = b2; // conversion to A& and copy constructor

	cout << "---" << '\n';

	return 0;
}