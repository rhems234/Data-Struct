#include <iostream>

using namespace std;

template <typename T>
class Graph {

private:
    int size; // 정점의 개수
    int count; // 인접 행렬의 크기
    int capacity; // 최대 용량

    T** vertex; // 정점의 집합
    int** matrix; // 인접 행렬

public:

    Graph() {
        size = 0;
        count = 0;
        capacity = 0;

        vertex = nullptr;
        matrix = nullptr;
    }

    void resize(int newsize) {
        T& newVertexeSet = new T[newsize];
        for (int i = 0; i < size; i++) {
            newVertexeSet[i] = vertex[i];
        }
        delete[] vertex;
        vertex = newVertexeSet;
        capacity = newsize;
    }

    void push(T data) {
        
        if (capacity >= 0) {
            size++;
        }

    }

    void edge(int i, int j) {
        if (vertex == nullptr) {
            cout << "adjacency matrix is empty" << endl;
        }
    }
};

int main()
{
    Graph<int> graph;

    graph.resize(5);

    /*graph.push('A');
    graph.push('B');*/

    return 0;
}
