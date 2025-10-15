#include <iostream>
using namespace std;

#define SIZE 5   // maximum size of stack

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is Full! (Overflow)\n";
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty! (Underflow)\n";
        } else {
            cout << "Popped element: " << arr[top] << endl;
            top--;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                if (s.isEmpty())
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is not Empty.\n";
                break;

            case 6:
                if (s.isFull())
                    cout << "Stack is Full.\n";
                else
                    cout << "Stack is not Full.\n";
                break;

            case 7:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
