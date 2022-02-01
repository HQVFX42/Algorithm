// R : 10s, 128MB
// 1 <= N < 15
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
bool bUsed1[40];	// check column
bool bUsed2[40];	// check diagonal /
bool bUsed3[40];	// check diagonal \

void funcRecursive(int cur, int n)	// cur번째 row에 말 배치 예정
{
	if (cur == n)	// n개를 놓는데 성공했다면
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)	// (cur, i)에 퀸을 놓을 예정
	{
		if (bUsed1[i] || bUsed2[i + cur] || bUsed3[cur - i + n - 1])
		{
			continue;
		}
		bUsed1[i] = true;
		bUsed2[i + cur] = true;
		bUsed3[cur - i + n - 1] = true;
		funcRecursive(cur + 1, n);
		bUsed1[i] = false;
		bUsed2[i + cur] = false;
		bUsed3[cur - i + n - 1] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	funcRecursive(0, N);
	cout << cnt;
}