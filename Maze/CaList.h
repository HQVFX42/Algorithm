#pragma once
#include <iostream>

template<typename T>
class Node
{
	//using T = int;
public:
	Node(T data)
		: data(data), prev(nullptr), next(nullptr) {}

public:
	T data;
	Node* prev;
	Node* next;
};

template<typename T>
class CaList
{
public:
	CaList()
	{
		_head = new Node<T>(0);
		_tail = new Node<T>(0);
		_head->next = _tail;
		_tail->prev = _head;
	}
	~CaList()
	{
		Node<T>* node = _head;
		while (node)
		{
			Node* temp = node;
			node = node->next;
			delete temp;
		}
	}

	Node<T>* GetNode(int index)
	{
		Node<T>* node = _head->next;
		if (node == _tail)
		{
			return nullptr;
		}

		for (int i = 0; i < index; i++)
		{
			if (node == _tail->prev)
			{
				return nullptr;
			}

			node = node->next;
		}

		return node;
	}

	void Print()
	{
		Node<T>* node = _head->next;
		while (node != _tail)
		{
			std::cout << node->data << " ";
			node = node->next;
		}
		std::cout << std::endl;
	}

	Node<T>* AddAtHead(int data)
	{
		/** Without dummy pointer */
		/** [head]	[node]	[temp]	[2]	[3]	[tail] */
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

		/** With dummy pointer */
		/** [dummy]	[node]	[temp]	[2]	[3]	[dummy] */
		/** [head]							[tail]  */
		Node<T>* node = new Node<T>(data);
		Node<T>* temp = _head->next;
		 
		node->next = temp;
		temp->prev = node;
		_head->next = node;
		node->prev = _head;

		return node;
	}

	Node<T>* AddAtTail(int data)
	{
		/** [dummy]	[1]	[2]	[temp]	[node]	[dummy] */
		/** [head]							[tail]  */
		Node<T>* node = new Node<T>(data);
		Node<T>* temp = _tail->prev;

		temp->next = node;
		node->prev = temp;
		node->next = _tail;
		_tail->prev = node;

		return node;
	}

	void Insert(Node<T>* posNode, int data)
	{
		/**					[node]					*/
		/** [dummy]	[prevN]		 [posNode]	[dummy]	*/
		/** [head]							[tail] 	*/
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = posNode->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
	}

	Node<T>* Remove(Node<T>* node)
	{
		/**					[node]					*/
		/** [dummy]	[prevN]		 [nextN]	[dummy]	*/
		/** [head]							[tail] 	*/
		Node* prevNode = node->prev;
		Node* nextNode = node->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		return nextNode;
	}

private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
};

