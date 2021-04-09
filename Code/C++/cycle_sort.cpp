// C++ program to implement Cycle Sort algorithm
/* Cycle Sort is an unstable in-place sorting algorithm. It is based on the idea that the permutation to be sorted can be factored into cycles,
which can individually be rotated to give a sorted result.

Consider a list of distinct elements. Given an element in it say 'a', we could find the index at which it will occur in the sorted list by simply counting
the number of elements in the entire list that are smaller than the element 'a'.

Now, If the element is already at the correct position, just pass, Else, we will write it to its intended position. That position is inhabited by a different element b,
which we then have to move to its correct position. This process of displacing elements to their correct positions continues until an element is moved to the original
position of a. This completes a cycle.
*/

#include <bits/stdc++.h>
using namespace std;

void cycle_sort(int a[], int n)
{
    int start, ele, pos, temp;

    // Traverse the entire array
    for (start = 0; start <= n - 2; start++)
    {
        ele = a[start];
        pos = start;
        // Count the number of items smaller than ele, towards its right
        for (int i = start + 1; i < n; i++)
            if (a[i] < ele)
                pos++;

        // If element is present in right position
        if (pos == start)
            continue;

        // Ignore if any duplicate element is present
        while (ele == a[pos])
            pos += 1;

        // put the element to it's right position
        if (pos != start)
        {
            swap(ele, a[pos]);
        }

        // Rotate rest of the cycle
        while (pos != start)
        {
            pos = start;
            for (int i = start + 1; i < n; i++)
                if (a[i] < ele)
                    pos += 1;

            while (ele == a[pos])
                pos += 1;

            // Keep the element in its right position
            if (ele != a[pos])
            {
                swap(ele, a[pos]);
            }
        }
    }
}

int main()
{
    int arr[50], n;
    cout << "How many numbers do you want to sort? ";
    cin >> n;
    cout << "Enter the numbers : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cycle_sort(arr, n);
    cout << "The sorted elements are : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

/*
Time Complexity - O(n^2), where 'n' is the size of the array
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

How many numbers do you want to sort? 5
Enter the numbers : 4 2 5 1 3
The sorted elements are :  1 2 3 4 5 

How many numbers do you want to sort? 8
Enter the numbers : 10 31 78 23 15 64 24 4
The sorted elements are :  4 10 15 23 24 31 64 78

*/
