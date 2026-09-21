#include <iostream>
using namespace std;

class Node {
public:
    int token;
    Node* next;

    Node(int value) {
        token = value;
        next = NULL;
    }
};

class Queue {
public:
    Node* head;

    Queue() {
        head = NULL;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position == 1) {
            insertFront(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteByValue(int value) {
        if (head == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (head->token == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL &&
               temp->next->token != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Token not found!" << endl;
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;

        delete deleteNode;
    }

    void display() {
        Node* temp = head;

        cout << "Front to back: ";

        while (temp != NULL) {
            cout << temp->token << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void reversePrint(Node* temp) {
        if (temp == NULL) {
            return;
        }

        reversePrint(temp->next);
        cout << temp->token << " ";
    }

    void displayReverse() {
        cout << "Last to first: ";
        reversePrint(head);
        cout << endl;
    }
};

int main() {
    Queue q;

    q.insertEnd(101);
    q.insertEnd(102);
    q.insertEnd(103);
    q.insertEnd(104);

    q.display();

    q.insertFront(100);
    q.display();

    q.insertAtPosition(150, 3);
    q.display();

    q.deleteByValue(102);
    q.display();

    q.displayReverse();

    return 0;
}