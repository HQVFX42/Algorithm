#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX = 111;
int graph[MAX][MAX];
int vis[MAX][MAX];
string a[MAX];

string split(string input, string delimiter)
{
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);

	string output;
	for (auto& i : ret)
	{
		output += i;
	}
	return output;
}

struct Node
{
	int color; // 방의 색 (0: 흰색, 1: 빨간색, 2: 파란색)
	vector<int> adj; // 인접한 방의 번호
};

vector<Node> nodes;
int n, m, res;

int bfs(int start)
{
	queue<int> q;
	vector<bool> visited(n + 1, false);
	int Cnt = 0;
	q.push(start);
	visited[start] = true;
	nodes[start].color = 1;
	Cnt++;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : nodes[cur].adj)
		{
			if (!visited[next])
			{
				if (nodes[cur].color == 1)
				{
					nodes[next].color = 2;
				}
				else if (nodes[cur].color == 2)
				{
					nodes[next].color = 1;
					Cnt++;
				}

				q.push(next);
				visited[next] = true;
			}
		}
	}

	return Cnt;
}

void dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (OOB(nx, ny, n, m))
		{
			continue;
		}
		if (graph[nx][ny] == 1 and vis[nx][ny] == 0)
		{
			dfs(nx, ny);
		}
	}
	return;

}

int dfsI(int x, int y)
{
	int res = 1;

	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (OOB(nx, ny, m, n))
		{
			continue;
		}
		if (graph[nx][ny] == 1 or vis[nx][ny] == 1)
		{
			continue;
		}
		res += dfsI(nx, ny);
	}
	return res;
}

bool Check(int d, int x, int y)
{
	for (int i = x; i < x + d; i++)
	{
		for (int j = y; j < y + d; j++)
		{
			if (a[i][j] != a[x][y])
			{
				return false;
			}
		}
	}
	return true;
}
void dfs(int d, int x, int y)
{
	if (Check(d, x, y))
	{
		cout << a[x][y];
		return;
	}

	cout << '(';
	float divide = 0.5;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dfs(d * divide, x + i * d * divide, y + j * d * divide);
		}
	}
	cout << ')';
}

int d[111111];

int main()
{
	int N, Q;
	string M;
	vector<pii> cuts;

	cin >> N >> M >> Q;
	if (M[0] == '*')
	{
		d[0] = 0;
	}
	else
	{
		d[0] = M[0] - '0';
	}

	for (int i = 1; i < M.size(); i++)
	{
		if (M[i] == '*')
		{
			d[i] = d[i - 1];
		}
		else
		{
			d[i] = d[i - 1] + (M[i] - '0');
		}
	}
	for (int i = 0; i < Q; i++)
	{
		int ret = 0;
		int start;
		int end;
		cin >> start >> end;
		string tmp = M.substr(start, end - start + 1);
		int st = start + tmp.find_first_of('*');
		int en = start + tmp.find_last_of('*');
		ret = d[en] - d[st];

		cout << ret << '\n';
	}

	return 0;
}

/*
20
111*213*22*3*132**12
4
3 8
10 18
0 11
4 9
*/