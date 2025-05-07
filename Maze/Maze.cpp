#include <iostream>
#include "List.h"

int main()
{
	CaList list;
	list.AddAtHead(1);
	list.AddAtHead(2);
	list.AddAtHead(3);

	list.AddAtTail(4);
	list.AddAtTail(5);
	list.AddAtTail(6);

	list.Print();
}
