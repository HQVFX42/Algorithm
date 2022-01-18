#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char c[20];
	cin >> c;
	for (int i = 0; c[i] != NULL; i++)
	{
		cout << "'" << c[i] << "'\n";
	}
}