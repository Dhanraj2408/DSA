#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = nullptr;
    }
};

class BrowserHistory {
    Node* top;

public:
    BrowserHistory() {
        top = nullptr;
    }

    void visit(string page) {
        Node* newNode = new Node(page);

        newNode->next = top;
        top = newNode;

        cout << "Visited: " << page << endl;
        cout << "Current page: " << top->page << endl;
    }

    void back() {
        if (top == nullptr) {
            cout << "Error: No page history available." << endl;
            return;
        }

        Node* temp = top;

        cout << "Going back from: " << top->page << endl;

        top = top->next;
        delete temp;

        if (top == nullptr)
            cout << "Current page: None" << endl;
        else
            cout << "Current page: " << top->page << endl;
    }

    ~BrowserHistory() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    BrowserHistory browser;

    int choice;
    string page;

    while (true) {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page name: ";
            cin >> page;

            browser.visit(page);
        }
        else if (choice == 2) {
            browser.back();
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