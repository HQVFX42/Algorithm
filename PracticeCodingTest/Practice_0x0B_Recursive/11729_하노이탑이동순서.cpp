#include <bits/stdc++.h>
using namespace std;

void func1(int a, int b, int n)
{
	if (n == 1)	// base condition
	{
		cout << a << ' ' << b << '\n';
		return;
	}
	func1(a, 6 - a - b, n - 1);		// n-1���� ������ ��� a���� ��� 6-a-b�� �ű��.
	cout << a << ' ' << b << '\n';	// n�� ������ ��� a���� ��� b�� �ű��.
	func1(6 - a - b, b, n - 1);		// n-1 ���� ������ ��� 6-a-b���� ��� b�� �ű��.
}

void func2(int a, int b, int n)
{
	if (n == 0)	// base condition
	{
		return;
	}
	func2(a, 6 - a - b, n - 1);		// n-1���� ������ ��� a���� ��� 6-a-b�� �ű��.
	cout << a << ' ' << b << '\n';	// n�� ������ ��� a���� ��� b�� �ű��.
	func2(6 - a - b, b, n - 1);		// n-1 ���� ������ ��� 6-a-b���� ��� b�� �ű��.
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;
	//cout << (int)pow(2, k) - 1 << '\n';	// pow�Լ� ���� double�� int�� ����ȯ ����� �Ѵ�
	cout << (1 << k) - 1 << '\n';		// 1�� kĭ left shift = 2^k
	//func1(1, 3, k);
	func2(1, 3, k);
}