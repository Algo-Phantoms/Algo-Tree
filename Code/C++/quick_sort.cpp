/*
	QuickSort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot. We'll pick the right-most element as the pivot in this implementation.
	Partitioning is the main mechanism in quickSort. Provided the array and the element x of the array as a pivot, the target of the partitioning is to place x at its correct location as in the sorted array, and to place all the elements smaller than x, before x, and to place all the elements greater than x, after x.
*/

#include <iostream>
using namespace std;


int *quickSort(int *arr, int left_index, int right_index)
{
    if (left_index >= right_index)				// Base Case
        return arr;

    int pivot = right_index, start = left_index, end = right_index;
    right_index--;
    while (left_index <= right_index)				// Partitioning
    {
        if (arr[left_index] >= arr[pivot] && arr[pivot] >= arr[right_index])				// Swapping the both in this case
        {
            int temp = arr[left_index];
            arr[left_index] = arr[right_index];
            arr[right_index] = temp;
        }
        if (arr[left_index] <= arr[pivot])
            left_index++;
        if (arr[pivot] <= arr[right_index])
            right_index--;
    }

    /* Placing the Pivot */
    int temp = arr[pivot];
    arr[pivot] = arr[left_index];
    arr[left_index] = temp;

    quickSort(arr, start, left_index - 1);				// Sorting the first half
    quickSort(arr, left_index + 1, end);				// Sorting the second half

    return arr;
}

int main()
{
    int n;
    cin >> n;				// Getting the number of Elements
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];				// Getting the unsorted array

    int *sortedArr = quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << sortedArr[i] << ' ';				// Printing the sorted array

    cout << '\n';
    return 0;
}

/* 
 Test Case : 

 Input :	7
			7 6 5 4 3 2 1 
 
 Output : 	1 2 3 4 5 6 7

 Time Complexity: The time taken by QuickSort depends upon the input array and partition strategy. Following are three cases:
	Best Case	: Θ(n.Logn)
	Average Case: Θ(n.Logn)
	Worst Case	: Θ(n^2)

 Space Complexity: O(n)
*/