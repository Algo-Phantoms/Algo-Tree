// Linear Search in C++
// It is the simplest search algorithm
// Algorithm:-

// 1. looping through the array from left to right / 0 to n-1
// 2. if element_want_to_search is equal to element_at_index i, we will return index and element_want_to_search is present in given array.
// 3. if loop terminate it means element is not present.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int linear_search(int arr[],int n,int element)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n; // Taking input of number of element in array
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i]; // taking input of elements in array
    }
    int element;
    cin>>element; // taking input of element want to search
    if(linear_search(arr,n,element)==-1)
    {
        cout<<"\n"<<element<<" is not present in given Array\n"; // if not present
    }
    else
    {
        cout<<"\n"<<element<<" is present at index "<<linear_search(arr,n,element); // if present
    }
}

// Sample test cases: 
// #1
// Input :
// 5 
// 1 2 3 5 6
// 4
// output : 4 is not present in given Array

// #2
// input :
// 4
// 10 30 24 65
// 24
// output : 24 is present at index 2

// Time-Complexity : O(n)
// Space-Complexity : O(1)
