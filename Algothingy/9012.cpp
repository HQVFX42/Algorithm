#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	FastIO();

	int T = 0;
	cin >> T;

	while (T--)
	{
		stack<char> VPS;
		string S = "";
		cin >> S;

		for (int i = 0; i < S.size(); i++)
		{
			if (VPS.size() and VPS.top() == '(' and S[i] == ')')
			{
				VPS.pop();
			}
			else
			{
				VPS.push(S[i]);
			}
		}

		if (VPS.empty())
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}