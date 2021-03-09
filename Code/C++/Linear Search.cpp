//In this code, we are performing linear search on an array of integers.
//key is the element we want to search in array.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size_of_array=0,i=0, key=0;
    cout<<"Please enter size of the array."<<endl;
    cin>>size_of_array;
    int arr[size_of_array];
    cout<<"Enter the numbers"<<endl;
    for(i=0; i<size_of_array; i++)
    cin>>arr[i];
    cout<<"Enter the number you want to search"<<endl;
    cin>>key;
    int flag=0;
    for(i=0; i<size_of_array; i++)
    {
        if(arr[i]==key)
        {
            cout<<"Key is found at index "<<i<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"Key is not found."<<endl;
    return 0;
}
//The time complexity of this code is O(N) where N is the size of Array because we are traversing the complete array.
