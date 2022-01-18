#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char c[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> c[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "[" << (c[i] - '0') * pow(10, 4-i) << "]\n";
	}
}