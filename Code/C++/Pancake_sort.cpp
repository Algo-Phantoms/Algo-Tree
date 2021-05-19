/*
    PANCAKE SORT
    - Sorting the sequence by making minimum reversals
*/
#include <bits/stdc++.h>
#define scan(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define input(n) int n; cin>>n;
using namespace std;

// function to reverse the array by flipping elemenets
void flip(int arr[], int n)
{
    int temp, i = 0;
    while (i < n)
    {
        temp = arr[i];
        arr[i] = arr[n];
        arr[n] = temp;
        i++;n--;
    }
}

// function that returns index of maximum element.
int Maximum_element(int arr[],int n)
{
    int mi=0,maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
            mi=i;
        }
    }
    return mi;
}

void Pancake_sort(int arr[],int n)
{
    int maxi_index=0;
    for(int current_size = n; current_size>1;current_size--)           // decreasing the size of array by 1 each time.
    {
        maxi_index = Maximum_element(arr,current_size);         //finding the index of maximum element.

        if(maxi_index != current_size-1)            // checking if index of maximum element is not equal to current array size.
        {
            flip(arr,maxi_index);               // flipping or reversing the array from start till the index of max element.
            flip(arr,current_size-1);           // flipping or reversing the array from start till the decreased array size.
        }
    }
}

int main()
{
    input(n);    //enter number of elements in an array
    int arr[n];
    scan(arr,n);   // enter n elements in array

    Pancake_sort(arr,n);         // calling Pancake sort function

    for(int i=0;i<n;i++)        // printing sorted array
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}


/*
    Test Cases:
    INPUT :  8
             4 9 0 1 6 7 3 2

    OUTPUT : 0 1 2 3 4 6 7 9

    INPUT :  5
             2 0 -1 9 7

    OUTPUT :  -1 0 2 7 9

    Time Complexity:
    Worst Time Complexity: O(n^2)
    Average Time Complexity: O(n^2)
    Best Time Complexity: O(1)

    Space Complexity: O(n)
*/
