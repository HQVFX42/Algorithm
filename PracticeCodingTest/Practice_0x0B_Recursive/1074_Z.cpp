#include <bits/stdc++.h>
using namespace std;

int ZRecursive(int n, int r, int c)
{
	if (n == 0)
	{
		return 0;
	}
	int half = 1 << (n - 1);
	if (r < half && c < half)
	{
		return ZRecursive(n - 1, r, c);
	}
	if (r < half && c >= half)
	{
		return half * half + ZRecursive(n - 1, r, c - half);
	}
	if (r >= half && c < half)
	{
		return 2 * half * half + ZRecursive(n - 1, r - half, c);
	}
	else
	{
		return 3 * half * half + ZRecursive(n - 1, r - half, c - half);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, r, c;
	cin >> N >> r >> c;
	cout << ZRecursive(N, r, c);
}