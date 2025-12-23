#include <iostream>
#include <string>
using namespace std;

// Base class
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
        cout << "Price: $" << price << endl;
    }
};

// Derived class: Book
class book : public publication {
private:
    int page_count;

public:
    void getdata() {
        publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
    }

    void putdata() const {
        publication::putdata();
        cout << "Page count: " << page_count << endl;
    }
};

// Derived class: Tape
class tape : public publication {
private:
    float playing_time;

public:
    void getdata() {
        publication::getdata();
        cout << "Enter playing time (minutes): ";
        cin >> playing_time;
    }

    void putdata() const {
        publication::putdata();
        cout << "Playing time: " << playing_time << " minutes" << endl;
    }
};

// Main function
int main() {
    book b;
    tape t;

    cout << "\nEnter book details:\n";
    b.getdata();
    cin.ignore();  // Clear input buffer

    cout << "\nEnter tape details:\n";
    t.getdata();

    cout << "\nBook details:\n";
    b.putdata();

    cout << "\nTape details:\n";
    t.putdata();

    return 0;
}
