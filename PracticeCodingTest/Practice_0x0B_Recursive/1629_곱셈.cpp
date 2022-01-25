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

	if (b % 2 == 0)	// ¦���� �ٷ� ��ȯ
	{
		return result;
	}
	else	// Ȧ���� a �� �� �� ���ؼ� ��ȯ
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