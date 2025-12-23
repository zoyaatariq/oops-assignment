
#include <iostream>
using namespace std;

template <typename T>
void swaps(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    swaps(x, y);
    cout << "Swapped ints: x=" << x << ", y=" << y << endl;

    double a = 1.5, b = 3.7;
    swaps(a, b);
    cout << "Swapped doubles: a=" << a << ", b=" << b << endl;

    char c1 = 'A', c2 = 'Z';
    swaps(c1, c2);
    cout << "Swapped chars: c1=" << c1 << ", c2=" << c2 << endl;

    float f1 = 2.2f, f2 = 4.4f;
    swaps(f1, f2);
    cout << "Swapped floats: f1=" << f1 << ", f2=" << f2 << endl;

    return 0;
}

