// Remove Duplicates from the sorted array.

#include<iostream>
using namespace std;

// Function for removing Duplicates.
int remove_Duplicates(int a[], int n)
{
    // Take separate index for pointing the unique elements.
    int k = 0;

    // Traverse Elements of an array.
    for (int i = 1; i < n; i++)
    {
        // Check, If ith element is not equal to kth element,
        // Then store ith value in a[k].
        if (a[i] != a[k])
        {
            k++;
            a[k] = a[i];
        }
    }
    //
    return k + 1;
}

int main()
{
    // Input size of an array.
    int n;
    cin >> n;

    int a[n];
    // Input Elements in an array.
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // calling function when number of elements
    // in array is greater than 1
    if (n > 1)
    {
        // remove_Duplicates() returns the new size of array.
        n = remove_Duplicates(a, n);
    }

    // Print Updated array.
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
/*
    Test cases :

    Input 1 :

        8
        1 1 2 2 3 3 4 4

    Output 1 :

        1 2 3 4

    Input 2 :

        9
        1 2 2 3 4 4 4 5 5

    Output 2:

        1 2 3 4 5

    Time complexity: O(n)
    Space Complexity: O(n)
*/
