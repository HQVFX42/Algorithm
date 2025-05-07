#include <iostream>
#include "List.h"

int main()
{
	CaList list;
	list.AddAtHead(1);
	Node* temp1 = list.AddAtHead(2);
	list.AddAtHead(3);

	list.AddAtTail(4);
	Node* temp2 = list.AddAtTail(5);
	list.AddAtTail(6);

	list.Insert(temp1, 7);
	list.Remove(temp2);

	list.Print();
}
