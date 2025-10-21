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
		//cout << "result : " << newNode->data << endl;
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

		//cout << "result : " << newNode->data << endl;
		size++;

	}

	void pop_front() {
		if (head == nullptr) {
			cout << "Linked List is Empty" << endl;
			return;
		}

		Node* deleteNode = head->next;

		if (head == head->next) {
			head = nullptr;
		}
		else {
			head->next = deleteNode->next;
		}

		//cout << "result : " << deleteNode->data << endl;

		delete deleteNode;

		size--;

	}

	void pop_back() {
		if (head == nullptr) {
			cout << "Linked List is Empty" << endl;
			return;
		}

		Node* deleteNode = head;
		Node* currentNode = head;

		if (head == head->next) {
			head = nullptr;
		}
		else {
			for (int i = 0; i < size - 1; i++) {
				currentNode = currentNode->next;
			}

			currentNode->next = head->next;
			head = currentNode;
		}

		delete deleteNode;
		size--;
	}

	const bool& empty() {
		return head == nullptr;
	}

	~List() {
		while (head != nullptr) {
			pop_front();
		}
	}

};

int main()
{

	List<int> list;

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();

	return 0;
}
