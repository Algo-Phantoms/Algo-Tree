/* 
Kadane's Algorithm is used to solve the maximum subarray sum problem.

The maximum subarray problem is the task of finding the largest 
possible sum of a contiguous subarray.
	
We make three cases in this algorithms.

1 - all the array elements are postive - then complete array 
sum is the largest subarray sum.

2 - all the array elemets are negative - then smallest elements 
is the largest subarray sum.

3 - elements are mix of positive and negative numbers - then we keep adding 
elements in the variable until the variable is positive. We keep track of the
variable value after each addition, so that we know the maximum value it rose to,
that maximum value is our answer. 
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	ll int n,maxs;
	cin>>n;
	// no of elements in the array
	    
	ll int arr[n],i,sum=0,pos=0,neg=0, maxi = INT_MIN;
	    
	for(i=0;i<n;i++)
	{
	    cin>>arr[i];
		// array input
	        
		sum += arr[i];
		// complete sum of the array
	        
	    if(arr[i] >=0 )
	    pos++;
		// no of positive values
	        
	    else
	    neg++;
		// no of negative values
	}
	    
	    
	if(pos == n)
	// if all elements are positive
	printf("%lld\n",sum);
	    
	else if(neg == n)
	// if all elements are negative
	{
	    for(i = 0; i<n; i++)
	    maxi = max(maxi , arr[i]);
		// find the largest element
	        
	    printf("%lld\n",maxi);
		// print the largest elements
	}
	else
	{
	    ll int left = 0;
	    ll int maxs = 0;
	        
	    for(i=0; i<n; i++)
	    {
	        if( left + arr[i] <=0 )
			// if variable becomes negative, reset left to 0				
	        {        
	            left = 0;
	        }
	            
	        else
			// add if the variable will remain positive
	        {
	            left += arr[i];
	            maxs = max(maxs,left);
				// keep track of variable's value to know the maximum
	            
	        }
	            
	    }
	        
	    printf("%lld\n",maxs);
		// print the answer
	}
}
/*
Testcase

Input :

5
4 1 -3 7 12

Output : 21

Input :

6
-1 -4 -5 8 7 9

Output : 24

Time complexity : O(n) in average case
Space complexity : O(1)

*/
