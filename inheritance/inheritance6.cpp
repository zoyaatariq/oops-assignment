```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

const int LIMIT = 100;

class safearay {
protected:
    int arr[LIMIT];
public:
    int& operator[](int n) {
        if (n < 0 || n >= LIMIT) {
            cout << "Index out of bounds\n";
            exit(1);
        }
        return arr[n];
    }
};

class safehilo : public safearay {
    int low, high;
public:
    safehilo(int l, int h) : low(l), high(h) {
        if (h - l + 1 > LIMIT) {
            cout << "Range too large\n";
            exit(1);
        }
    }
    int& operator[](int n) {
        if (n < low || n > high) {
            cout << "Index out of bounds\n";
            exit(1);
        }
        return arr[n - low];
    }
};

int main() {
    safehilo sa(10, 19);

    for (int i = 10; i <= 19; i++)
        sa[i] = i * 10;

    for (int i = 10; i <= 19; i++)
        cout << sa[i] << " ";

    return 0;
}
```
