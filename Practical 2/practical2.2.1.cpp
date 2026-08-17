#include <iostream>
using namespace std;

int main()
{
    int n, target;

    cout << "Enter number of book codes = ";
    cin >> n;

    int book[n];

    cout << "Enter sorted book codes:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> book[i];
    }

    cout << "Enter target book code = ";
    cin >> target;

    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(book[mid] == target)
        {
            cout << "Book found at position " << mid + 1;
            return 0;
        }
        else if(target < book[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << "Book not found.";

    return 0;
}