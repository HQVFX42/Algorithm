#include <iostream>

using namespace std;

int main()
{
	long long a = 0, b = 0;
	cin >> a >> b;
	// 2가 더 적은지 5가 더 적은지 알 수 없으므로 둘다 비교 해서 min값을 찾는다.
	long long div2 = 0;
	long long div5 = 0;

	for (long long i = 2; i <= a; i *= 2)
	{
		div2 += a / i;
	}
	for (long long i = 2; i <= a - b; i *= 2)
	{
		div2 -= (a-b) / i;
	}
	for (long long i = 2; i <= b; i *= 2)
	{
		div2 -= b / i;
	}
	for (long long i = 5; i <= a; i *= 5)
	{
		div5 += a / i;
	}
	for (long long i = 5; i <= a - b; i *= 5)
	{
		div5 -= (a - b) / i;
	}
	for (long long i = 5; i <= b; i *= 5)
	{
		div5 -= b / i;
	}
	cout << min(div2, div5) << '\n';

	return 0;
}