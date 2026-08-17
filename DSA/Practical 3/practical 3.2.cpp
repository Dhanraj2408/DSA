#include <iostream>
using namespace std;

int main(){
    int arr[50];
    int i,j,temp,n;

    cout<<"Enter the number of colours you want to enter:- "<<endl;
    cin>>n;

    for(i=0;i<n;i++){
        cout<<"Enter Colour code of bucket number "<<i+1<<":- ";
        cin>>arr[i];
    }

    for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){


            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            }
}
    cout<<"Sorted array is"<<endl;
    for(i=0;i<n;i++){
        cout<< arr[i];
}
}
