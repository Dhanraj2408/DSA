#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* last = NULL;

void insertStudent(int value, int position) {

    Node* newNode = new Node();
    newNode->data = value;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
        return;
    }

    if (position == 1) {
        newNode->next = last->next;
        last->next = newNode;
        return;
    }

    Node* temp = last->next;
    int i = 1;

    while (i < position - 1 && temp != last) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == last) {
        last = newNode;
    }
}

void deleteStudent(int value) {

    if (last == NULL) {
        cout << "Circle is empty." << endl;
        return;
    }

    Node* current = last->next;
    Node* previous = last;

    do {

        if (current->data == value) {

            // Only one node
            if (current == last && current->next == last) {
                last = NULL;
            }
            else {

                previous->next = current->next;

                if (current == last) {
                    last = previous;
                }
            }

            delete current;
            return;
        }

        previous = current;
        current = current->next;

    } while (current != last->next);

    cout << "Student not found." << endl;
}

void display() {

    if (last == NULL) {
        cout << "Circle: Empty" << endl;
        return;
    }

    Node* temp = last->next;

    cout << "Circle: ";

    do {
        cout << temp->data;

        temp = temp->next;

        if (temp != last->next) {
            cout << " -> ";
        }

    } while (temp != last->next);

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