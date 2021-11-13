#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	int diff;
	cin >> a >> b;
	if (a > b)
	{
		swap(a, b);
	}
	if (a == b || b - a == 1)
	{
		cout << 0;
	}
	else
	{
		diff = b - a - 1;
		cout << diff << "\n";

		for (long long i = 0; i < diff; i++)
		{
			
			cout << ++a << " ";
		}
	}

}