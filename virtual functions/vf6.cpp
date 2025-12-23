
#include <iostream>
#include <cmath>
using namespace std;

class bMoney {
    long double amount;
public:
    bMoney() : amount(0.0) {}
    bMoney(long double a) : amount(a) {}
    void getdata() {
        cout << "Enter amount: ";
        cin >> amount;
    }
    void display() const {
        cout << amount << endl;
    }
    friend bMoney round(const bMoney& m);
};

bMoney round(const bMoney& m) {
    long double intpart, fracpart;
    fracpart = modfl(m.amount, &intpart);
    if (fracpart >= 0.50) intpart += 1.0;
    return bMoney(intpart);
}

int main() {
    bMoney mo1, mo2;
    int n;

    cout << "How many amounts to test? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        mo1.getdata();
        mo2 = round(mo1);
        cout << "Rounded amount: ";
        mo2.display();
    }

    return 0;
}
