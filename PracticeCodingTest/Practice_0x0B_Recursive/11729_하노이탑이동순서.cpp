#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n)
{
	if (n == 1)	// base condition
	{
		cout << a << ' ' << b << '\n';
		return;
	}
	func(a, 6 - a - b, n - 1);		// n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.
	cout << a << ' ' << b << '\n';	// n번 원판을 기둥 a에서 기둥 b로 옮긴다.
	func(6 - a - b, b, n - 1);		// n-1 개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다.
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