#include <bits/stdc++.h>
using namespace std;
// R : 1s, 512MB
// 1 <= M <= N <= 8
int arr[10];
bool bUsed[10];

void funcRecursive(int k, int n, int m)	// 현재 k개까지 수를 선택
{
	if (k == m)	// m개를 모두 선택했다면
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)	// 1부터 n까지의 수에대해
	{
		if (bUsed[i] == false)	// 아직 i가 사용되지 않았다면
		{
			arr[k] = i;			// k번째 수를 i로 정한다
			bUsed[i] = true;	// i는 사용했다고 명시
			funcRecursive(k + 1, n, m);	// 다음 수를 정하러 한 단계 더 들어간다
			bUsed[i] = false;	// k번째 수를 i로 정한 모든 경우에 대해 다 확인하면 i를 다시 미사용으로 
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	funcRecursive(0, N, M);
}