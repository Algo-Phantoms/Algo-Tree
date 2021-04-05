// Binary Search based C++ program to find number
// of rotations in a sorted and rotated array.
#include<bits/stdc++.h>
using namespace std;

// Returns count of rotations for an array which
// is first sorted in ascending order, then rotated
int countRotations(int arr[], int n) {
    
    //Ranges in which our sortest element will be located
    int low = 0, high = n-1;
    
    while(low<=high) {
        //If the segment is already sorted
        //lower index will be the count
        //Return low
        if(arr[low]<=arr[high])
        return low;
        
        // Find mid
        int mid = low + ((high-low)/2);
        
        // Find prev
        int prev = (mid+1)%n;
        
        // Find next
        int next = (mid+n-1)%n;
        
        // Check if mid itself is minimum element
        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev])
        return mid;
        
        // Decide whether we need to go to left half or
        else if(arr[mid]<=arr[high])
            high = mid-1;
        
        // right half
        else if(arr[mid]>=arr[low])
            low = mid+1;
    }
    
}

// Driver code
int main() {
    
    //Number of elements in the array
    int n;
    
    //Enter the number
    cin>>n;
    
    //Sorted rotated array
	int arr[n+1];
	
	//Enter the array elements
	for(int i=0;i<n;i++)
	cin>>arr[i];

    //Print the rotations
	cout << countRotations(arr, n) << endl;
	return 0;
}

// Test case - 1
// Input:
// n = 6
// arr[] = {4, 5, 6, 1, 2, 3}
// Output:
// 3

// Test case - 2
// Input:
// n = 9
// arr[] = {12, 13, 14, 15, 16, 19, 6, 7, 9}
// Output:
// 6

// Time Complexity: O(Logn)
// Space Complexity: O(1)