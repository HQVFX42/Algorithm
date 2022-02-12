// R : 1s, 512MB
// 1 <= M <= N <= 8
#include <bits/stdc++.h>
using namespace std;

void dfs2(int depth, int n, int m)
{
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	do
	{
		reverse(v.begin() + m, v.end());	// ���� m���� ���� �ߺ��� �ɷ�����
		for (int i = 0; i < m; i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));	// N��ü�� permutation
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	dfs2(0, N, M);
}