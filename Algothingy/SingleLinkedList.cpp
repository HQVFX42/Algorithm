#include <bits/stdc++.h>
/**
 * Single Linked List.
 */

class Parent
{
public:
	virtual void Bar() = 0;
	virtual void BBB() = 0;

private:
	int a;
};

class Child : public Parent
{
public:
	void Bar() override {};
	void BBB() override {};

};

struct Node
{
	int Data;         // 노드의 데이터
	Node* Next;       // 다음 노드를 가리키는 포인터

	// 기본 생성자
	Node(int InData = 0) : Data(InData), Next(nullptr) {}
};

class LinkedList
{
private:
	Node* Head;      // 연결 리스트의 첫 번째 노드

public:
	LinkedList() : Head(nullptr) {}

	// 노드를 삽입하는 함수
	Node* Insert(int Data);

	// 노드를 삭제하는 함수
	Node* Remove(int Data);

	// 두 리스트를 연결하는 함수
	Node* Concatenate(LinkedList& OtherList);

	// 순회 포인터를 이용한 역순 함수
	Node* Reverse();
	Node* Reverse2();
	Node* ReverseRecursive(Node* head);

	// 리스트의 크기를 반환하는 함수
	int Size();

	// 리스트를 출력하는 함수
	void Display();
};

Node* LinkedList::Insert(int Data)
{
	Node* NewNode = new Node(Data);  // 새로운 노드 생성

	if (Head == nullptr)
	{
		Head = NewNode;
	}
	else
	{
		Node* Current = Head;
		while (Current->Next != nullptr)
		{
			Current = Current->Next;
		}
		Current->Next = NewNode;
	}

	return NewNode;
}

 Node* LinkedList::Remove(int Data)
 {
 	if (Head == nullptr)
 	{
 		return nullptr;  // 리스트가 비어 있을 경우
 	}

 	if (Head->Data == Data)
 	{
 		Node* Temp = Head;
 		Head = Head->Next;
 		delete Temp;
 		return nullptr;
 	}

 	Node* Current = Head;
 	while (Current->Next != nullptr)
 	{
 		if (Current->Next->Data == Data)
 		{
 			Node* Temp = Current->Next;
 			Current->Next = Current->Next->Next;
 			delete Temp;
 			return Current;
 		}
 		Current = Current->Next;
 	}

 	return nullptr;
 }

 Node* LinkedList::Concatenate(LinkedList& OtherList)
 {
	 if (Head == nullptr)
	 {
		 Head = OtherList.Head;
		 return Head;
	 }

	 if (OtherList.Head == nullptr)
	 {
		 return nullptr;  // 다른 리스트가 비어 있을 경우
	 }

	 Node* Current = Head;
	 while (Current->Next != nullptr)
	 {
		 Current = Current->Next;
	 }
	 Current->Next = OtherList.Head;
	 OtherList.Head = nullptr;            // 다른 리스트 초기화

	 return Current;
 }

 Node* LinkedList::Reverse()
 {
	 // 역순으로 변환할 때 사용할 이전 노드 포인터를 초기화
	 Node* Prev = nullptr;

	 // 현재 노드 포인터를 리스트의 첫 번째 노드로 설정
	 Node* Current = Head;

	 // 다음 노드 포인터를 초기화
	 Node* Next = nullptr;

	 // 리스트의 모든 노드를 순회
	 while (Current != nullptr)
	 {
		 // 현재 노드의 다음 노드를 임시로 저장
		 Next = Current->Next;

		 // 현재 노드의 다음 포인터를 이전 노드로 설정하여 역순으로 연결
		 Current->Next = Prev;

		 // 이전 노드를 현재 노드로 이동
		 Prev = Current;

		 // 현재 노드를 다음 노드로 이동
		 Current = Next;
	 }

	 // 리스트의 첫 번째 노드를 역순으로 변환된 리스트의 첫 번째 노드로 설정
	 Head = Prev;

	 // 역순으로 변환된 리스트의 첫 번째 노드를 반환
	 return Head;
 }

 Node * LinkedList::Reverse2()
 {
	 Head = ReverseRecursive(Head);
	 return Head;
 }

 Node* LinkedList::ReverseRecursive(Node* head)
 {
	 if (head == nullptr or head->Next == nullptr)
	 {
		 return head;
	 }

	 Node * NewHead = ReverseRecursive(head->Next);
	 head->Next->Next = head;
	 head->Next = nullptr;

	 return NewHead;
 }

 int LinkedList::Size()
 {
	 int Count = 0;
	 Node* Temp = Head;
	 while (Temp != nullptr)
	 {
		 Count++;
		 Temp = Temp->Next;
	 }
	 return Count;
 }

 void LinkedList::Display()
 {
	 Node* Temp = Head;
	 while (Temp != nullptr)
	 {
		 std::cout << Temp->Data << " ";
		 Temp = Temp->Next;
	 }
	 std::cout << std::endl;
 }


int main()
{
	LinkedList List1;
	LinkedList List2;

	List1.Insert(1);
	List1.Insert(2);
	List1.Insert(3);

	List2.Insert(4);
	List2.Insert(5);
	List2.Insert(6);

	std::cout << "List1: ";
	List1.Display();

	std::cout << "List2: ";
	List2.Display();

	std::cout << "Concatenated List: ";
	List1.Concatenate(List2);
	List1.Display();

	std::cout << "Reversed List: ";
	List1.Reverse();
	List1.Display();

	std::cout << "Reversed List: ";
	List1.Reverse2();
	List1.Display();

	Child f;

	std::cout << sizeof(f) << std::endl;

	return 0;
}
