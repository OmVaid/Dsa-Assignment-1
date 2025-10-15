#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

// Function to insert node at end
void insert(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to display linked list
void display() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to reverse the linked list
void reverseList() {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;    // Store next node
        curr->next = prev;    // Reverse current node's link
        prev = curr;          // Move prev forward
        curr = next;          // Move curr forward
    }

    head = prev;  // Update head to new first node
    cout << "Linked list reversed successfully.\n";
}

int main() {
    // Creating linked list: 1->2->3->4->NULL
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    cout << "Original Linked List: ";
    display();

    reverseList();

    cout << "Reversed Linked List: ";
    display();

    return 0;
}
