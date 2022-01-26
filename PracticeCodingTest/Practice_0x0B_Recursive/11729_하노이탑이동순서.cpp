#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n)
{
	if (n == 1)	// base condition
	{
		cout << a << ' ' << b << '\n';
		return;
	}
	func(a, 6 - a - b, n - 1);		// n-1���� ������ ��� a���� ��� 6-a-b�� �ű��.
	cout << a << ' ' << b << '\n';	// n�� ������ ��� a���� ��� b�� �ű��.
	func(6 - a - b, b, n - 1);		// n-1 ���� ������ ��� 6-a-b���� ��� b�� �ű��.
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;
	cout << (1 << k) - 1 << '\n';
	func(1, 3, k);
}