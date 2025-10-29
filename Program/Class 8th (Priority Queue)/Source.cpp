#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue {

private:
    int index;
    int capacity;
    T* container;
    int child;
    int parent;

public:
    PriorityQueue() {
        index = 0;
        capacity = 0;
        container = nullptr;
        child = 0;
        parent = 0;
    }

    void resize(int newsize) {
        capacity = newsize;

        T* newpointer = new T[capacity];

        for (int i = 0; i < capacity; i++) {
            newpointer[i] = NULL;
        }

        for (int i = 0; i < index; i++) {
            newpointer[i] = container[i];
        }

        delete[] container;

        container = newpointer;
    }

    void push(T data) {

        if (capacity == 0) {
            resize(1);
        }
        else if (capacity <= index) {
            resize(capacity * 2);
        }

        container[index] = data;

        child = index;

        parent = (child - 1) / 2;

        while (container[child] > container[parent]) {
            /*T temp = container[parent];
            container[parent] = container[child];
            container[child] = temp;*/

            std::swap(container[parent], container[child]);

            child = parent;
            parent = (child - 1) / 2;
        }

        index++;
    }

    ~PriorityQueue() {
        delete[] container;
    }

    const T& top() {
        if (container == nullptr) {
            exit(1);
        }

        return container[0];
    }

    const bool& empty() {
        return index == 0;
    }

};

int main()
{
    PriorityQueue<int> priorityqueue;

    priorityqueue.push(10);
    priorityqueue.push(20);
    priorityqueue.push(30);
    priorityqueue.push(60);
    priorityqueue.push(40);

    cout << priorityqueue.top() << endl;

    cout << priorityqueue.empty() << endl;

    return 0;
}
