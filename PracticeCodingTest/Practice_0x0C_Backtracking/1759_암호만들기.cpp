// 2s, 128MB
// 3 <= L <= C <= 15
#include <bits/stdc++.h>
using namespace std;

int L, C;
char arr[15], ans[15];

void FuncRecursive(int depth, int st)
{
	if (depth == L)
	{
		int vowel = 0, consonant = 0;
		bool bPass = false;
		for (int i = 0; i < L; i++)
		{
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
			{
				vowel++;
			}
			else
			{
				consonant++;
			}
		}
		if (vowel >= 1 && consonant >= 2)
		{
			bPass = true;
		}
		if (bPass)
		{
			for (int i = 0; i < L; i++)
			{
				cout << ans[i];
			}
			cout << '\n';
			return;
		}
	}
	for (int i = st; i < C; i++)
	{
		ans[depth] = arr[i];
		FuncRecursive(depth + 1, i + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + C);
	FuncRecursive(0, 0);
}