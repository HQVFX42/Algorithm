#include <bits/stdc++.h>

using namespace std;

int n, maxVal, maxId;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 0; i < 9; i++)
	{
		cin >> n;

		if (n > maxVal)
		{
			maxVal = n;
			maxId = i+1;
		}
	}
	cout << maxVal << "\n" << maxId;
}