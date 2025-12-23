
#include <iostream>
using namespace std;

template <typename T>
double average(T arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}

int main() {
    int arrInt[] = {1, 2, 3, 4, 5};
    long arrLong[] = {100L, 200L, 300L, 400L};
    double arrDouble[] = {1.1, 2.2, 3.3, 4.4};
    char arrChar[] = {'A', 'B', 'C', 'D'};

    cout << "Average of int array: " << average(arrInt, 5) << endl;
    cout << "Average of long array: " << average(arrLong, 4) << endl;
    cout << "Average of double array: " << average(arrDouble, 4) << endl;
    cout << "Average of char array: " << average(arrChar, 4) << endl;

    return 0;
}

