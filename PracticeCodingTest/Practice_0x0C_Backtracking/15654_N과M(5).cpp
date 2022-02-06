// 1s, 512MB
// 1 <= M <= N <= 8
#include <bits/stdc++.h>
using namespace std;

int arr[10];
bool bUsed[10];
int num[10];

void funcRecursive(int k, int n, int m)	// 현재 k개까지 수를 선택했다
{
	if (k == m)	// m개를 모두 택했다면
	{
		for (int i = 0; i < m; i++)
		{
			cout << num[arr[i]] << ' ';	// arr에 기록해둔 인덱스에 대응되는 수 출력
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)	// 0 부터 n-1까지의 인덱스에 대해
	{
		if (bUsed[i] == false)	// 아직 i가 사용되지 않았으면
		{
			arr[k] = i;	// k번째 인덱스를 i로 정함
			bUsed[i] = true;	// i 사용
			funcRecursive(k + 1, n, m);	// 다음 인덱스 정하러 한 단계 더 진행
			bUsed[i] = false;	// k번째 인덱스를 i로 정한 모든 경우에 대해 다 확인했으니 i 미사용으로 전환
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);
	funcRecursive(0, n, m);
}