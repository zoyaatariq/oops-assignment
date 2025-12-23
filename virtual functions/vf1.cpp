
#include <iostream>
#include <string>
using namespace std;

class publication {
protected:
    string title;
    float price;
public:
    virtual void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    virtual void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
    virtual ~publication() {}
};

class book : public publication {
    int pages;
public:
    void getdata() override {
        publication::getdata();
        cout << "Enter page count: ";
        cin >> pages;
    }
    void putdata() const override {
        publication::putdata();
        cout << "Pages: " << pages << endl;
    }
};

class tape : public publication {
    float playing_time;
public:
    void getdata() override {
        publication::getdata();
        cout << "Enter playing time: ";
        cin >> playing_time;
    }
    void putdata() const override {
        publication::putdata();
        cout << "Playing time: " << playing_time << " minutes" << endl;
    }
};

int main() {
    publication* pubarr[100];
    int count = 0;
    char choice;

    do {
        cout << "Enter book or tape (b/t)? ";
        cin >> choice;
        cin.ignore();

        if (choice == 'b' || choice == 'B') {
            pubarr[count] = new book;
        } else if (choice == 't' || choice == 'T') {
            pubarr[count] = new tape;
        } else {
            cout << "Invalid choice\n";
            continue;
        }

        pubarr[count]->getdata();
        cin.ignore();
        count++;

        cout << "Add another? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    cout << "\nAll publications entered:\n";
    for (int i = 0; i < count; i++) {
        pubarr[i]->putdata();
        cout << endl;
    }

    for (int i = 0; i < count; i++)
        delete pubarr[i];

    return 0;
}

