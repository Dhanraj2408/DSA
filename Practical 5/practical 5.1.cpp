#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void addBeginning(string song) {
    Node* newNode = new Node();

    newNode->song = song;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void addEnd(string song) {
    Node* newNode = new Node();

    newNode->song = song;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(string givenSong, string newSong) {

    Node* temp = head;

    while (temp != NULL && temp->song != givenSong) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Song not found." << endl;
        return;
    }

    Node* newNode = new Node();

    newNode->song = newSong;

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}


void removeFirst() {

    if (head == NULL) {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}

int countSongs() {

    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void display() {

    Node* temp = head;

    cout << "Playlist: ";

    while (temp != NULL) {

        cout << temp->song;

        if (temp->next != NULL) {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

int main() {

    addBeginning("Song A");
    display();

    addEnd("Song B");
    display();

    addEnd("Song C");
    display();

    insertAfter("Song B", "Song X");
    display();

    cout << "Number of songs: " << countSongs() << endl;

    removeFirst();
    display();

    cout << "Number of songs: " << countSongs() << endl;

    insertAfter("Song Z", "Song Y");

    return 0;
}