#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
    int top;
    int arr[SIZE];

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
        } else {
            cout << arr[top--] << " popped from stack\n";
        }
    }

    void peek() {
        if (!isEmpty()) {
            cout << "Top element is: " << arr[top] << "\n";
        } else {
            cout << "Stack is empty\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.peek();
    s.pop();
    s.display();
    return 0;
}
