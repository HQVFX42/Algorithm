#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, arr[10001] = {};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr[num]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		while (arr[i])
		{
			cout << i << '\n';
			arr[i]--;
		}
	}
}