#include <bits/stdc++.h>

using namespace std;

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int a[15555];
int main()
{
	fastIO();

	int n = 0;
	int m = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] == m)
			{
				cnt++;
			}
		}
	}

	cout << cnt;
}