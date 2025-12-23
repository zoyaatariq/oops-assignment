```cpp
#include <iostream>
#include <string>
using namespace std;

enum period { hourly, weekly, monthly };

class employee {
protected:
    string name;
    long number;
public:
    void getdata() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter number: ";
        cin >> number;
    }
    void putdata() const {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

class employee2 : public employee {
protected:
    double compensation;
    period pay_period;
public:
    void getdata() {
        employee::getdata();
        char ch;
        cout << "Enter compensation: ";
        cin >> compensation;
        cout << "Enter period (h/w/m): ";
        cin >> ch;
        if (ch == 'h')
            pay_period = hourly;
        else if (ch == 'w')
            pay_period = weekly;
        else
            pay_period = monthly;
    }
    void putdata() const {
        employee::putdata();
        cout << "Compensation: " << compensation << endl;
        cout << "Period: ";
        if (pay_period == hourly) cout << "Hourly";
        else if (pay_period == weekly) cout << "Weekly";
        else cout << "Monthly";
        cout << endl;
    }
};

class manager : public employee2 {
    string title;
public:
    void getdata() {
        employee2::getdata();
        cin.ignore();
        cout << "Enter title: ";
        getline(cin, title);
    }
    void putdata() const {
        employee2::putdata();
        cout << "Title: " << title << endl;
    }
};

class scientist : public employee2 {
    int publications;
public:
    void getdata() {
        employee2::getdata();
        cout << "Enter publications: ";
        cin >> publications;
    }
    void putdata() const {
        employee2::putdata();
        cout << "Publications: " << publications << endl;
    }
};

class laborer : public employee2 {
public:
    void getdata() {
        employee2::getdata();
    }
    void putdata() const {
        employee2::putdata();
    }
};

int main() {
    manager m;
    scientist s;
    laborer l;

    cout << "Enter manager data\n";
    m.getdata();
    cin.ignore();

    cout << "\nEnter scientist data\n";
    s.getdata();
    cin.ignore();

    cout << "\nEnter laborer data\n";
    l.getdata();

    cout << "\nManager data\n";
    m.putdata();

    cout << "\nScientist data\n";
    s.putdata();

    cout << "\nLaborer data\n";
    l.putdata();

    return 0;
}
```
