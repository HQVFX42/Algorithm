#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cout << '*';
		}
		cout << "\n";
	}
}