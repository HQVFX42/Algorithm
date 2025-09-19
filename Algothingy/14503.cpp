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

//시계로 k칸 회전: d = (d + k) % 4, 반시계로 k칸 회전: d = (d + 4 - k) % 4
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };   // N, E, S, W // clockwise

bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX = 55;
int Graph[MAX][MAX];
bool vis[MAX][MAX];

int main()
{
    FastIO();

    int N, M;
    ip2(N, M);
    int r, c, d;
    ip2(r, c);
    ip1(d);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {            
            ip1(Graph[i][j]);
        }
    }

    int answer = 0;
    while (true)
    {
        if (!vis[r][c])
        {
            vis[r][c] = true;
            answer++;
        }

        bool bFlag = false;
        for (int dir = 0; dir < 4; dir++)
        {
            d = (d + 3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];
            if (OOB(nx, ny, N, M) or Graph[nx][ny] or vis[nx][ny])
            {
                continue;
            }

            r += dx[d];
            c += dy[d];
            bFlag = true;
            break;
        }

        if (!bFlag)
        {
            int nd = (d + 2) % 4;
            int nx = r + dx[nd];
            int ny = c + dy[nd];
            if (OOB(nx, ny, N, M) or Graph[nx][ny])
            {
                break;
            }
            r += dx[nd];
            c += dy[nd];
        }
    }

    op1(answer);
}
