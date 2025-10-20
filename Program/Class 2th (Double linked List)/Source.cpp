#include <iostream>

using namespace std;

// 양방향 연결 리스트
template<typename T>
class List {

private:

    struct Node {
        T data;
        Node* next;
        Node* previous;
    };

    Node* head;
    Node* tail;
    int size;

public:
    List() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_front(T data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->previous = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->previous = newNode;
        }
        else {
            tail = newNode;
        }

        head = newNode;
        size++;

    }

    void pop_front() {

        if (head == nullptr) {
            cout << "Linked List is Empty" << endl;
            return;
        }

        // deleteNode에 head 저장 -> 삭제할 노드 저장.
        Node* deleteNode = head;
        // head는 다음 메모리를 가르킴.
        head = head->next;

        if (head != nullptr) {
            // 이전 노드를 가리키고 있는 previous를 초기화 시켜줌.
            head->previous = nullptr;
        }
        else {
            // 리스트가 완전히 비었을 때 tail도 nullptr로 초기화하여 잘못된 주소 참조 방지.
            tail = nullptr;
        }

        //cout << "deleteNode result : " << deleteNode->data << endl;
        delete deleteNode;
        // delete 시 메모리도 같이 감소 시킴.
        size--;
    }

    void push_back(T data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        // 리스트가 비었을 경우
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        // 리스트에 노드가 있을 경우
        else {
            tail->next = newNode; // 기존 tail의 다음을 새 노드로 저장.
            newNode->previous = tail; // 새 노드의 이전을 기존 tail로 저장.
            tail = newNode; // tail을 새 노드로 갱신
        }

        /*cout << "head : " << head->data << endl;
        cout << "tail : " << tail->data << endl;*/
        size++;
    }

    void pop_back() {

        if (tail == nullptr) {
            cout << "Linked List is Empty" << endl;
            return;
        }

        // 삭제할 노드 지정 -> tail
        Node* deleteNode = tail;
        // tail에 이전 노드 ( previous ) 로 이동
        tail = tail->previous;

        if (tail != nullptr) {
            // 새 tail의 next를 초기화
            tail->next = nullptr;
        }
        else {
            // 리스트가 비었으면 head도 초기화
            head = nullptr;
        }

        //cout << "Delete Node : " << deleteNode->data << endl;
        delete deleteNode;
        size--;
    }

    const bool& empty() {
        return (head == nullptr);
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

    /*list.push_front(10);
    list.push_front(5);

    list.pop_front();
    list.pop_front();*/

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();

    return 0;
}
