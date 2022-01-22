#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int number;
	cin >> number;

	int ans = 0;
	for (int i = 1; i < number; i++)
	{
		ans = ans + i;
		if (ans >= number)
		{
			cout << i;
			break;
		}
	}
}