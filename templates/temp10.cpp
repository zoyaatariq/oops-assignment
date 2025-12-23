
#include <iostream>
#include <cstring>
using namespace std;

const int SZ = 80;

class StringTooLong {
    const char* msg;
public:
    StringTooLong(const char* m) : msg(m) {}
    const char* what() const { return msg; }
};

class String {
    char str[SZ];
public:
    String(const char* s = "") {
        if (strlen(s) >= SZ) throw StringTooLong("Initialization string too long");
        strcpy(str, s);
    }
    void display() const { cout << str << endl; }
    String operator+(const String& s) const {
        if (strlen(str) + strlen(s.str) >= SZ)
            throw StringTooLong("Resulting string too long");
        char temp[SZ];
        strcpy(temp, str);
        strcat(temp, s.str);
        return String(temp);
    }
};

int main() {
    try {
        String s1("Hello, ");
        String s2("world!");
        String s3 = s1 + s2;
        s3.display();

        String s4("This string is deliberately made way too long to trigger the constructor exception and should fail immediately.");
    } catch (StringTooLong& e) {
        cout << "Exception: " << e.what() << endl;
    }

    try {
        String a("1234567890");
        String b("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        String c = a + b;
    } catch (StringTooLong& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
