#include <iostream>

using namespace std;

template <typename T>
class Stack {
private :
    int capacity;
    int highset;
    T* container;

public :

    Stack() {
        capacity = 0;
        highset = -1;
        container = nullptr;
    }

    void resize(int newsize) {
        // 1. capactiy에 새로운 size 값을 저장합니다.
        capacity = newsize;

        // 2. 새로운 포인터 변수를 생성해서 새롭게 만들어진 메모리 공간을 가리키도록 합니다.
        T* newpointer = new T[capacity];

        // 3. 새로운 메모리 공간의 값을 초기화합니다.
        for (int i = 0; i < capacity; i++) {
            newpointer[i] = NULL;
        }

        // 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣어줍니다.
        for (int i = 0; i < highset; i++) {
            newpointer[i] = container[i];
        }


        // 5. 기본 배열의 메모리를 해제합니다.
        delete[] container;

        // 6. 기존 배열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가리킵니다.
        container = newpointer;
    }

    void push(T data) {
        
        if (capacity == 0) {
            resize(1);
        }
        else if (highset + 1 >= capacity) {
            resize(capacity * 2);
        }

        highset++;
        container[highset] = data;

    }

};

int main()
{

    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    return 0;
}
