#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int r, g, b;
	int count = 0;
	cin >> r >> g >> b;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < g; j++)
		{
			for (int k = 0; k < b; k++)
			{
				cout << i << ' ' << j << ' ' << k << '\n';
				count++;
			}
		}
	}
	cout << count;
}