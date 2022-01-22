#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;
	int x = a * b * c;
	for (int i = 1; i <= x; i++)
	{
		if (i % a == 0 && i % b == 0 && i % c == 0)
		{
			cout << i;
			break;
		}
	}
}