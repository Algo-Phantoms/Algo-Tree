// This is c++ code for finding Kth maximum element in given array
// Algorithm :-
// 1. If given k is greater then number of elements return -1;
// 2. sort the given array
// 3. return (k-1)th element in the given array.

#include <bits/stdc++.h>
using namespace std;
int Kth_max_element(int arr[],int n,int k)
{
    if(k>n)return -1; //If given k is greater then number of elements return -1
    sort(arr,arr+n); //sort the given array
    return arr[k-1]; //return (k-1)th element in the given array.
}
int main()
{
    int n; // Number of elements in the given array
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i]; // Input the elements
    }
    int k;
    cin>>k; // Input K
    cout<<Kth_max_element(arr,n,k)<<"\n";
}

//Test Case 1
// Input :
//4
// 1 2 5 3
// 2
// Output :
// 2


// Test case 2
// input:
// 8
// 1 4 2 7 3 9 10 8
// 4
// Output:
// 4

// Time-Complexity : O(nlogn)
// Space-Complexity : O(n)