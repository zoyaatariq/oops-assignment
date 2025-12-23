
#include <iostream>
using namespace std;

template <typename T, int SIZE>
class Queue {
    T arr[SIZE];
    int head, tail;
public:
    Queue() : head(0), tail(0) {}
    void enqueue(T item) {
        arr[tail] = item;
        tail = (tail + 1) % SIZE;
    }
    T dequeue() {
        T item = arr[head];
        head = (head + 1) % SIZE;
        return item;
    }
};

int main() {
    Queue<int, 5> qInt;
    Queue<double, 5> qDouble;
    Queue<char, 5> qChar;

    qInt.enqueue(10);
    qInt.enqueue(20);
    qInt.enqueue(30);
    cout << "Dequeue int: " << qInt.dequeue() << endl;
    cout << "Dequeue int: " << qInt.dequeue() << endl;

    qDouble.enqueue(1.1);
    qDouble.enqueue(2.2);
    cout << "Dequeue double: " << qDouble.dequeue() << endl;

    qChar.enqueue('A');
    qChar.enqueue('B');
    cout << "Dequeue char: " << qChar.dequeue() << endl;

    return 0;
}

