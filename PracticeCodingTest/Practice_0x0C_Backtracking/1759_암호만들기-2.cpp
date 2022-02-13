#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[20];

void dfs2()
{
	vector<int> v(c);
	for (int i = l; i < c; i++)
	{
		v[i] = 1;
	}
	do
	{
		int vowel = 0;
		bool bPass = false;
		for (int i = 0; i < c; i++)
		{
			if (v[i] == 0)
			{
				if (arr[i] == 'a' or arr[i] == 'e' or arr[i] == 'i' or arr[i] == 'o' or arr[i] == 'u')
				{
					vowel++;
				}
				if (vowel >= 1 and l - vowel >= 2)
				{
					bPass = true;
				}
			}
		}
		if (bPass)
		{
			for (int i = 0; i < c; i++)
			{
				if (v[i] == 0)
				{
					cout << arr[i];
				}
			}
			cout << '\n';
		}
	} while (next_permutation(v.begin(), v.end()));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> l >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + c);
	dfs2();
}