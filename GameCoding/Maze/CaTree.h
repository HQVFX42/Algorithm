#pragma once

#include <vector>

class Node
{
public:
	Node(const char* data)
		: data(data)
	{

	}

public:
	const char* data;
	std::vector<Node*> children;
};

class CaTree
{
public:
	Node* CreateTree()
	{
		Node* root = new Node("root");
		{
			Node* node = new Node("Team1");
			root->children.push_back(node);
			{
				Node* leaf = new Node("leaf1");
				node->children.push_back(leaf);
			}
			{
				Node* leaf = new Node("leaf2");
				node->children.push_back(leaf);
			}
			{
				Node* leaf = new Node("leaf3");
				node->children.push_back(leaf);
			}
		}
		{
			Node* node = new Node("Team2");
			root->children.push_back(node);
			{
				Node* leaf = new Node("leaf1");
				node->children.push_back(leaf);
				{
					Node* ll = new Node("leaf1-1");
					leaf->children.push_back(ll);
					{
						Node* lll = new Node("leaf1-1-1");
						ll->children.push_back(lll);
					}
					{
						Node* lll = new Node("leaf1-1-2");
						ll->children.push_back(lll);
					}
				}
			}
			{
				Node* leaf = new Node("leaf2");
				node->children.push_back(leaf);
			}
		}
		{
			Node* node = new Node("Team3");
			root->children.push_back(node);
			{
				Node* leaf = new Node("leaf1");
				node->children.push_back(leaf);
			}
			{
				Node* leaf = new Node("leaf2");
				node->children.push_back(leaf);
				{
					Node* ll = new Node("leaf2-1");
					leaf->children.push_back(ll);
				}
			}
			{
				Node* leaf = new Node("leaf3");
				node->children.push_back(leaf);
			}
			{
				Node* leaf = new Node("leaf4");
				node->children.push_back(leaf);
			}
		}

		return root;
	}

	// depth : root에서 node까지 가는 edge의 개수
	void PrintTree(Node* root, int depth = 0)
	{
		for (int i = 0; i < depth; i++)
		{
			std::cout << "--";
		}

		std::cout << root->data << std::endl;

		for (Node* child : root->children)
		{
			PrintTree(child, depth + 1);
		}
	}

	// 재귀를 이용하여 최하단 자식의 depth를 return
	int GetDepth(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int maxDepth = 0;
		for (Node* child : root->children)
		{
			int childDepth = GetDepth(child);
			if (maxDepth < childDepth)
			{
				maxDepth = childDepth;
			}
		}

		return maxDepth + 1;
	}
};

