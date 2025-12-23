

#include <iostream>
using namespace std;

template <typename T>
class frac {
    T num, den;
public:
    frac(T n = 0, T d = 1) : num(n), den(d) {
        if (den == 0) { cout << "Denominator cannot be 0\n"; exit(1); }
    }
    void display() { cout << num << "/" << den << endl; }
    frac operator+(const frac& f) {
        return frac(num * f.den + f.num * den, den * f.den);
    }
    frac operator-(const frac& f) {
        return frac(num * f.den - f.num * den, den * f.den);
    }
    frac operator*(const frac& f) {
        return frac(num * f.num, den * f.den);
    }
    frac operator/(const frac& f) {
        return frac(num * f.den, den * f.num);
    }
};

int main() {
    frac<char> f1(3,4), f2(1,2);
    frac<char> res;

    res = f1 + f2;
    cout << "Sum: "; res.display();

    res = f1 - f2;
    cout << "Difference: "; res.display();

    res = f1 * f2;
    cout << "Product: "; res.display();

    res = f1 / f2;
    cout << "Quotient: "; res.display();

    return 0;
}
