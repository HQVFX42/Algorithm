#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int h[9];

int main()
{
	fastIO();
	for (int i = 0; i < 9; i++)
	{
		cin >> h[i];
	}
	sort(h, h + 9);
	do
	{
		int sum = 0;
		for (int i = 0; i < 7; i++)
		{
			sum += h[i];
		}
		if (sum == 100)
		{
			break;
		}
	} while (next_permutation(h, h+9));
	for (int i = 0; i < 7; i++)
	{
		cout << h[i] << '\n';
	}
}