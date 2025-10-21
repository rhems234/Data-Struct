#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
    T* pointer;
    int count;
    int capacity;

public:
    Vector() {
        pointer = nullptr;
        count = 0;
        capacity = 0;
    }

    void resize(int newsize) {
        // 1. capactiy에 새로운 size 값을 저장합니다.
        capacity = newsize;

        // 2. 새로운 포인터 변수를 생성해서 새롭게 만들어진 메모리 공간을 가리키도록 합니다.
        T* newpointer = new T[newsize];

        // 3. 새로운 메모리 공간의 값을 초기화합니다.
        for (int i = 0; i < newsize; i++) {
            newpointer[i] = T();
        }

        // 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣어줍니다.
        for (int i = 0; i < newsize ; i++) {
            newpointer[i] = pointer[i];
        }

        // 5. 기본 배열의 메모리를 해제합니다.
        delete[] pointer;

        // 6. 기존 배열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가리킵니다.
        pointer = newpointer;

        if (count > newsize) {
            count = newsize;
        }

    }

};

int main()
{
    Vector<int> vector;

    vector.resize(5);

    return 0;
}
