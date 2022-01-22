#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 3; i++)
	{
		int a;
		cin >> a;
		if (!(a & 1))
		{
			cout << a << '\n';
		}
	}
}