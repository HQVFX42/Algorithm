#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a, b, c;

LL Power(LL a, LL b, LL c)
{
	if (b == 1)
	{
		return a % c;
	}
	LL result = Power(a, b / 2, c);
	result = result * result % c;
	if (b % 2 == 0)
	{
		return result;
	}
	return result * a % c;
}

int main()
{
	cin >> a >> b >> c;
	cout << Power(a, b, c);
}