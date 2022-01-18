#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n1, n2, n3;
	char c1, c2;
	cin >> n1 >> c1 >> n2 >> c2 >> n3;
	cout.width(4);
	cout.fill('0');
	cout << n1 << c1;
	cout.width(2);
	cout.fill('0');
	cout << n2 << c2;
	cout.width(2);
	cout.fill('0');
	cout << n3;
}