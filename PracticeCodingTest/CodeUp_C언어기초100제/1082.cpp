#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> hex >> n;
	for (int i = 1; i < 16; i++)
	{
		cout << hex << uppercase << n << '*' << i << '=' << n * i << '\n';
	}
}