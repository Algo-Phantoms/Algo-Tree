/*

* Bubble sort is a sorting algorithm that is most commonly used to sort an array or list of elements.
* Here we are implementing this algorithm, which can sort the array in either increasing or decreasing
  order depending upon the parameter choosen.

* Approach used : Compare two adjacent element , if they are not in desired order swap them. The pass through
  the list is repeated until the list is sorted.
* If we have n elements then it can take upto n-1 passes to sort this list.
* Here we are implementing the optimized bubble sort, as we can observe that the n-th pass finds the n-th 
  largest element and puts it into its final place. So, the inner loop can avoid looking at the last n − 1 items when running for the n-th time: 
* Stable as well as adaptive algorithm.

*/
#include <bits/stdc++.h>
using namespace std;
//  In the function call when increasing=false ,this function will sort the list in decreasing order,
//  by default it sorts in increasing order.
void bubble_sort(int arr[],int n,bool increasing=true)
{
  //loop for passes
    for(int i=0;i<n-1;i++)
    {
    bool at_least_one_swap=false;
    for(int j=0;j<(n-i-1);j++)
        {
          if(increasing==true)
          {  if(arr[j]>arr[j+1])
            {
            swap(arr[j],arr[j+1]);
            at_least_one_swap=true;
            }
          }  
          else
          {
             if(arr[j]<arr[j+1])
            {
            swap(arr[j],arr[j+1]);
            at_least_one_swap=true;
            }
          }
        }
        /*
        here we are breaking the outer loop because when not a single swap happens, then we can ensure
        that our list has been sorted , there is no need of more passes. 
        */
        if(at_least_one_swap==false)
        break;
    }
}
int main()
{
   ios_base::sync_with_stdio(0); 
   cin.tie(0);
   cout.tie(0);
  //Taking the number of test cases
  int t;
  cin >> t;
  while (t--)
  {
    //Taking input for the number of elements in the array
    int n;
    cin>>n;
    int arr[n];
    
    //Taking input each array element
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    //calling user defined function bubble_sort(int arr[],int n,bool increasing=true) 
    bubble_sort(arr,n);
    
    //array after sorting
    for(int i=0;i<n;i++)  
    cout<<arr[i]<<" ";
    
    cout<<endl;
    
  }
  return 0;
}

/*

* A sample test case for the bubble_sort

    TEST CASE:

    Input 1:
    2
    10
    10 9 8 7 6 5 4 3 2 1
    5
    89 11 5 98 100

    Output 1:
    1 2 3 4 5 6 7 8 9 10
    5 11 89 98 100


    Time Complexity : 
    Worst case complexity : O(n^2)
    Best case complexity : O(n)
    Average case complexity :  O(n^2)
    Space complexity: Θ(1) 
*/