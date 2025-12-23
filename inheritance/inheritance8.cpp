```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int SZ = 80;

class String {
protected:
    char str[SZ];
public:
    String() { str[0] = '\0'; }
    String(const char s[]) { strcpy(str, s); }
    void display() const { cout << str << endl; }
};

class Pstring : public String {
public:
    Pstring() : String() {}
    Pstring(const char s[]) {
        if (strlen(s) >= SZ) {
            strncpy(str, s, SZ - 1);
            str[SZ - 1] = '\0';
        } else {
            strcpy(str, s);
        }
    }
};

class Pstring2 : public Pstring {
public:
    Pstring2& left(const Pstring& s1, int n) {
        int i;
        for (i = 0; i < n && s1.str[i] != '\0'; i++)
            str[i] = s1.str[i];
        str[i] = '\0';
        return *this;
    }
    Pstring2& mid(const Pstring& s1, int s, int n) {
        int i;
        for (i = 0; i < n && s1.str[s + i] != '\0'; i++)
            str[i] = s1.str[s + i];
        str[i] = '\0';
        return *this;
    }
    Pstring2& right(const Pstring& s1, int n) {
        int len = strlen(s1.str);
        int start = (n > len) ? 0 : len - n;
        int i;
        for (i = 0; i < n && s1.str[start + i] != '\0'; i++)
            str[i] = s1.str[start + i];
        str[i] = '\0';
        return *this;
    }
};

int main() {
    Pstring s1("Hello, World!");
    Pstring2 s2;

    s2.left(s1, 5);
    s2.display();

    s2.mid(s1, 7, 5);
    s2.display();

    s2.right(s1, 6);
    s2.display();

    return 0;
}
```
