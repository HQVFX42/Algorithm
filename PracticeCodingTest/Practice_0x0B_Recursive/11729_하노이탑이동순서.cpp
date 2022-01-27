#include <bits/stdc++.h>
using namespace std;

void func1(int a, int b, int n)
{
	if (n == 1)	// base condition
	{
		cout << a << ' ' << b << '\n';
		return;
	}
	func1(a, 6 - a - b, n - 1);		// n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.
	cout << a << ' ' << b << '\n';	// n번 원판을 기둥 a에서 기둥 b로 옮긴다.
	func1(6 - a - b, b, n - 1);		// n-1 개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다.
}

void func2(int a, int b, int n)
{
	if (n == 0)	// base condition
	{
		return;
	}
	func2(a, 6 - a - b, n - 1);		// n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.
	cout << a << ' ' << b << '\n';	// n번 원판을 기둥 a에서 기둥 b로 옮긴다.
	func2(6 - a - b, b, n - 1);		// n-1 개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다.
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;
	//cout << (int)pow(2, k) - 1 << '\n';	// pow함수 사용시 double을 int로 형변환 해줘야 한다
	cout << (1 << k) - 1 << '\n';		// 1을 k칸 left shift = 2^k
	//func1(1, 3, k);
	func2(1, 3, k);
}