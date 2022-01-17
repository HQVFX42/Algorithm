#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int TC;
	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		int j = 0;
		for (; j < TC - i - 1; j++)cout << ' ';
		for (; j < TC; j++)cout << '*';
		cout << '\n';
	}
}