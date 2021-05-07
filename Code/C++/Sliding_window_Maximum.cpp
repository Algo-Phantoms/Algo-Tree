/* 
Problem: Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.

eg.) Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, k = 3
     Output: 3 4 5 6 7 8 9 10 


Explanation: Maximum of first window 1,2,3 is ---> 3
	     Maximum of next window 2,3,4 is ---> 4
	     Maximum of next window 3,4,5 is ---> 5
	     Maximum of next window 4,5,6 is ---> 6
	     Maximum of next window 5,6,7 is ---> 7
	     Maximum of next window 6,7,8 is ---> 8
	     Maximum of next window 7,8,9 is ---> 9
	     Maximum of next window 8,9,10 is ---> 10

*/

#include<bits/stdc++.h>
using namespace std;

// Function to slide the window and get maximum of them.
void slide_window(int arr[], int n, int k)
{
    vector<int> v;
    priority_queue<int> maxh;    // max-heap
    for(int i = 0; i<n; i++)
    {
        maxh.push(arr[i]);

	// If size of max-heap is equal to k, store the top element and then make the heap empty.
        if(maxh.size() == k)     
        {
            cout<<maxh.top()<<" ";
            while(maxh.size() > 0)
                maxh.pop();
            if(i == n)
                return;
            else
                i-= k-1;
        }
        
    }
}

int main()
{
    int n,k;
    cout<<"Size of array: ";
    cin>>n;
    cout<<"Array elements: ";
    int arr[n];
    for(int i = 0; i<n; i++)
    {
       cin>>arr[i];
    }
    cout<<"Value of k: ";
    cin>>k;
    slide_window(arr,n,k);
    return 0;
}


/* Test Cases

1) Input --> arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, k = 4
   Output --> 10 10 10 15 15 90 90 

2) Input --> arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6} , k = 3
   Output --> 3 3 4 5 5 5 6 
*/

// Time Complexity ---> O(n*(logk + k)) = O(n*k)
// Space Complexity ----> O(k) <---- To store elements in heap
