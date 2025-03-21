#include <bits/stdc++.h>
/**
 * Single Linked List.
 */
struct Node
{
	int data;         // 노드의 데이터
	Node* next;       // 다음 노드를 가리키는 포인터
};

class LinkedList
{
private:
	Node* head;       // 연결 리스트의 첫 번째 노드

public:
	LinkedList() : head(nullptr) {}  // 기본 생성자

	// 연결 리스트에 노드를 삽입하는 함수
	void insert(int data);

	// 연결 리스트에서 노드를 삭제하는 함수
	void remove(int data);

	// 연결 리스트에서 특정 값을 검색하는 함수
	bool search(int data);

	// 연결 리스트를 출력하는 함수
	void display();
};

void LinkedList::insert(int data)
{
	Node* newNode = new Node();  // 새로운 노드 생성
	newNode->data = data;        // 데이터 할당
	newNode->next = head;        // 새로운 노드의 next 포인터를 현재 head로 설정
	head = newNode;              // head를 새로운 노드로 업데이트함
}

void LinkedList::remove(int data)
{
	if (head == nullptr) return;  // 리스트가 비어 있을 경우

	if (head->data == data)
	{     // 삭제할 노드가 head일 경우
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	Node* curr = head;
	while (curr->next != nullptr)
	{
		if (curr->next->data == data)
		{
			Node* temp = curr->next;
			curr->next = curr->next->next;
			delete temp;
			return;
		}
		curr = curr->next;
	}
}

bool LinkedList::search(int data)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->data == data) return true;
		temp = temp->next;
	}
	return false;
}

void LinkedList::display()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

int main() {
	LinkedList list;

	// 노드 삽입
	list.insert(6);
	list.insert(9);
	list.insert(1);
	list.insert(3);
	list.insert(7);

	std::cout << "Current list: ";
	list.display();

	// 노드 삭제
	std::cout << "Remove 1: ";
	list.remove(1);
	list.display();

	// 값 검색
	std::cout << "Search 7: " << (list.search(7) ? "true" : "false") << std::endl;
	std::cout << "Search 13: " << (list.search(13) ? "true" : "false") << std::endl;

	return 0;
}