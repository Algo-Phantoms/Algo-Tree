/*
 Binary Search: Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array.
 If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
 Otherwise narrow it to the upper half.
 Repeatedly check until the value is found.


Compare x with the middle element.
If x matches with middle element, we return the mid index.
Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
Else (x is smaller) recur for the left half.
*/
//  Binary Search implementation
#include <bits/stdc++.h> 
using namespace std; 

int binarySearch(int arr[], int left, int right, int val) 
{ 
	if (right >= left) { 
		int middle = left + (right - left) / 2; 

		// If the element is present at the middle 
		// itself 
		if (arr[middle] == val) 
			return middle; 

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (arr[middle] > val) 
			return binarySearch(arr, left, middle - 1, val); 

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(arr, middle + 1, right, val); 
	} 

	// We reach here when element is not 
	// present in array 
	return -1; 
} 

int main(void) 
{ 
 
    int n;
    cin>>n;
	int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    

	int x;
    cin>>x; 
	
	int result = binarySearch(arr, 0, n - 1, x); 
	(result == -1) ? cout << "Element is not present in array"
				: cout << "Element is present at index " << result; 
	return 0; 
} 



/*
Testcases:
testcase1:
input:
6
2 3 4 5 6 7
4
output:
Element is present at index 2
testcase2:
input:
4
3 56 22 88
9
output:
Element is not present in array

TC:The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Log n).
SC:O(Logn) recursion call stack space.
*/