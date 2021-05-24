/*
LONGEST BITONIC SUBSEQUENCE- 
It is the longest subsequence in which array is sorted such that 
it is first in increasing order to the peak  and then in decreasing 
order .
 
*/

/* lbs()  length of the Longest Bitonic Subsequence in
    arr[] of size n. The function mainly creates two temporary arrays
    lis[] and lds[] and returns the maximum lis[i] + lds[i] - 1.
 
    lis[i] -Longest Increasing subsequence ending with arr[i]
    lds[i] -Longest decreasing subsequence starting with arr[i]
*/
int lbs( int arr[], int n )
{
   int i, j;
 
   /* Allocate memory for lis[] and initialize LIS values as 1 for
      all indexes */
   int *lis = new int[n];
   for (i = 0; i < n; i++)
      lis[i] = 1;
 
   /* Compute LIS values from left to right */
   for (i = 1; i < n; i++)
      for (j = 0; j < i; j++)
         if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
 
   /* Allocate memory for lds and initialize LDS values for
      all indexes */
   int *lds = new int [n];
   for (i = 0; i < n; i++)
      lds[i] = 1;
 
   /* Compute LDS values from right to left */
   for (i = n-2; i >= 0; i--)
      for (j = n-1; j > i; j--)
         if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
            lds[i] = lds[j] + 1;
 
 
   /* Return the maximum value of lis[i] + lds[i] - 1*/
   int max = lis[0] + lds[0] - 1;
   for (i = 1; i < n; i++)
     if (lis[i] + lds[i] - 1 > max)
         max = lis[i] + lds[i] - 1;
   return max;
}
 
/* Driver program to test above function */
int main()
{ 
  
  int arr[];
  int n;
  cout<<"enter the number of array element you want to enter";
  cin>>n;
  for(int i=0;i<n;i++)
  {
  cin>>arr[i];
  }
  cout<<"Length of LBS is "<<lbs( arr, n ) ;
  return 0;
}