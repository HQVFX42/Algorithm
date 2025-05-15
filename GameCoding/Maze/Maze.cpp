#include"pch.h"
#include "Board.h"
#include "Player.h"
#include "CaStack.h"
#include "CaQueue.h"
#include "CaTree.h"
#include "CaPriorityQueue.h"

Board board;
Player player;

// 인접리스트 : 실제로 연결된 노드`만` 저장하는 방법
void CreateGraph()
{
	struct Vertex
	{
		int data;
	};

	std::vector<Vertex> vertices;
	std::vector<std::vector<int>> adjList;
	adjList.resize(5);
	adjList[0] = { 1, 3 };
	adjList[1] = { 0, 2, 3 };
	adjList[2] = { 1, 4 };
	adjList[3] = { 0, 1 };
	adjList[4] = { 2 };

	bool bConnected = false;
	int size = adjList[0].size();
	for (int i = 0; i < size; i++)
	{
		if (adjList[0][i] == 4)
		{
			bConnected = true;
			break;
		}
	}

	std::cout << "Is 4 connected? " << (bConnected ? "Yes" : "No") << std::endl;
}

// 인접행렬: 모든 노드에 대해 연결된 노드`모두`를 저장하는 방법
void CreateGraph2()
{
	// adj[from][to]
	// 메모리 사용량이 많지만 빠른 접근이 가능
	std::vector<std::vector<bool>> adjMatrix(6, std::vector<bool>(6, false));
	adjMatrix[0][1] = true;
	adjMatrix[0][3] = true;
	adjMatrix[1][0] = true;
	adjMatrix[1][2] = true;
	adjMatrix[1][3] = true;
	adjMatrix[2][1] = true;

	std::vector<std::vector<int>> adjMatrix2 =
	{
		{-1, 11, -1, 15, -1 },
		{ 1, -1, 1, 5, -1 },
		{ -1, 2, -1, -1, -1 },
		{ -1, -1, -1, -1, -1 },
		{ -1, -1, 3, -1, -1 }
	};

	bool bConnected = adjMatrix[0][3];
	std::cout << "Is 4 connected? " << (bConnected ? "Yes" : "No") << std::endl;

}

int main()
{
	//::srand(static_cast<uint32>(time(nullptr)));

	//board.Init(25, &player);
	//player.Init(&board);

	//uint64 lastTick = 0;
	//while (true)
	//{
	//	const uint64 currentTick = ::GetTickCount64();
	//	const uint64 deltaTick = currentTick - lastTick;
	//	lastTick = currentTick;

	//	// Input

	//	// Logic
	//	player.Update(deltaTick);

	//	// Render
	//	board.Render();
	//}

	CaTree tree;
	Node* root = tree.CreateTree();
	tree.PrintTree(root);
	std::cout << "Depth: " << tree.GetDepth(root) << std::endl;

	//CreateGraph();
	//CreateGraph2();

	// 탐색방법
	// vector : 순회
	// tree : 재귀
	// graph : DFS, BFS
}
