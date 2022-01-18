#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n1, n2, n3;
	char c;
	cin >> n1 >> c >> n2 >> c >> n3;
	c = '-';
	cout.width(2);
	cout.fill('0');
	cout << n3 << c;
	
	cout.width(2);
	cout.fill('0');
	cout << n2 << c;

	cout.width(4);
	cout.fill('0');
	cout << n1;
}