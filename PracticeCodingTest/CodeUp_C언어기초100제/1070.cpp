#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a;
	cin >> a;
	if (a < 3 || a == 12) cout << "winter";
	else if (a >= 3 && a <= 5) cout << "spring";
	else if (a >= 6 && a <= 8) cout << "summer";
	else cout << "fall";
}