// 1s, 512MB
// 1 <= M <= 8
#include <bits/stdc++.h>
using namespace std;

int arr[10];
bool bUsed[10];

void funcRecursive(int k, int n, int m)	// 현재 k까지 수를 선택했다
{
	if (k == m)	// m개를 모두 택했으면
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';	// arr에 기록해둔 수를 출력
		}
		cout << '\n';
		return;
	}
	int cnt = arr[k - 1] + 1;
	//int cnt = 1;	// 시작지점, k = 0일 때는 1
	//if(cnt != 0) cnt = arr[k - 1] + 1;	// k != 0일 경우 arr[k-1] + 1
	for (int i = cnt; i <= n; i++)
	{
		if (bUsed[i] == false)	// 아직 i가 사용되지 않았으면
		{
			arr[k] = i;	// k번째 수를 i로 정한다
			bUsed[i] = true;	// i를 사용
			funcRecursive(k + 1, n, m);	// 다음 수를 정하러 한 단계 더
			bUsed[i] = false;	// k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 미사용
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