//P4
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int BFS(int Start, unordered_map<int, unordered_set<int>>& Graph, unordered_set<int>& Visited)
{
	queue<int> Q;
	Q.push(Start);
	Visited.insert(Start);
	int Size = 0;

	while (!Q.empty())
	{
		int Node = Q.front();
		Q.pop();
		Size++;

		for (int Edge : Graph[Node])
		{
			if (Visited.find(Edge) == Visited.end())
			{
				Visited.insert(Edge);
				Q.push(Edge);
			}
		}
	}

	return Size;
}

int main() {
	int E, N;
	cin >> E >> N;

	unordered_map<int, unordered_set<int>> Graph;

	for (int i = 0; i < E; ++i)
	{
		int U;
		int V;
		cin >> U >> V;
		Graph[U].insert(V);
		Graph[V].insert(U);
	}

	unordered_set<int> Visited;
	int Answer = 0;

	for (const auto& Root : Graph)
	{
		int Node = Root.first;
		if (Visited.find(Node) == Visited.end())
		{
			int Size = BFS(Node, Graph, Visited);
			if (Size <= N)
			{
				Answer += Size;
			}
		}
	}

	cout << Answer << endl;

	return 0;
}