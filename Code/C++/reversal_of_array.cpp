/* Reversing an array means displaying all the elements of the array from last to first
    This code uses dyanmic memory allocation */

#include<iostream>
using namespace std;
int main(){
    int *arr =NULL;
    int i,n;

    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    arr = new int[n];
    cout<<"Enter the elements of the array: ";

    for(i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<"The array is: ";
    for(i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"The reversed array is: ";
    for(i=n-1;i>=0;i--) {
        cout<<arr[i]<<" ";
    }
/* 
    Sample test cases:
    Enter the number of elements in the array: 5
    Enter the elements of the array: 1 2 3 4 5
    The array is: 1 2 3 4 5
    The reversed array is: 5 4 3 2 1

    Enter the number of elements in the array: 10
    Enter the elements of the array: 12 5 35 47 17
    The array is: 12 5 35 47 17
    The reversed array is: 17 47 35 5 12
 
    The time complexity of the reversal of an array is O(n)*/
}
