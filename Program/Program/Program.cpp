#include <iostream>

using namespace std;

// 원형 연결 리스트
template <typename T>
class List {

private:

	struct Node
	{
		T data;
		Node* next;
	};

	int size;
	Node* head;

public:

	List() {
		head = nullptr;
		size = 0;
	}

	void push_back(T data) {
		Node* newNode = new Node;
		newNode->data = data;
		
		// 리스트가 비었을 때 자기 자신을 가리키게 끔.
		if (head == nullptr) {
			head = newNode;
			newNode->next = head;
		}
		else {
			newNode->next = head->next;

			head->next = newNode;

			head = newNode;
		}
		cout << "result : " << newNode->data << endl;
		size++;

	}

	void push_front(T data) {
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr) {
			head = newNode;
			newNode->next = head;
		}
		else {
			newNode->next = head->next;
			head->next = newNode;
		}

		cout << "result : " << newNode->data << endl;
		size++;

	}

	void pop_front() {
		if (head == nullptr) {
			cout << "Linked List is Empty" << endl;
			return;
		}

		Node* deleteNode = new Node;
		deleteNode = head;
		head = head->next;



	}

};

int main()
{

	List<int> list;

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	list.push_front(40);
	list.push_front(50);
	list.push_front(60);

    return 0;
}
