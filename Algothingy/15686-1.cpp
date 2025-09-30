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

int N;
int M;
vector<pii> vC;
vector<pii> vH;
vector<vector<int>> vLists;

void Combination(int start, vector<int> v)
{
    if (v.size() == M)
    {
        vLists.push_back(v);
        return;
    }

    for (int i = start + 1; i < vC.size(); i++)
    {
        v.push_back(i);
        Combination(i, v);
        v.pop_back();
    }

    return;
}

int main()
{
    FastIO();

    ip2(N, M);

    int map[55][55];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ip1(map[i][j]);
            if (map[i][j] == 1)
            {
                vH.push_back({ i, j });
            }
            else if (map[i][j] == 2)
            {
                vC.push_back({ i, j });
            }
        }
    }

    vector<int> v;
    Combination(-1, v);

    int answer = 987654321;
    for (vector<int> list : vLists)
    {
        int ans = 0;
        for (pii h : vH)
        {
            int minDist = 987654321;
            for (int idx : list)
            {
                int dist = abs(h.X - vC[idx].X) + abs(h.Y - vC[idx].Y);
                minDist = min(minDist, dist);
            }
            ans += minDist;
        }
        answer = min(answer, ans);
    }

    op1(answer);
}
