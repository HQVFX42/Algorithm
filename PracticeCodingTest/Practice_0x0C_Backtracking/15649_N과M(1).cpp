#include <bits/stdc++.h>
using namespace std;
// R : 1s, 512MB
// 1 <= M <= N <= 8
int arr[10];
bool bUsed[10];

void funcRecursive(int k, int n, int m)	// ���� k������ ���� ����
{
	if (k == m)	// m���� ��� �����ߴٸ�
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)	// 1���� n������ ��������
	{
		if (bUsed[i] == false)	// ���� i�� ������ �ʾҴٸ�
		{
			arr[k] = i;			// k��° ���� i�� ���Ѵ�
			bUsed[i] = true;	// i�� ����ߴٰ� ���
			funcRecursive(k + 1, n, m);	// ���� ���� ���Ϸ� �� �ܰ� �� ����
			bUsed[i] = false;	// k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ���ϸ� i�� �ٽ� �̻������ 
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