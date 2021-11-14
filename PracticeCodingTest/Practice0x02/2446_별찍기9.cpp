#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	cin >> num;

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < 2 * (num - i) - 1; j++)
		{
			cout << '*';
		}
		cout << "\n";
	}

	for (int j = 0; j < num - 1; j++)
	{
		cout << ' ';
	}
	cout << "*\n";

	for (int i = 1; i <= num - 1; i++)
	{
		for (int j = 1; j <= num - i - 1; j++)
		{
			cout << ' ';
		}
		for (int j = 1; j <= 2 * i + 1; j++)
		{
			cout << '*';
		}
		cout << "\n";
	}

}