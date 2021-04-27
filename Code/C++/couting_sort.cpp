/*

  - Counting sort is a stable sorting technique
  - It is used to sort objects according to the keys that are small numbers
  - It counts the number of keys whose key values are same
  - This sorting technique is effective when the difference between different keys are not so big, otherwise, it can increase the space complexity.

*/

#include <iostream>

using namespace std;

int maxValue(int A[], int n)
{
    int m = A[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (A[i] > m)
            m = A[i];
    }
    return m;
}

void CountSort(int A[], int n)
{
    int i, *C, j;

    // Obtaining thr max value from the array
    int max = maxValue(A, n);

    C = (int *)malloc((max + 1) * sizeof(int));

    // Initialize empty array
    for (i = 0; i < max + 1; i++)
        C[i] = 0;

    //  // Insert elements in their rescpetive position (array index)
    for (i = 0; i < n; i++)
        C[A[i]]++;

    // Get the sorted elements
    i = 0, j = 0;
    while (i < max + 1)
    {
        if (C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }
        else
            i++;
    }
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    CountSort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}

/*

    Test Case:

    Input:    6
              34 22 65 38 99 48

    Output:   22 34 38 48 65 99


    Input:    10
              10 72 82 30 67 28 75 1 55 34

    Output:   1 10 28 30 34 55 67 72 75 82



    Time Complexity:
    Worst Time Complexity: O(n+r)
    Average Time Complexity: O(n+r)

    Space Complexity: O(n+r)

*/
