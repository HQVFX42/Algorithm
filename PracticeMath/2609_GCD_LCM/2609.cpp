#include <iostream>
using namespace std;

// ����Լ��� ����� ��Ŭ���� ȣ����
//int gcd(int a, int b)
//{
//	if (b == 0) { return a; }
//	else { return gcd(b, a % b); }
//}

// ����Լ��� ������� �ʴ� ��Ŭ���� ȣ����
//int gcd(int a, int b)
//{
//	while (b != 0)
//	{
//		int r = a % b;
//		a = b;
//		b = r;
//	}
//	return a;
//}

int main()
{
	// GCD
	// 2���� min(A, B)���� ��� ������ ������ ���� ���
	int g = 1;
	int a = 0, b = 0;
	cin >> a >> b;
	for (int i = 2; i <= min(a,b); i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			g = i;
		}
	}
	cout << g << '\n';
	// LCM
	cout << a * b / g << '\n';
	return 0;
}