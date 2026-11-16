#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Node { char data; Node* next; };
Node* topNode = NULL;

void push(char x) {
    Node* p = new Node;
    p->data = x; p->next = topNode; topNode = p;
}
char pop() {
    if (!topNode) return '\0';
    Node* p = topNode; char x = p->data;
    topNode = p->next; delete p; return x;
}
int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    string infix = "3+5*2", postfix = "";
    for (char c : infix) {
        if (isdigit(c)) postfix += c;
        else {
            while (topNode && priority(topNode->data) >= priority(c)) postfix += pop();
            push(c);
        }
    }
    while (topNode) postfix += pop();
    cout << "Postfix: " << postfix << endl;

    int st[20], top = -1;
    for (char c : postfix) {
        if (isdigit(c)) st[++top] = c - '0';
        else {
            int b = st[top--], a = st[top--], ans = 0;
            if (c == '+') ans = a+b;
            if (c == '-') ans = a-b;
            if (c == '*') ans = a*b;
            if (c == '/') ans = a/b;
            st[++top] = ans;
        }
    }
    cout << "Result: " << st[top];
    return 0;
}