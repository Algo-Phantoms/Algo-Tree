/*
Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.
We basically ignore half of the elements just after one comparison.

Compare the element to be searched (let be x) with the middle element.
1.If x matches with middle element, we return the mid index.
2.Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
3.Else (x is smaller) recur for the left half.
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
	while (left <= right) {
		int mid = left + (right - left) / 2;

		// Check if x is present at mid
		if (arr[mid] == x)
			return mid;

		// If x greater, ignore left half
		if (arr[mid] < x)
			left = mid + 1;

		// If x is smaller, ignore right half
		else
			right = mid - 1;
	}

	// if we reach here, then element was
	// not present
	return -1;
}

int main(void)
{   
	int arr[10];
    cout<<"Enter 10 elements: "<<endl;
    int num = 10;
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
	int x;
    cout<<"Enter the element to be searched: ";
    cin>>x;
    int n= sizeof(arr)/sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? cout << "Element is not present in array"
				: cout << "Element is present at index " << result;
	return 0;
}
/*
Test Cases:
Input:
Enter 10 elements: 
33
22
11
44
55
66
77
88
55
89
Enter the element to be searched: 66
Output:
Element is present at index 5



Input:
Enter 10 elements: 
34
12
44
54
65
76
87
98
09
21
Enter the element to be searched: 45
output:
Element is not present in array
*/

/*

Time Complexity:O(Log n), which is efficient.
Space Complexity: O(1) in case of iterative implementation.
*/

