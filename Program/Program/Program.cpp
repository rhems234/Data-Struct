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
        unsigned int index = hash_function(key);

        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;

        if (newNode->value >= 1) {
            cout << "Insert complete" << endl;
            newNode->next = bucket[index].head;
            bucket[index].head = newNode;

            bucket[index].count++;
        }

    }

};

int main()
{
    HashTable<const char *, int> hashtable;

    cout << hashtable.hash_function(3) << endl;
    cout << hashtable.hash_function(4) << endl;
    cout << hashtable.hash_function(5) << endl;

    hashtable.insert("1", 0);
    hashtable.insert("2", 1);
    hashtable.insert("3", 2);
    hashtable.insert("4", 3);

    return 0;
}
