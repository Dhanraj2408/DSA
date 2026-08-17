#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of borrowed books = ";
    cin >> n;

    int book[n];

    cout << "Enter Book IDs:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
    }

    cout << "\nBooks borrowed more than once are:\n";

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (book[i] == book[j])
            {
                count++;
            }
        }

        if (count > 1)
        {
            int a = 0;

            for (int k = 0; k < i; k++)
            {
                if (book[i] == book[k])
                {
                    a = 1;
                    break;
                }
            }

            if (a == 0)
            {
                cout << book[i] << endl;
            }
        }
    }

    return 0;
}