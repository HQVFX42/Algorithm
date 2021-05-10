#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) { return a; }
	else { return gcd(b, a % b); }
}

int main()
{
	unsigned int t = 0;
	cin >> t;

	while (t--)
	{
		unsigned int a = 0, b = 0;
		cin >> a >> b;

		cout << (a * b) / gcd(a, b) << '\n';
	}
	return 0;
}