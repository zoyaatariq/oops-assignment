
#include <iostream>
using namespace std;

template <typename T, int SIZE>
class safearay {
    T arr[SIZE];
public:
    T& operator[](int index) {
        if (index < 0 || index >= SIZE) {
            cout << "Index out of bounds\n";
            exit(1);
        }
        return arr[index];
    }
};

int main() {
    safearay<int, 5> intArray;
    safearay<double, 4> doubleArray;

    for (int i = 0; i < 5; i++) intArray[i] = i * 10;
    for (int i = 0; i < 4; i++) doubleArray[i] = i * 1.1;

    cout << "Int array: ";
    for (int i = 0; i < 5; i++) cout << intArray[i] << " ";
    cout << endl;

    cout << "Double array: ";
    for (int i = 0; i < 4; i++) cout << doubleArray[i] << " ";
    cout << endl;

    return 0;
}

