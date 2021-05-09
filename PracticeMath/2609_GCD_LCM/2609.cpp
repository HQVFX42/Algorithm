#include <iostream>
using namespace std;

// 재귀함수를 사용한 유클리드 호제법
//int gcd(int a, int b)
//{
//	if (b == 0) { return a; }
//	else { return gcd(b, a % b); }
//}

// 재귀함수를 사용하지 않는 유클리드 호제법
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
	// 2부터 min(A, B)까지 모든 정수로 나누어 보는 방법
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