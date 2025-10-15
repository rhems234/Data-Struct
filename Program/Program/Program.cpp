#include <iostream>

using namespace std;

template <typename T>
class List {

private:
    struct Node {
        T data;
        Node* next;
    };

    int size;
    Node* head;

public:
    List() {
        size = 0;
        head = nullptr;
    }

    void push_front(T data) {
        Node* newnode = new Node;
        newnode->data = data;

        if (head == nullptr) {
            head == newnode;

            newnode->next = nullptr;
        }
        else {
            newnode->next = head;

            head = newnode;
        }
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "Linked List is Empty" << endl;
            return;
        }

        Node* deletenode = head;
        head = deletenode->next;

        size--;
        delete deletenode;
    }

    void push_back(T data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* currentNode = head;

            head->next = newNode;
        }
    }

};

int main()
{
    List<int> list;

    list.push_front(10);
    list.push_front(5);

    list.pop_front();
    list.pop_front();
    list.pop_front();

    return 0;
}
