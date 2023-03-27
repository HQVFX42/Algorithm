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

vector<string> Candidates;

void Eliminate(string s, int a, int b) 
{
	for (int i = 0; i < Candidates.size(); i++)
	{
		int CntA = 0, CntB = 0;
		for (int j = 0; j < 4; j++) 
		{
			if (Candidates[i][j] == s[j])
			{
				CntA++;
			}
			else if (s.find(Candidates[i][j]) != string::npos)
			{
				CntB++;
			}
		}
		if (CntA != a || CntB != b)
		{
			Candidates.erase(Candidates.begin() + i);
			i--;
		}
	}
}

int main() {
	string Consonants = "bdgnprst";
	string Vowels = "aeiou";

	for (int i = 0; i < Consonants.size(); i++)
	{
		for (int j = 0; j < Vowels.size(); j++)
		{
			for (int k = 0; k < Consonants.size(); k++)
			{
				for (int l = 0; l < Vowels.size(); l++)
				{
					if (Consonants[i] != Consonants[k] && Vowels[j] != Vowels[l])
					{
						Candidates.push_back(string(1, Consonants[i]) + Vowels[j] +Consonants[k] + Vowels[l]);
					}
				}
			}
		}
	}

	int n;
	cin >> n;

	while (n--) 
	{
		string s;
		int a, b;
		cin >> s >> a >> b;

		Eliminate(s, a, b);
	}

	if (Candidates.size() == 0)
	{
		cout << "x" << '\n';
	}
	else if (Candidates.size() == 1)
	{
		cout << Candidates[0] << '\n';
	}
	else 
	{
		cout << "x" << '\n';
	}

	return 0;
}

/*
7
roga 1 1
rase 0 1
poru 0 1
gipa 0 1
dego 3 0
bego 3 0
nego 3 0
*/