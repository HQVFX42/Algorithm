#pragma once
#include <iostream>

class Node
{
	using T = int;
public:
	Node(T data)
		: data(data), prev(nullptr), next(nullptr) {}

public:
	T data;
	Node* prev;
	Node* next;
};

class CaList
{
public:
	CaList()
	{
		_head = new Node(0);
		_tail = new Node(0);
		_head->next = _tail;
		_tail->prev = _head;
	}
	~CaList()
	{
		Node* node = _head;
		while (node)
		{
			Node* temp = node;
			node = node->next;
			delete temp;
		}
	}

	void Print()
	{
		Node* node = _head->next;
		while (node != _tail)
		{
			std::cout << node->data << " ";
			node = node->next;
		}
		std::cout << std::endl;
	}

	Node* AddAtHead(int data)
	{
		/* Without dummy pointer */
		/* [head]	[node]	[temp]	[2]	[3]		[tail] */
		//Node* node = new Node(data);
		//if (!_head)
		//{
		//	_head = node;
		//	_tail = node;
		//}
		//else
		//{
		//	Node* temp = _head;
		//	node->next = temp;
		//	temp->prev = node;
		//	_head = node;
		//}

		/* With dummy pointer */
		/* [dummy]	[node]	[temp]	[2]	[3]		[dummy]*/
		/* [head]								[tail] */
		Node* node = new Node(data);
		Node* temp = _head->next;
		 
		node->next = temp;
		temp->prev = node;
		_head->next = node;
		node->prev = _head;

		return node;
	}

	Node* AddAtTail(int data)
	{
		/* With dummy pointer */
		/* [dummy]	[1]	[2]	[3]	[temp]	[node]	[dummy]*/
		/* [head]								[tail] */
		Node* node = new Node(data);
		Node* temp = _tail->prev;

		temp->next = node;
		node->prev = temp;
		node->next = _tail;
		_tail->prev = node;

		return node;
	}


private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
	int size;
};

