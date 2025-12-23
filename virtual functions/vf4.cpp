
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
    virtual bool isOversize() const = 0;
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
        cout << "Pages: " << pages;
        if (isOversize()) cout << " (Oversize)";
        cout << endl;
    }
    bool isOversize() const override {
        return pages > 800;
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
        cout << "Playing time: " << playing_time << " minutes";
        if (isOversize()) cout << " (Oversize)";
        cout << endl;
    }
    bool isOversize() const override {
        return playing_time > 90;
    }
};

int main() {
    publication* pubarr[2];
    pubarr[0] = new book;
    pubarr[1] = new tape;

    for (int i = 0; i < 2; i++) {
        cin.ignore();
        pubarr[i]->getdata();
    }

    for (int i = 0; i < 2; i++) {
        pubarr[i]->putdata();
        delete pubarr[i];
    }

    return 0;
}
