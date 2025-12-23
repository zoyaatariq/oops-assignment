
#include <iostream>
#include <string>
using namespace std;

class Money {
    long double amount;
public:
    Money() : amount(0.0) {}
    Money(long double a) : amount(a) {}
    void getdata() {
        cout << "Enter amount: ";
        cin >> amount;
    }
    void display() const {
        cout << amount << endl;
    }
    Money operator+(const Money& m) const { return Money(amount + m.amount); }
    Money operator-(const Money& m) const { return Money(amount - m.amount); }
    Money operator*(const Money& m) const { return Money(amount * m.amount); }
    Money operator/(const Money& m) const { return Money(amount / m.amount); }
    Money operator*(long double n) const { return Money(amount * n); }
    Money operator/(long double n) const { return Money(amount / n); }
    friend Money operator*(long double n, const Money& m);
    friend Money operator/(long double n, const Money& m);
};

Money operator*(long double n, const Money& m) {
    return Money(n * m.amount);
}

Money operator/(long double n, const Money& m) {
    return Money(n / m.amount);
}

int main() {
    Money m1, m2, result;
    long double num;

    cout << "Enter first money amount:\n";
    m1.getdata();
    cout << "Enter second money amount:\n";
    m2.getdata();
    cout << "Enter a floating-point number:\n";
    cin >> num;

    cout << "m1 + m2 = "; (m1 + m2).display();
    cout << "m1 - m2 = "; (m1 - m2).display();
    cout << "m1 * m2 = "; (m1 * m2).display();
    cout << "m1 / m2 = "; (m1 / m2).display();
    cout << "m1 * num = "; (m1 * num).display();
    cout << "m1 / num = "; (m1 / num).display();
    cout << "num * m2 = "; (num * m2).display();
    cout << "num / m2 = "; (num / m2).display();

    return 0;
}

