
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T, int SIZE>
class Queue {
    T arr[SIZE];
    int head, tail, count;
public:
    Queue() : head(0), tail(0), count(0) {}
    void enqueue(T item) {
        if (count >= SIZE) throw overflow_error("Queue overflow");
        arr[tail] = item;
        tail = (tail + 1) % SIZE;
        count++;
    }
    T dequeue() {
        if (count <= 0) throw underflow_error("Queue underflow");
        T item = arr[head];
        head = (head + 1) % SIZE;
        count--;
        return item;
    }
    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == SIZE; }
};

int main() {
    Queue<int, 5> q;
    int choice, val;

    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Exit\nChoice: ";
        cin >> choice;
        try {
            if (choice == 1) {
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                cout << "Enqueued " << val << endl;
            } else if (choice == 2) {
                val = q.dequeue();
                cout << "Dequeued " << val << endl;
            } else break;
        } catch (exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
    }

    return 0;
}
