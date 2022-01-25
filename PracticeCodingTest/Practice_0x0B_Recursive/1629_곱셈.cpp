#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL Power(LL a, LL b, LL c)
{
	if (b == 1)	// base condition
	{
		return a % c;
	}
	LL result = Power(a, b / 2, c);
	result = result * result % c;

	if (b % 2 == 0)	// 짝수면 바로 반환
	{
		return result;
	}
	else	// 홀수면 a 한 번 더 곱해서 반환
	{
		return result * a % c;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	LL a, b, c;
	cin >> a >> b >> c;
	cout << Power(a, b, c);
}