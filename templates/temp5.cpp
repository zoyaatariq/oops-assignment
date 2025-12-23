
#include <iostream>
using namespace std;

template <typename T>
T amax(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

int main() {
    int arrInt[] = {1, 5, 3, 9, 2};
    double arrDouble[] = {2.2, 3.5, 1.1, 4.8};
    float arrFloat[] = {1.1f, 5.5f, 3.3f};
    long arrLong[] = {100L, 500L, 300L};

    cout << "Max int: " << amax(arrInt, 5) << endl;
    cout << "Max double: " << amax(arrDouble, 4) << endl;
    cout << "Max float: " << amax(arrFloat, 3) << endl;
    cout << "Max long: " << amax(arrLong, 3) << endl;

    return 0;
}
