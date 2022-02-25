// merge sort
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1111111], b[1111111], c[1111111];

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	int idxA = 0, idxB = 0;
	for (int i = 0; i < n + m; i++)
	{
		if (idxB == m) c[i] = a[idxA++];
		else if (idxA == n) c[i] = b[idxB++];
		else if (a[idxA] <= b[idxB]) c[i] = a[idxA++];
		else c[i] = b[idxB++];
	}
	for (int i = 0; i < n + m; i++) cout << c[i] << ' ';
}