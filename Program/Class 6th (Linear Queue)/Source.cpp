#include <iostream>

using namespace std;

#define SIZE 5

// Queue -> First In First Out
template <typename T>
class Queue {

private:
    int front;
    int rear;
    T container[SIZE];

public:
    Queue() {
        front = 0;
        rear = 0;

        for (int i = 0; i < SIZE; i++) {
            container[i] = NULL;
        }
    }

    void push(T data) {
        if (rear == SIZE) {
            cout << "Linear Queue overflow" << endl;
            return;
        }

        container[rear++] = data;

    }

    void pop() {
        if (empty()) {
            cout << "Queue is Empty" << endl;
        }
        else {
            //cout << "delete : " << container[front] << endl;

            container[front] = NULL;
            front++;
        }
    }

    const bool& empty() {
        return front == rear;
    }

    // 가장 앞 데이터 출력
    const T& peek() {
        if (empty()) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }

        return container[front];
    }

    const int& size() {
        return rear - front;
    }

};

int main()
{

    Queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);

    while (queue.empty() == false) {
        cout << queue.peek() << endl;

        queue.pop();
    }

    cout << "Queue Size : " << queue.size() << endl;

    return 0;
}
