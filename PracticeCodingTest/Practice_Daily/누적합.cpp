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
	{	// �������� ���� ����  i-1�� �־� 1��° index ���� ����ϴ� ���� ����
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b >> c;
		cout << psum[c] - psum[b - 1] << '\n';
	}
}