
#include <iostream>
#include <cctype>
#include <cstdlib>
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
    void push(Token* t) { st[++top] = t; }
    Token* pop() { return top >= 0 ? st[top--] : nullptr; }
    Token* peek() const { return top >= 0 ? st[top] : nullptr; }
    bool isEmpty() const { return top == -1; }
};

int main() {
    Stack s;
    string expr;
    cout << "Enter expression (space-separated, e.g., 3.14 + 2.0 * 5): ";
    getline(cin, expr);

    for (size_t i = 0; i < expr.size();) {
        if (isspace(expr[i])) { i++; continue; }
        if (isdigit(expr[i]) || expr[i] == '.') {
            size_t j = i;
            while (j < expr.size() && (isdigit(expr[j]) || expr[j]=='.')) j++;
            float num = stof(expr.substr(i, j - i));
            s.push(new Number(num));
            i = j;
        } else {
            s.push(new Operator(expr[i]));
            i++;
        }
    }

    cout << "Stack contents (top to bottom):\n";
    while (!s.isEmpty()) {
        Token* t = s.pop();
        if (t->getOperator() != '\0')
            cout << "Operator: " << t->getOperator() << endl;
        else
            cout << "Number: " << t->getNumber() << endl;
        delete t;
    }

    return 0;
}

