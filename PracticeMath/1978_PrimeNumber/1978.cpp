#include <iostream>

using namespace std;

bool is_primeNumber1(int n)
{
	if (n < 2) { return false; }
	for (int i = 2; i <= n - 1; i++)
	{
		if (n % i == 0) { return false; }
	}
	return true;
}

bool is_primeNumber2(int n)
{
	if (n < 2) { return false; }
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0) { return false; }
	}
	return true;
}

bool is_primeNumber3(int n)
{
	if (n < 2) { return false; }
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0) { return false; }
	}
	return true;
}

int main()
{
	int unsigned t = 0;
	cin >> t;

	int cnt = 0;
	for (int i = 0; i < t; i++)
	{
		int num;
		cin >> num;
		if (is_primeNumber3(num))
		{
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}