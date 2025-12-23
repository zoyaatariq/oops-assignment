#include <iostream>
using namespace std;

class Counter {
protected:
    int count;
public:
    Counter() : count(0) {}
    Counter(int c) : count(c) {}
    Counter& operator++() {
        ++count;
        return *this;
    }
    Counter& operator--() {
        --count;
        return *this;
    }
    int getcount() const {
        return count;
    }
};

class Counter2 : public Counter {
public:
    Counter2() : Counter() {}
    Counter2(int c) : Counter(c) {}
    Counter2 operator++(int) {
        Counter2 temp = *this;
        ++count;
        return temp;
    }
    Counter2 operator--(int) {
        Counter2 temp = *this;
        --count;
        return temp;
    }
};

int main() {
    Counter2 c(5);

    cout << c.getcount() << endl;
    ++c;
    cout << c.getcount() << endl;
    c++;
    cout << c.getcount() << endl;
    --c;
    cout << c.getcount() << endl;
    c--;
    cout << c.getcount() << endl;

    return 0;
}
