
#include <iostream>
using namespace std;

class Array {
private:
    int* ptr;
    int size;
public:
    Array(int s) : size(s) {
        ptr = new int[s];
    }
    Array(const Array& a) : size(a.size) {
        ptr = new int[size];
        for (int i = 0; i < size; i++)
            ptr[i] = a.ptr[i];
    }
    ~Array() {
        delete[] ptr;
    }
    int& operator[](int j) {
        return ptr[j];
    }
    Array& operator=(const Array& a) {
        if (this == &a)
            return *this;
        delete[] ptr;
        size = a.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
            ptr[i] = a.ptr[i];
        return *this;
    }
    int getSize() const {
        return size;
    }
};

int main() {
    const int ASIZE = 10;
    Array arr1(ASIZE);
    for (int j = 0; j < ASIZE; j++)
        arr1[j] = j * j;

    Array arr2(arr1);
    Array arr3(ASIZE);
    arr3 = arr1;

    for (int j = 0; j < ASIZE; j++)
        cout << arr1[j] << " ";
    cout << endl;

    for (int j = 0; j < arr2.getSize(); j++)
        cout << arr2[j] << " ";
    cout << endl;

    for (int j = 0; j < arr3.getSize(); j++)
        cout << arr3[j] << " ";
    cout << endl;

    Array arr4(5);
    arr4 = arr1;

    for (int j = 0; j < arr4.getSize(); j++)
        cout << arr4[j] << " ";
    cout << endl;

    return 0;
}


