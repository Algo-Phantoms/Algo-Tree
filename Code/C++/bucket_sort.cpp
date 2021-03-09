
/* 
  Bucket Sort is a sorting technique that sorts the elements by first dividing the elements into several groups called buckets. 
  The elements inside each bucket are sorted using any of the suitable sorting algorithms or recursively calling the same algorithm.
*/

#include <iostream>
#include <vector>

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

void BucketSort(int A[], int n)
{
  int maximum = maxValue(A, n);
  vector<int> Bins[maximum + 1];

  for (int i = 0; i < n; i++)
    Bins[A[i]].push_back(A[i]);

  int i = 0, k = 0;
  while (i < maximum + 1)
  {
    for (int j = Bins[i].size() - 1; j >= 0; j--)
    {
      A[k++] = Bins[i][j];
    }
    i++;
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

  BucketSort(A, n);

  for (int i = 0; i < n; i++)
  {
    cout << A[i] << " ";
  }

  return 0;
}

/*

    Test Case:

    Input:    7
              4 63 1 53 87 44 36

    Output:   1 4 36 44 53 63 87


    Time Complexity:
    Worst Time Complexity: O(n^2)
    Average Time Complexity: O(n+k) 
    Best Time Complexity: O(n+k)

    Space Complexity: O(n+k)

*/
