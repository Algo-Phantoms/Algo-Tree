/*

    - Shell sort is an algorithm that first sorts the elements far apart from each other and successively reduces the interval between the elements to be sorted.
    - It is a generalized version of insertion sort.

*/

#include <iostream>

using namespace std;

void ShellSort(int A[], int n)
{
    int gap, i, j, temp;

    // Start with a big gap, then reduce the gap 
    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is gap sorted  
        for (i = gap; i < n; i++)
        {
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            temp = A[i];
            j = i - gap;

            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }

            //  put temp (the original a[i]) in its correct location 
            A[j + gap] = temp;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int A[n];

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    ShellSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}

/*

    Test Case:

    Input:    7
              64 923 84 738 12 873 2


    Output:   2 12 64 84 738 873 923


    Input:     6
                64 -83 19 -22 73 100


    Output:   -83 -22 19 64 73 100



    Time Complexity:
    Worst Time Complexity: O(n^2)
    Average Time Complexity: O(n*log(n)^2) O(n^(3/2))
    Best Time Complexity: O(n+r)

    Space Complexity: O(1)

*/
