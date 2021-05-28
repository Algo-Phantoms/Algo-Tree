
/* 
  Bucket Sort is a sorting technique that sorts the elements by first dividing the elements into several groups called buckets. 
  The elements inside each bucket are sorted using any of the suitable sorting algorithms or recursively calling the same algorithm.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to find max value
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

// Function for Bucket Sort
void BucketSort(int A[], int n)
{
	// Calling function get maximum value among all the elements
	int maximum = maxValue(A, n);

	//  Create empty bins
	vector<int> Bins[maximum + 1];

	// Insert elements in their rescpetive bin
	for (int i = 0; i < n; i++)
		Bins[A[i]].push_back(A[i]);

	// Get the sorted elements
	int i = 0, k = 0;
	while (i < maximum + 1)
	{
		for (int j = Bins[i].size() - 1; j >= 0; j--)
			A[k++] = Bins[i][j];
		i++;
	}
}

int main()
{
	int n; 
	// Number of elements
	cin >> n;
	int A[n];

	// Taking input of the elements
	for (int i = 0; i < n; i++)
		cin >> A[i];

	// Calling function to sort the elements using Bucket Sort
	BucketSort(A, n);

	// Displaying Sorted Elements
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	return 0;
}

/*

    Test Case:
    Input:   		7
              	4 63 1 53 87 44 36
    Output:   	1 4 36 44 53 63 87

    Input:   		6
              	5 3 12 7 21 4
    Output:   	3 4 5 7 12 21

    Time Complexity:
    Worst Time Complexity: O(n^2)
    Average Time Complexity: O(n+k) 
    Best Time Complexity: O(n+k)

    Space Complexity: O(n+k)

    where O(n) is the complexity for making the buckets and 
    O(k) is the complexity for sorting the elements of the bucket
*/
