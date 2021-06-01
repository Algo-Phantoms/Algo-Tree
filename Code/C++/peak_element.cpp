/* 
* A peak element is an element that is greater than its neighbours.
* Problem Statement :- An Array of size n, where nums[i]!=nums[i+1], is given and we need to find out the peak element and return its index.
* For this problem, We would be using binary search Technique.
* Note: Peak element can be more than one,we have to output any ones index.
*/

#include <bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n)
{
    //declaring and initializing two pointers l and r
    //pointing to the leftmost and rightmost element respectively.
    int l = 0, r = n - 1;
    //iterating the elements until l is less than equal to r
    while (l <= r) 
    {
        //computing mid
        // (l+r)/2 directly not used as in some cases int overflow may occur
        int mid = l + (r - l) / 2;
        //checking only those elements whose right and left both neighbour exists
        //excluding the right end and the left end element
        if(mid>0 && mid<n-1)
        {   //both neighbours are smaller,return index
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid-1]>arr[mid])
                r=mid-1;
            else l=mid+1;
        }
        //checking the element at left end
        else if(mid==0)
        {   
            if(arr[0] > arr[1])
                return 0;
            else return 1;
        }
        //checking the element at left end
        else if(mid==n-1)
        {   
            if(arr[n-1] > arr[n-2])
                return n-1;
            else return n-2;
        }
    }
    return -1;
}

int main()
{
    //taking input from user
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array Elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Index of Peak element: ";
    cout << peakElement(arr, n);
}

/* 
Test Cases:
  * Input :-
    Enter size of array: 4
    Enter array Elements: 5 10 20 15
   
  * Output :-
    Index of Peak element: 2
	
  * Input :-
    Enter size of array: 6
    Enter array Elements: 1 3 8 12 4 2
    
  * Output :-
    Index of Peak element: 3

  * Time complexity: O(Log n)
  * Space Complexity: O(1)
*/