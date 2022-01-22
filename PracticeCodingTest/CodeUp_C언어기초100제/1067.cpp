#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a;
	cin >> a;
	if (a > 0)
	{
		cout << "plus" << '\n';
	}
	else
	{
		cout << "minus" << '\n';

	}
	if (a & 1)
	{
		cout << "odd" << '\n';
	}
	else
	{
		cout << "even" << '\n';
	}
}