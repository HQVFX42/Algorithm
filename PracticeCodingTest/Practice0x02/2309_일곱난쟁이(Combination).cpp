#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int heigt[9], result[7];

	for (int i = 0; i < 9; i++)
	{
		cin >> heigt[i];
	}

	for (int a = 0; a < 8; a++)
	{
		int total = 0;

		for (int b = a+1; b < 9; b++)
		{
			total = 0;

			for (int c = 0, i =0 ; c < 9; c++)
			{
				if (c != a && c != b)
				{
					result[i++] = heigt[c];
				}
			}
			for (int i = 0; i < 7; i++)
			{
				total += result[i];
			}

			if (total == 100)
			{
				break;
			}
		}
		if (total == 100)
		{
			break;
		}
	}
	sort(result, result + 7);
	for (int i = 0; i < 7; i++)
	{
		cout << result[i] << "\n";
	}
}