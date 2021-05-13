#include <iostream>
#include <vector>
using namespace std;

unsigned int gcd(unsigned int a, unsigned int b)
{
	if (b == 0) { return a; }
	else { return gcd(b, a % b); }
}

int main()
{
	unsigned int n = 0, s = 0;
	cin >> n >> s;
	vector<int> a(n);
	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int x;
		cin >> x;
		int diff = x - s;
		if (diff < 0) { diff = -diff; }
		a[i] = diff;
	}

	unsigned int result = a[0];
	for (unsigned int i = 1; i < n; i++)
	{
		result = gcd(result, a[i]);
	}
	cout << result << '\n';

	return 0;
}