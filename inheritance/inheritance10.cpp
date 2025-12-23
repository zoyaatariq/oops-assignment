```cpp
#include <iostream>
using namespace std;

const int MAX = 100;

struct pair {
    int x;
    int y;
};

class Stack2 {
protected:
    int st[MAX];
    int top;
public:
    Stack2() : top(-1) {}
    void push(int n) {
        if (top >= MAX - 1) {
            cout << "Stack overflow\n";
            return;
        }
        st[++top] = n;
    }
    int pop() {
        if (top < 0) {
            cout << "Stack underflow\n";
            return 0;
        }
        return st[top--];
    }
};

class pairStack : public Stack2 {
public:
    void push(pair p) {
        Stack2::push(p.x);
        Stack2::push(p.y);
    }
    pair pop() {
        pair p;
        p.y = Stack2::pop();
        p.x = Stack2::pop();
        return p;
    }
};

int main() {
    pairStack ps;
    pair p1 = {10, 20}, p2;

    ps.push(p1);
    p2 = ps.pop();

    cout << "Popped pair: (" << p2.x << ", " << p2.y << ")" << endl;

    return 0;
}
```

