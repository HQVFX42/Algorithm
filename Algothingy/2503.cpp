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

int n, question, strike, ball;
vector<vector<int>> hint;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> question >> strike >> ball;
		hint.push_back({ question, strike, ball });
	}

	int ans = 0;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 9; k++)
			{
				if (i == j or j == k or k == i)
				{
					continue;
				}

				int cnt = 0;
				for (auto & arr : hint)
				{
					int number = arr[ 0 ];
					int strike = arr[ 1 ];
					int ball = arr[ 2 ];

					int strikeCnt = 0;
					int ballCnt = 0;

					int n1 = to_string(number)[ 0 ] - '0';
					int n2 = to_string(number)[ 1 ] - '0';
					int n3 = to_string(number)[ 2 ] - '0';
					if (i == n1)
					{
						strikeCnt++;
					}
					if (j == n2)
					{
						strikeCnt++;
					}
					if (k == n3)
					{
						strikeCnt++;
					}

					if (i == n2 or i == n3)
					{
						ballCnt++;
					}
					if (j == n3 or j == n1)
					{
						ballCnt++;
					}
					if (k == n1 or k == n2)
					{
						ballCnt++;
					}

					if (strike == strikeCnt and ball == ballCnt)
					{
						cnt++;
					}
				}

				if (cnt == n)
				{
					ans++;
				}
			}
		}
	}

	op1l(ans);
}
