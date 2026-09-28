#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertStudent(int value, int position) {

    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;

        head = newNode;
        return;
    }

    if (position == 1) {

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
        return;
    }

    Node* temp = head;
    int i = 1;

    while (i < position - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteStudent(int value) {

    if (head == NULL) {
        cout << "Circle is empty." << endl;
        return;
    }

    Node* temp = head;

    do {

        if (temp->data == value) {

            if (temp->next == temp) {
                head = NULL;
            }
            else {

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head) {
                    head = temp->next;
                }
            }

            delete temp;
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Student not found." << endl;
}

void display() {

    if (head == NULL) {
        cout << "Circle: Empty" << endl;
        return;
    }

    Node* temp = head;

    cout << "Circle: ";

    do {

        cout << temp->data;

        temp = temp->next;

        if (temp != head) {
            cout << " -> ";
        }

    } while (temp != head);

    cout << " -> back to first" << endl;
}

int main() {

    insertStudent(1, 1);
    display();

    insertStudent(2, 2);
    display();

    insertStudent(3, 3);
    display();

    insertStudent(4, 2);
    display();

    deleteStudent(3);
    display();

    deleteStudent(1);
    display();

    return 0;
}