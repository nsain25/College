#include <iostream>
#include <cstring>
#include <cctype>
#include <stack>

using namespace std;

struct Stack {
    int top;
    char* arr;
    unsigned size;

    Stack(unsigned size) {
        top = -1;
        this->size = size;
        arr = new char[size];
    }

    ~Stack() {
        delete[] arr;
    }

    int isFull() {
        return top == size - 1;
    }

    int isEmpty() {
        return top == -1;
    }

    void push(char item) {
        if (isFull()) {
            cout << "Overflow!" << endl;
            return;
        }
        arr[++top] = item;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }
};

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(const char* infix) {
    unsigned size = strlen(infix);
    Stack stack(size);
    
    for (unsigned i = 0; i < size; ++i) {
        if (isalnum(infix[i])) {
            cout << infix[i];
        } else if (infix[i] == '(') {
            stack.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!stack.isEmpty() && stack.arr[stack.top] != '(') {
                cout << stack.pop();
            }
            if (!stack.isEmpty() && stack.arr[stack.top] != '(') {
                cout << "Oh no, Invalid!" << endl;
                return;
            } else {
                stack.pop();
            }
        } else {
            while (!stack.isEmpty() && precedence(infix[i]) <= precedence(stack.arr[stack.top])) {
                cout << stack.pop();
            }
            stack.push(infix[i]);
        }
    }

    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
}

int main() {
    const int MAXSIZE = 100;
    char infix[MAXSIZE];

    cout << "Enter an infix notation (Max 100): ";
    cin.getline(infix, MAXSIZE);

    cout << "The postfix notation will be: ";
    infixToPostfix(infix);

    return 0;
}
