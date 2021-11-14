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
		int j = 0;
		for (; j < num - i; j++)
		{
			cout << '*';
		}		
		cout << "\n";
	}
}