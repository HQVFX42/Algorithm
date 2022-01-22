#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[10000] = {};
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int ans = 23;
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, arr[i]);
	}
	cout << ans;
}