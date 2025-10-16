#include <iostream>

using namespace std;

// 양방향 연결 리스트
template<typename T>
class List {

private :

    struct Node {
        T data;
        Node* next;
        Node* previous;
    };

    Node* head;
    Node* tail;
    int size;

public :
    List() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
};

int main()
{
    List<int> list;

    return 0;
}
