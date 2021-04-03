// C++ program to implement Cycle Sort algorithm
/* Cycle Sort is an unstable in-place sorting algorithm. It is based on the 
idea that one of the permutation of the numbers is in sorted order */

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
        for (int i = start + 1; i < n; i++)
            if (a[i] < ele)
                pos++;

        // If element is present in right position
        if (pos == start)
            continue;

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
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I

How many numbers do you want to sort? 5
Enter the numbers : 4 2 5 1 3
The sorted elements are :  1 2 3 4 5 

*/
