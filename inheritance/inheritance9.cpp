```cpp
#include <iostream>
#include <string>
using namespace std;

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

class manager : public employee {
protected:
    string title;
public:
    void getdata() {
        employee::getdata();
        cin.ignore();
        cout << "Enter title: ";
        getline(cin, title);
    }
    void putdata() const {
        employee::putdata();
        cout << "Title: " << title << endl;
    }
};

class executive : public manager {
    double bonus;
    int stock_options;
public:
    void getdata() {
        manager::getdata();
        cout << "Enter yearly bonus: ";
        cin >> bonus;
        cout << "Enter number of stock options: ";
        cin >> stock_options;
    }
    void putdata() const {
        manager::putdata();
        cout << "Yearly bonus: " << bonus << endl;
        cout << "Stock options: " << stock_options << endl;
    }
};

int main() {
    executive e;

    cout << "Enter executive details\n";
    e.getdata();

    cout << "\nExecutive information\n";
    e.putdata();

    return 0;
}
```

