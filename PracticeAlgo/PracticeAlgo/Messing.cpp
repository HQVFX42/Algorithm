#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

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

struct NodeV
{
	int color; // ���� �� (0: ���, 1: ������, 2: �Ķ���)
	vector<int> adj; // ������ ���� ��ȣ
};

vector<NodeV> nodes;
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

map<int, vector<int>> g;
set<int> visited;

int dfs(int depth, set<int>& visited)
{
	int cnt = 1;
	visited.insert(depth);
	for (auto& i : g[depth])
	{
		if (!visited.count(i))
		{
			cnt += dfs(i, visited);
		}
	}

	return cnt;
}

class A
{
public:
	A();
	~A();

	virtual void print();

private:

};

A::A()
{
	cout << "A()\n";
}

A::~A()
{
	cout << "~A()\n";
}

void A::print()
{
	cout << "AAA\n";
}

class B : A
{
public:
	B();
	~B();

	virtual void print();

private:

};

B::B()
{
	cout << "B()\n";
}

B::~B()
{
	cout << "~B()\n";
}

void B::print()
{
	cout << "BBB\n";
}

int main()
{
	//fastIO();
	A* ptrA = new A;
	B* ptrB = new B;

	ptrA->print();
	ptrB->print();

	//delete ptrA;
	delete ptrB;
}


/*
10 3
21 88
23 75
97 35
2 8
67 9
64 75
65 71
70 98
9 71
60 35

10
abcd
abcde
sdkfkkoxcc
dkfuds
kdgugs
dkfdu
dsf
dkjfgusdgg
dkdkfdufd
kkoxcc
*/