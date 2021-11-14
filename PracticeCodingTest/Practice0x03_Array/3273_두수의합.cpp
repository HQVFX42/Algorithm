#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a[1000001] = {};

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int x;
	cin >> x;

	int ans = 0;
	bool b[2000001] = {};
	for (int i = 0; i < n; i++)
	{
		if (x - a[i] > 0 && b[x-a[i]])
		{
			ans++;
		}
		b[a[i]] = true;
	}
	cout << ans;
}