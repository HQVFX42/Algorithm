#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long  a, b;
	cin >> a >> b;
	cout << a + b << "\n"
		 << a - b << "\n"
		 << a * b << "\n"
		 << a / b << "\n"
		 << a % b << "\n";
	cout << fixed << setprecision(2) << (double)a / (double)b << "\n";
}