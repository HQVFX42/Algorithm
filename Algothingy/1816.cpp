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
#define op2l(a) cout << a << ' ' << b << '\n'

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n;
ll s;

bool Check(ll n)
{
	for (int i = 2; i <= 1000000; i++)
	{
		if (n % i == 0)		// 100만 이하의 약수가 존재한다
		{
			return false;
		}
		if (i == 1000000)	// 100만 이하의 약수가 존재하지 않는다
		{
			return true;
		}
	}
}

int main()
{
	FastIO();

	cin >> n;
	while (n--)
	{
		cin >> s;
		if (Check(s))
		{
			op1l("YES");
		}
		else
		{
			op1l("NO");
		}
	}
}
