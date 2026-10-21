#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void join(int token) {
        if (rear == 4) {
            cout << "Error: Queue is full\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = token;

        cout << "Front token: " << arr[front] << endl;
    }

    void serve() {
        if (front == -1 || front > rear) {
            cout << "Error: Queue is empty\n";
            return;
        }

        cout << "Served token: " << arr[front] << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        } else {
            cout << "Front token: " << arr[front] << endl;
        }
    }
};

int main() {
    Queue q;

    q.join(101);
    q.join(102);
    q.join(103);

    q.serve();
    q.join(104);
    q.serve();
    q.serve();

    return 0;
}