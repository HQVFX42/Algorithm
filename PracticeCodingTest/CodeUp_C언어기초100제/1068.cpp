#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a;
	cin >> a;
	if (a > 89) cout << 'A';
	else if (a > 69) cout << 'B';
	else if (a > 39) cout << 'C';
	else cout << 'D';
}