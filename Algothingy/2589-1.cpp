#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define X first
#define Y second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ip1(a) cin >> a
#define ip2(a,b) cin >> a >> b
#define ops cout << ' '
#define op1(a) cout << a << ' '
#define op2(a,b) cout << a << ' ' << b
#define opl cout << '\n'
#define op1l(a) cout << a << '\n'
#define op2l(a,b) cout << a << ' ' << b << '\n'

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int N, M;
int vis[55][55];
string graph[55];

int main()
{
    FastIO();

    ip2(N, M);
    for (int i = 0; i < N; i++)
    {
        ip1(graph[i]);
    }

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] == 'L')
            {
                memset(vis, 0, sizeof(vis));
                vis[i][j] = 1;
                queue<pii> q;
                q.push({ i, j });
                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (OOB(nx, ny, N, M) or vis[nx][ny] or graph[nx][ny] == 'W')
                        {
                            continue;
                        }
                        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                        q.push({ nx, ny });
                        result = max(result, vis[nx][ny]);
                    }
                }
            }
        }
    }

    op1l(result - 1);
}
