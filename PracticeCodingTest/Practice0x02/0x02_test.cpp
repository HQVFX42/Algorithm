#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[9] = {};
	for (int i = 0; i < 9; i++) cin >> arr[i];
	int ans = 0;
	for (int i = 0; i < 9; i++) ans = max(ans, arr[i]);
	cout << ans << '\n';
	cout << find(arr, arr + 9, ans) - arr + 1;
}