#include <iostream>

using namespace std;

#define SIZE 4

// 원형 큐
template <typename T>
class Queue {
private:

    int rear;
    int front;
    T container[SIZE];
    
public:

    Queue() {
        rear = SIZE - 1;
        front = SIZE - 1;
        for (int i = 0; i < SIZE; i++) {
            container[i] = NULL;
        }
        
    }

    void push(T data) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is Full." << endl;
            return;
        }

        rear = (rear + 1) % SIZE;
        container[rear] = data;

        cout << "Data : " << container[rear] << endl;
    }

    void pop() {
        if (rear == front) {
            cout << "Queue is empty." << endl;
            return;
        }

        front = (front + 1) % SIZE;
        container[front] = NULL;

    }

    const T& peek() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            exit(1);
        }

        return container[(front + 1) % SIZE];
    }

    const bool& empty() {
        return rear == front;
    }

    const int& size() {
        return (rear - front + SIZE) % SIZE;
    }

};

int main()
{
    Queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    cout << "Queue Size : " << queue.size() << endl;
    
    while (queue.empty() == false) {
        cout << queue.peek() << endl;

        queue.pop();
    }

    cout << "Queue Size : " << queue.size() << endl;

    queue.push(40);
    queue.push(50);
    queue.push(60);

    return 0;
}
