/*Dutch National Flag Algorithm is a sorting algorithum to sort an array of 0, 1 and 2's 
 in linear time and without any extra space (such as creating an extra array).*/

//Code for Dutch National Flag Algorithm

#include<iostream>
using namespace std;

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Dutch_National_Flag_Algorithm(int A[], int end)
{
    int start = 0, mid = 0;
    int pivot = 1;
 
    while (mid <= end)
    {
        if (A[mid] < pivot)         // current element is 0
        {
            swap(A, start, mid);
            ++start, ++mid;
        }
        else if (A[mid] > pivot)    // current element is 2
        {
            swap(A, mid, end);
            --end;
        }
        else {                      // current element is 1
            ++mid;
        }
    }
}
 
int main()
{
    int x;//size of array
    cin>>x;
    cout<<endl;
    int A[x];
    for (int i = 0; i < x; i++) {
        cin>>A[i];
    }
    int n = sizeof(A)/sizeof(A[0]);
 
    Dutch_National_Flag_Algorithm(A, n - 1);
 
    for (int i = 0; i < n; i++) {
        cout<<A[i];
    }
 
    return 0;
}

/*Two Test case you can try out with this code-
# Input   12
          0 1 2 2 1 0 0 2 0 1 1 0 
  Output  000001111222  
# Input   6
          1 0 2 0 0 2 
  Output  0 0 0 1 2 2 */

/*Time Complexity = O(n)
Space Complexity = O(1)*/