/* 
* Sorted array is one in which the elements are arranged either in ascending order or in descending order.

* Problem Statement :- A clockwise rotated sorted Array of size n and distinct element is given and we need to find out the number of times it is rotated.

* For this problem, let us consider array is previously arranged in ascending order and then it was rotated.
* Now, to find the number of rotations, we have to search for the smallest element as every element will be 
shifted by same number of positions as the first element is shifted.

*/

#include <bits/stdc++.h>
using namespace std;

int noOfRotation(int arr[], int n)
{
    ///variable to store no. of times the array is rotated
    int ans = -1;
    //if last element is greater than 1st that is array sorted
    //return 0 as number of rotation equals zero
    if (arr[0] < arr[n - 1]) {
        return 0;
    }

    //declaring and initializing two pointers l and r
    //pointing to the leftmost and rightmost element respectively.
    int l = 0, r = n - 1;
    //iterating the elements until l is less than equal to r
    while (l <= r) {

        if (arr[l] <= arr[r])
            return l;
        //computing mid
        // (l+r)/2 directly not used as in some cases int overflow may occur
        int mid = l + (r - l) / 2;
        //Array cannot have negative indices therefore to avoid it, n is added
        //To avoid out of bound condition take modulo n
        int previous = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        if (arr[mid] <= arr[next] && arr[mid] <= arr[previous]) {
            ans = mid;
            break;
        }
        //if arr[mid] is greater than arr[l] then search space which in right to mid
        //should be included and left one to be discarded
        if (arr[l] <= arr[mid])
            l = mid + 1;
        //if arr[mid] is less than arr[r] then search space which in left to mid
        //should be included and right one should be discarded
        // we will go on decreasing the left search space
        else if (arr[mid] <= arr[r])
            r = mid - 1;
    }
    return ans;
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
    cout << "Number of times sorted array is rotated: ";
    cout << noOfRotation(arr, n);
}

/* 
Test Cases:

  * Input :-
    Enter size of array: 8
    Enter array Elements: 5 6 7 8 9 1 2 3
   

  * Output :-
    Number of times sorted array is rotated: 5
	
  * Input :-
    Enter size of array: 6
    Enter array Elements: 60 70 80 20 40 50
    
  * Output :-
    Number of times sorted array is rotated: 3

  * Time complexity: O(Log n)
  * Space Complexity: O(1)

*/
