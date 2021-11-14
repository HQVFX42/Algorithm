#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt[201] = {};
	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		cnt[x + 100]++;
	}

	int v;
	cin >> v;

	cout << cnt[v + 100];
}