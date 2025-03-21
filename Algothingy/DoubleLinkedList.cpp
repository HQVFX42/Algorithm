#include <bits/stdc++.h>

struct Node
{
    int data;         // 노드의 데이터
    Node* prev;       // 이전 노드를 가리키는 포인터
    Node* next;       // 다음 노드를 가리키는 포인터
};

class DoubleLinkedList
{
private:
    Node* head;       // 연결 리스트의 첫 번째 노드
    Node* tail;       // 연결 리스트의 마지막 노드

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}  // 기본 생성자

    // 연결 리스트에 노드를 삽입하는 함수
    void insertAtHead(int data);
    void insertAtTail(int data);

    // 연결 리스트에서 노드를 삭제하는 함수
    void removeAtHead();
    void removeAtTail();
    void remove(int data);

    // 연결 리스트에서 특정 값을 검색하는 함수
    bool search(int data);

    // 연결 리스트를 출력하는 함수
    void displayForward();
    void displayBackward();
};

void DoubleLinkedList::insertAtHead(int data)
{
    Node* newNode = new Node();  // 새로운 노드 생성
    newNode->data = data;        // 데이터 할당

    if (head == nullptr)
    {       // 리스트가 비어 있을 경우
        head = newNode;
        tail = newNode;
        newNode->prev = nullptr;
        newNode->next = nullptr;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = nullptr;
        head = newNode;
    }
}

void DoubleLinkedList::insertAtTail(int data)
{
    Node* newNode = new Node();  // 새로운 노드 생성
    newNode->data = data;        // 데이터 할당

    if (tail == nullptr)
    {       // 리스트가 비어 있을 경우
        head = newNode;
        tail = newNode;
        newNode->prev = nullptr;
        newNode->next = nullptr;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        newNode->next = nullptr;
        tail = newNode;
    }
}

void DoubleLinkedList::removeAtHead() {
    if (head == nullptr) return;  // 리스트가 비어 있을 경우

    if (head == tail)
    {           // 리스트에 노드가 하나만 있을 경우
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

void DoubleLinkedList::removeAtTail() {
    if (tail == nullptr) return;  // 리스트가 비어 있을 경우

    if (head == tail)
    {           // 리스트에 노드가 하나만 있을 경우
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

void DoubleLinkedList::remove(int data)
{
    if (head == nullptr) return;  // 리스트가 비어 있을 경우

    if (head->data == data)
    {     // 삭제할 노드가 head일 경우
        removeAtHead();
        return;
    }

    if (tail->data == data)
    {     // 삭제할 노드가 tail일 경우
        removeAtTail();
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
    {
        if (curr->next->data == data)
        {
            Node * temp = curr->next;
            curr->next = curr->next->next;
            if (curr->next != nullptr)
            {
                curr->next->prev = curr;
            }
            else
            {
                tail = curr;
            }
            delete temp;
            return;
        }
        curr = curr->next;
    }
}

bool DoubleLinkedList::search(int data)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        if (temp->data == data) return true;
        temp = temp->next;
    }
    return false;
}

void DoubleLinkedList::displayForward()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void DoubleLinkedList::displayBackward()
{
    Node* temp = tail;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << std::endl;
}
