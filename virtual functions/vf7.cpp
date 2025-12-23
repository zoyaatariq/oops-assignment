
#include <iostream>
using namespace std;

class Token {
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual ~Token() {}
};

class Operator : public Token {
    char oper;
public:
    Operator(char c) : oper(c) {}
    char getOperator() override { return oper; }
    float getNumber() override { return 0.0; }
};

class Number : public Token {
    float fnum;
public:
    Number(float f) : fnum(f) {}
    float getNumber() override { return fnum; }
    char getOperator() override { return '\0'; }
};

class Stack {
    Token* st[100];
    int top;
public:
    Stack() : top(-1) {}
    void push(Token* t) {
        if (top >= 99) {
            cout << "Stack overflow\n";
            return;
        }
        st[++top] = t;
    }
    Token* pop() {
        if (top < 0) {
            cout << "Stack underflow\n";
            return nullptr;
        }
        return st[top--];
    }
    bool isEmpty() const { return top == -1; }
};

int main() {
    Stack s;
    s.push(new Number(3.14159));
    s.push(new Operator('/'));
    s.push(new Number(2.0));
    s.push(new Operator('+'));
    s.push(new Number(75.25));
    s.push(new Operator('*'));
    s.push(new Number(3.333));
    s.push(new Operator('+'));
    s.push(new Number(6.02));

    while (!s.isEmpty()) {
        Token* t = s.pop();
        char op = t->getOperator();
        if (op != '\0')
            cout << "Operator: " << op << endl;
        else
            cout << "Number: " << t->getNumber() << endl;
        delete t;
    }

    return 0;
}
