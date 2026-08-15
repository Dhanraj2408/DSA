#include <iostream>
using namespace std;

int main() {
    int n, target;
    cout << "Enter number of vehicles: ";
    cin >> n;

    int arr[n];
    cout << "Enter the vehicles no.: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the vehicle to search: ";
    cin >> target;

    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            cout << "Found at position " << i + 1;
            return 0;
        }
    }

    cout << "Not Found";

    return 0;
}