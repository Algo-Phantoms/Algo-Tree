/* C++ program to find the sum of all elements of 
   the given array and display the sum as an output*/
   
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, i, sum=0;
    
    cin>>n;
    
    long long int arr[n];
    
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    for(i=0;i<n;i++)
    {
        sum+=arr[i];    // calculates the sum of all elements of the array
    }

    cout<<sum<<endl;    // displaying sum
    
    return 0;
    
}

/*  Test Cases:
   Input: 
   6 
   3 4 23 4 2 16
   
   Output:
   52
   
   Input: 
   4
   0 -1 4 -5
   
   Output:
   -2
   
   Time Complexity: O(n)
   Space Complexity: O(1)
   
*/ 
