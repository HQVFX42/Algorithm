#include <iostream>
#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include <vector>
#include <queue>

struct Vertex
{
	int data;
};

std::vector<Vertex> vertices;
std::vector<std::vector<int>> adjList;
std::vector<bool> visited;
std::vector<bool> discovered;

void CreateGraph()
{
	vertices.resize(7);

	adjList = std::vector<std::vector<int>>(7, std::vector<int>(7, -1));
	adjList[0][1] = adjList[1][0] = 15;
	adjList[0][3] = adjList[3][0] = 35;
	adjList[0][6] = adjList[6][0] = 100;
	adjList[1][2] = adjList[2][1] = 5;
	adjList[1][3] = adjList[3][1] = 10;
	adjList[3][4] = adjList[4][3] = 10;
	adjList[4][5] = adjList[5][4] = 10;
	adjList[5][6] = adjList[6][5] = 10;
}

struct VertexCost
{
	VertexCost(int cost, int vertex)
		: cost(cost), vertex(vertex)
	{
	}

	bool operator<(const VertexCost& other) const
	{
		return cost < other.cost;
	}

	bool operator>(const VertexCost& other) const
	{
		return cost > other.cost;
	}

	int cost;
	int vertex;
};

void Dijikstra(int here)
{
	// 최소 경로를 찾기 위한 우선순위 큐
	std::priority_queue<VertexCost, std::vector<VertexCost>, std::greater<VertexCost>> pq;
	// 발견한 케이스 중 가장 작은 비용을 저장하기 위한 벡터
	std::vector<int> best(vertices.size(), INT_MAX);
	// 방문한 정점들을 저장하기 위한 벡터
	std::vector<int> parent(vertices.size(), -1);

	pq.push(VertexCost(0, here));
	best[here] = 0;
	parent[here] = here;

	while (!pq.empty())
	{
		// 제일 좋은 후보 찾기
		VertexCost vc = pq.top();
		pq.pop();
		
		int cost = vc.cost;
		here = vc.vertex;

		// 더 짧은 경로를 찾았다면
		if (best[here] < cost)
		{
			continue;
		}
		std::cout << "Vertex: " << here << std::endl;

		for (int there = 0; there < vertices.size(); there++)
		{
			// 연결된 정점이 아니면 패스
			if (adjList[here][there] == -1)
			{
				continue;
			}

			// 더 좋은 경로를 과거에 찾았으면 패스
			int nextCost = best[here] + adjList[here][there];
			if (nextCost >= best[there])
			{
				continue;
			}

			// 지금까지 찾은 경로중에서 최선 수치 갱신
			best[there] = nextCost;
			parent[there] = here;
			pq.push(VertexCost(nextCost, there));
		}
	}
}


int main()
{
	//SetCursorOnOff(false);

	//while (true)
	//{
	//	// Input
	//	HandleKeyInput();

	//	// Logic
	//	HandleMove();

	//	// Output
	//	PrintMap2D();
	//}

	CreateGraph();

	Dijikstra(0);
}
