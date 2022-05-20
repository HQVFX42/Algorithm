#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int a[111111], b, c, psum[111111], n, m;

int main()
{
	fastIO();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{	// 누적합을 만들 때는  i-1이 있어 1번째 index 부터 사용하는 것이 좋음
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b >> c;
		cout << psum[c] - psum[b - 1] << '\n';
	}
}