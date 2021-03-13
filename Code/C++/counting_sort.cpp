/*
----------------------- Counting Sort Algorithm----------------------- 

1) Take a count array to store the count of each unique object.
2) Modify the count array such that each element at each index stores the sum of previous counts.
3) Store each number from the input sequence followed by decreasing its count by 1.
4) Copy the content of temporary array used to the original array.

----------------------- Time Complexity ----------------------- 
Best case = O(n+k)
Average case = O(n+k)
Worst case = O(n+k)

----------------------- Space Complexity ----------------------- 
Space complexity = O(n+k)

*/

#include <bits/stdc++.h>
using namespace std;

// Printing array function
void showarray(int *ar, int n)
{
  for (int i = 0; i < n; i++)
    cout << ar[i] << " ";
  cout << "\n";
}

// Counting sort function
void countSort(int *ar, int n)
{
  // Initializing variable 'max' with minus infinity and 'min' variable with plus infinity.
  int max = INT_MIN, min = INT_MAX;

  // Finding maximum and minimum element in the entered array
  for (int i = 0; i < n; i++)
  {
    if (min > ar[i])
    {
      min = ar[i];
    }
    if (max < ar[i])
    {
      max = ar[i];
    }
  }

  // count array is used to store the frequency of each element in the entered array.
  int *count = new int[max - min + 1];
  // temp array is used to temporarily store the values from the main array as final answer.
  int *temp = new int[n];

  for (int i = 0; i < (max - min + 1); i++)
  {
    count[i] = 0;
  }

  // Storing the frequency of each element in the count array
  for (int i = 0; i < n; i++)
  {
    count[ar[i] - min]++;
  }

  // Modifying the count array such that each element at each index stores the sum of previous count.
  for (int i = 1; i < (max - min + 1); i++)
  {
    count[i] += count[i - 1];
  }

  // Storing elements from original array into temp array as per the position of elements in count array.
  for (int i = n - 1; i >= 0; i--)
  {
    temp[count[ar[i] - min] - 1] = ar[i];
    count[ar[i] - min]--;
  }

  // Copying sorted elements back to the original array.
  for (int i = 0; i < n; i++)
  {
    ar[i] = temp[i];
  }
}

int main()
{
  int n, i;
  cout << "Input: ";
  cin >> n; // Accepting number of elements to be sorted from the user.
  int *ar = new int[n];
  for (i = 0; i < n; i++)
  {
    cin >> ar[i]; // Accepting numbers to be sorted
  }
  cout << "Output: ";
  countSort(ar, n);
  showarray(ar, n);
  return 0;
}

/*
    Test Case:

    Input: 9
    7 5 3 6 9 8 1 2 4

    Output: 1 2 3 4 5 6 7 8 9 


    Input: 10
    14 77 2 -9 6 44 -27 3 50 100

    Output: -27 -9 2 3 6 14 44 50 77 100 

*/