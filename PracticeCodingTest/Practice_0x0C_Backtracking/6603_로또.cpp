// 1s, 128MB
// 6 < k < 13
#include <bits/stdc++.h>
using namespace std;

int k, num[15], arr[6];

void funcRecursive(int n, int st)
{
	if (n == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = st; i < k; i++)
	{
		arr[n] = num[i];
		funcRecursive(n + 1, i + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> k && k != 0)
	{
		for (int i = 0; i < k; i++)
		{
			cin >> num[i];
		}
		funcRecursive(0, 0);
		cout << '\n';
	}
}