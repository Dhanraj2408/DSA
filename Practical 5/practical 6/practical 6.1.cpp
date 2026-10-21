#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;

public:
    Stack(int n) {
        capacity = n;
        arr = new int[capacity];
        top = -1;
    }

    void push(int value) {
    
        if (top == capacity - 1) {
            cout << " Stack Overflow  " << value << endl;
            return;
        }

        arr[++top] = value;
        cout << "Placed tray: " << value << endl;
        cout << "Current top: " << arr[top] << endl;
    }

    void pop() {
     
        if (top == -1) {
            cout << " Stack Underflow - No tray to take" << endl;
            return;
        }

        cout << "Taken tray: " << arr[top] << endl;
        top--;

        if (top == -1)
            cout << "Current top: None" << endl;
        else
            cout << "Current top: " << arr[top] << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    int n;

    cout << "Enter maximum tray capacity: ";
    cin >> n;

    Stack s(n);

    int choice, value;

    while (true) {
        cout << "\n1. Place Tray (Push)";
        cout << "\n2. Take Tray (Pop)";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tray number: ";
            cin >> value;
            s.push(value);
        }
        else if (choice == 2) {
            s.pop();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}