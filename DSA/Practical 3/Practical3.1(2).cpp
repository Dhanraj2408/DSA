#include<iostream>
using namespace std;
int main()
{
    int a[5]={8,5,1,3,7};
    for(int i=0; i<4; i++)
    {
        int min = i;
        for(int j=i+1; j<5; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
