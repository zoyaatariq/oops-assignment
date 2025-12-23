
#include <iostream>
using namespace std;

struct Link {
    int data;
    Link* next;
    Link(int d) : data(d), next(nullptr) {}
};

class linklist {
    Link* head;
public:
    linklist() : head(nullptr) {}
    linklist(const linklist& l) : head(nullptr) {
        if (!l.head) return;
        head = new Link(l.head->data);
        Link* src = l.head->next;
        Link* dest = head;
        while (src) {
            dest->next = new Link(src->data);
            dest = dest->next;
            src = src->next;
        }
    }
    ~linklist() {
        Link* current = head;
        while (current) {
            Link* temp = current;
            current = current->next;
            delete temp;
        }
    }
    linklist& operator=(const linklist& l) {
        if (this == &l) return *this;
        Link* current = head;
        while (current) {
            Link* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        if (!l.head) return *this;
        head = new Link(l.head->data);
        Link* src = l.head->next;
        Link* dest = head;
        while (src) {
            dest->next = new Link(src->data);
            dest = dest->next;
            src = src->next;
        }
        return *this;
    }
    void add(int d) {
        Link* newlink = new Link(d);
        newlink->next = head;
        head = newlink;
    }
    void display() const {
        Link* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    linklist* list1 = new linklist();
    list1->add(1);
    list1->add(2);
    list1->add(3);

    linklist* list2 = new linklist();
    *list2 = *list1;

    delete list1;

    list2->display();

    delete list2;
    return 0;
}

