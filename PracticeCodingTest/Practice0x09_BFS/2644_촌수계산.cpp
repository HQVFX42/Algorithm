#include <bits/stdc++.h>
using namespace std;

int graph[111][111], dist[111];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;	// ��ü ��� ��
	cin >> n;
	int a, b;	// �̼��� ����ؾ��ϴ� ���� �ٸ� �� ����� ��ȣ
	cin >> a >> b;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	fill(dist, dist + n + 1, -1);
	queue<int> q;
	q.push(a);
	dist[a] = 0;	// ������
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int nxt = 1; nxt <= n; nxt++)
		{
			if (dist[nxt] != -1 or graph[cur][nxt] == 0) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	cout << dist[b];	// ������������ ����
}