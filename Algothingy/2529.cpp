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

const int MX = 10;
int k, vis[ MX ];
char c[ MX ];
vector<string> ans;

bool IsValid(char x, char y, char op)
{
	if (x < y and op == '<')
	{
		return true;
	}
	if (x > y and op == '>')
	{
		return true;
	}
	return false;
}

void DFS(int idx, string num)
{
	if (idx == k + 1)
	{
		ans.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (vis[ i ])
		{
			continue;
		}
		if (idx == 0 or IsValid(num[ idx - 1 ], i + '0', c[ idx - 1 ]))
		{
			vis[ i ] = 1;
			DFS(idx + 1, num + to_string(i));
			vis[ i ] = 0;
		}
	}
}

int main()
{
	FastIO();

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> c[ i ];
	}

	DFS(0, "");

	sort(ans.begin(), ans.end());

	op1l(ans[ ans.size() - 1 ]);
	op1l(ans[ 0 ]);
}
