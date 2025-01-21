#include <bits/stdc++.h>
using namespace std;

const int MAX = 222222;
//int n, k;
int dist[ MAX ], cnt[ MAX ];

void BFS(int x)
{
	dist[ x ] = 1;
	cnt[ x ] = 1;
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (0 <= nxt and nxt <= MAX)
			{
				if (!dist[ nxt ])
				{
					q.push(nxt);
					dist[ nxt ] = dist[ cur ] + 1;
					cnt[ nxt ] += cnt[ cur ];
				}
				else if (dist[ nxt ] == dist[ cur ] + 1)
				{
					cnt[ nxt ] += cnt[ cur ];
				}
			}
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	BFS(n);

	cout << dist[ k ] - 1 << '\n';
	cout << cnt[ k ] << '\n';

	return 0;
}
