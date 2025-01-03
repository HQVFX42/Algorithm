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

int n;
vector<pair<int, int>> arr;
vector<int> arrX, arrY;

int main()
{
	FastIO();

    cin >> n;


    vector<int> answer(n, -1);

    // 입력 받기
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a, b });
        arrY.push_back(a);
        arrX.push_back(b);
    }

    // 만날 장소 정하기
    for (int y : arrX)
    {
        for (int x : arrY)
        {
            vector<int> dist;

            // 만날 장소로 각각의 점들이 오는 비용 계산하기
            for (auto [ex, ey] : arr)
            {
                int d = abs(ex - x) + abs(ey - y);
                dist.push_back(d);
            }

            // 가까운 순서대로 정렬하기
            sort(dist.begin(), dist.end());

            int tmp = 0;
            for (int i = 0; i < dist.size(); i++)
            {
                tmp += dist[ i ];
                if (answer[ i ] == -1)
                {
                    answer[ i ] = tmp;
                }
                else
                {
                    answer[ i ] = min(tmp, answer[ i ]);
                }
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++)
    {
        cout << answer[ i ] << " ";
    }
    cout << endl;

    return 0;
}
