#include <iostream>

using namespace std;

template<typename KEY, typename VALUE>
class HashTable {
private :
    struct Node {
        KEY key;
        VALUE value;

        Node* next;
    };

    struct Bucket {
        int count;
        Node* head;
    };

    int size;
    int capacity;

    Bucket* bucket;

public:
    HashTable() {
        size = 0;
        capacity = 8;

        bucket = new Bucket[capacity];

        for (int i = 0; i < capacity; i++) {
            bucket[i].head = nullptr;
            bucket[i].count = 0;
        }
    }

    template<typename KEY>
    unsigned int hash_function(KEY key) {
        return (unsigned int)key % capacity;
    }

    template<>
    unsigned int hash_function(const char * key) {
        int sum = 0;

        for (int i = 0; *key != '\0'; i++) {
            sum += key[i];

            key = key + 1;
        }

        return (unsigned int)sum % capacity;
    }

    void insert(KEY key, VALUE value) {
        // 해시 함수를 통해서 저장하는 임시 변수.
        unsigned int index = hash_function(key);

        // 새로운 노드 생성.
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;

        // 노드가 1개라도 존재하지 않는다면
        if (bucket[index].count == 0) {
            bucket[index].head = newNode;
        }
        else {
            newNode->next = bucket[index].head;
            bucket[index].head = newNode;
        }
        // bucket[index]의 count를 증가시킵니다.
        bucket[index].count++;
    }

    void erase(KEY key) {
        // 해시 함수를 통해서 값을 받는 임시 변수.
        int index = hash_function(key);

        // Node를 탐색할 수 있는 포인터 변수.
        Node* currentNode = bucket[index].head;

        // 이전 Node를 저장 할 수 있는 포인터 변수 선언.
        Node* prevNode = nullptr;

        // currentNode가 nullptr과 같다면 함수를 종료합니다.
        if (prevNode == nullptr) {
            cout << "Not key found..." << endl;
        } 
        else {
           // currentNode를 이용해서 내가 찾고자 하는 key값을 찾습니다.
            while (currentNode != nullptr) 
            {
                if (currentNode->key == key) 
                {
                    if (currentNode == bucket[index].head) 
                    {
                        bucket[index].head = currentNode->next;
                    }
                    else 
                    {
                        prevNode->next = currentNode->next;
                    }

                    size--;

                    bucket[index].count--;

                    delete currentNode;

                    return;
                }
                else {
                    prevNode = currentNode;

                    currentNode = currentNode->next;
                }
            }

            cout << "not key found..." << endl;
        }
    }

    // 밀집도
    const float& load_factor() {
        return (float)size / capacity;
    }

    // 버킷 갯수
    const int& bucket_count() {
        return capacity;
    }

};

int main()
{
    HashTable<const char *, int> hashtable;

    /*cout << hashtable.hash_function(3) << endl;
    cout << hashtable.hash_function(4) << endl;
    cout << hashtable.hash_function(5) << endl;*/

    hashtable.insert("apple", 10);
    hashtable.insert("banana", 20);
    hashtable.insert("cherry", 30);
    
    hashtable.erase("melon");
    hashtable.erase("apple");

    cout << hashtable.load_factor() << endl;
    cout << hashtable.bucket_count() << endl;

    return 0;
}
