#include <iostream>

using namespace std;

// 단방향 연결 리스트 
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

            while (currentNode->next != nullptr) {

                currentNode = currentNode->next;

            }

            currentNode->next = newNode;
        }

        size++;

    }

    void pop_back() {

        Node* deleteNode = head;
        Node* previousNode = nullptr;

        // 노드 값이 없을 경우 경고 메세지 출력
        if (head == nullptr) {
            cout << "Linked List is Empty" << endl;
            return;
        }

        // 노드가 하나일 경우 head 삭제 및 size 감소 후 초기화
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            size--;
            return;
        }

        // while문을 통해 리스트 검색
        // head -> 10 -> 20 -> 30 -> nullptr
        // previousNode가 deleteNode를 가리킬 경우에
        // deleteNode는 다음 값(deleteNode->next)을 가리킴
        while (deleteNode->next != nullptr) {
            previousNode = deleteNode;
            deleteNode = deleteNode->next;
        }

        previousNode->next = nullptr;
        delete deleteNode;
        size--;
    }

    const bool& empty() {
        return (head == nullptr);
    }

    ~List() {
        // currentNode -> head를 가리킴.
        // nextNode -> currentNode의 다음 주소를 저장.
        // currentNode 삭제 후 nextNode에 저장 된 currentNode->next 값을 저장.
        /*Node* currentNode = head;

        while (currentNode != nullptr) {
            Node* nextNode = currentNode->next;

            cout << "delete node : " << currentNode->data << endl;

            delete currentNode;
            currentNode = nextNode;
        }

        head = nullptr;*/

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
    list.push_back(40);
    list.push_back(50);
    list.push_back(60);

    cout << list.empty() << endl;

    //list.~List();

    /*list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();*/

    return 0;
}
