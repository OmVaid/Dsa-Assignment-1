#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);

        // move all previous elements behind the new one
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Popped element: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
        } else {
            cout << "Top element: " << q.front() << endl;
        }
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Stack elements: ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingOneQueue s;
    int choice, val;

    while (true) {
        cout << "\n--- Stack using One Queue ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.top();
                break;
            case 4:
                s.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
