#include <iostream>

struct Node
{
	int Data;
	Node* Next;
};

Node* head = nullptr;

void Push(int Value)
{
	Node* NewNode = new Node();
	NewNode->Data = Value;
	NewNode->Next = head;
	head = NewNode;
}

void Pop()
{
	if (head == nullptr)
	{
		std::cout << "Stack is empty" << std::endl;
		return;
	}

	Node* Temp = head;
	head = head->Next;
	delete Temp;
}

int main()
{
	Push(1);
	Push(2);
	Push(3);
	Pop();
	Pop();
	Pop();
	Pop(); // Stack is empty
	return 0;
}