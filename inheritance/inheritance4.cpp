
#include <iostream>
#include <string>
using namespace std;

class publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class sales {
protected:
    float sales_amount[3];
public:
    void getdata() {
        cout << "Enter sales for last three months: ";
        for (int i = 0; i < 3; i++)
            cin >> sales_amount[i];
    }
    void putdata() const {
        cout << "Sales: ";
        for (int i = 0; i < 3; i++)
            cout << sales_amount[i] << " ";
        cout << endl;
    }
};

class book : public publication, public sales {
    int pages;
public:
    void getdata() {
        publication::getdata();
        cout << "Enter pages: ";
        cin >> pages;
        sales::getdata();
    }
    void putdata() const {
        publication::putdata();
        cout << "Pages: " << pages << endl;
        sales::putdata();
    }
};

class tape : public publication, public sales {
    float time;
public:
    void getdata() {
        publication::getdata();
        cout << "Enter playing time: ";
        cin >> time;
        sales::getdata();
    }
    void putdata() const {
        publication::putdata();
        cout << "Playing time: " << time << endl;
        sales::putdata();
    }
};

class disk : public publication, public sales {
    enum disktype { CD, DVD };
    disktype type;
public:
    void getdata() {
        publication::getdata();
        char ch;
        cout << "Enter disk type (c/d): ";
        cin >> ch;
        type = (ch == 'c' || ch == 'C') ? CD : DVD;
        sales::getdata();
    }
    void putdata() const {
        publication::putdata();
        cout << "Disk type: " << (type == CD ? "CD" : "DVD") << endl;
        sales::putdata();
    }
};

int main() {
    book b;
    tape t;
    disk d;

    cout << "Enter book details\n";
    b.getdata();
    cin.ignore();

    cout << "\nEnter tape details\n";
    t.getdata();
    cin.ignore();

    cout << "\nEnter disk details\n";
    d.getdata();

    cout << "\nBook information\n";
    b.putdata();

    cout << "\nTape information\n";
    t.putdata();

    cout << "\nDisk information\n";
    d.putdata();

    return 0;
}
