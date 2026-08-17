#include <iostream>
using namespace std;

int main() {
    int n, h;
    cout << "Enter number of bakery items: ";
    cin >> n;

    int arr[n];

    cout << "Enter the items: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"Enter the number of hours: ";
    cin >> h;
    h = h % n;

    for(int i = h; i < n; i++) {
        cout << arr[i] << " ";
    }

    for(int i = 0; i < h; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}