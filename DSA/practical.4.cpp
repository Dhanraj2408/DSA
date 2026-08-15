#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};
void insert(node** head, int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}
void printList(node* head) {
    node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    node* head = nullptr;
    insert(&head, 1);       
    printList(head);
    return 0;
}