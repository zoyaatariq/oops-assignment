
#include <iostream>
using namespace std;

class OutOfBounds {
    int index;
public:
    OutOfBounds(int i) : index(i) {}
    int getIndex() const { return index; }
    const char* what() const { return "Index out of bounds"; }
};

class safearay {
    int arr[10];
public:
    int& operator[](int index) {
        if (index < 0 || index >= 10) throw OutOfBounds(index);
        return arr[index];
    }
};

int main() {
    safearay sa;
    try {
        sa[0] = 10;
        sa[9] = 99;
        sa[10] = 100;
    } catch (OutOfBounds& e) {
        cout << "Exception: " << e.what() << ", index = " << e.getIndex() << endl;
    }

    for (int i = 0; i < 10; i++)
        cout << sa[i] << " ";
    cout << endl;
    return 0;
}

