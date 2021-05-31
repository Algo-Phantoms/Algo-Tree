/*
Problem statement: Find minimum number of coins required to get sum equals to given total.
Language: C++
input: n            ------>size of array which contains type of coins we have
arr[] -arr[0] arr[1] ..... arr[n-1]         ----->next line space seperated integers (coins type)
total                                       ------>total amount 
output:  ans                                ----->only line of output will give us minimum number of coins which sum as "total"
*/

/*
This is a classic dynamic programming problem. If you maintain an array of different type of coins available i.e arr change can be made from 0 to n-1  
you can step through each denomination starting at its index and incrementing to the right, adding dp[i-arr[j]] to each of the element dp[j] to get running total.
After filling the dp array in the bottom-up manner, our final solution gets stored at the last Index of the array i.e. return
*/

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int count_coins(int a[],int n,int sum)
{
	int dp[sum+1]; // temporary array Initialization or base case
	int i,j;
	for(i=0;i<=sum;i++)
	dp[i]=INT_MAX;
	dp[0]=0; // Initialize all table values

	// Now Calculate minimum coins required
	for(i=1 ;i<=sum;i++)
	{ 
		for(j=0;j<n;j++)
		{
			if(dp[i-a[j]]+1<dp[i] && dp[i-a[j]]!=INT_MAX)
			dp[i]=min(dp[i-a[j]]+1,dp[i]);
			
		}
	}
    if(dp[sum]==INT_MAX)
    return -1;
	return dp[sum];
}


int main()
{
	int n,i,sum;
    cout<<"Enter number of coins: ";
	cin>>n;
	int a[n];
    cout<<"Provide coins value: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>sum;
    int ans=count_coins(a,n,sum);
	if(ans==-1)
	cout<<"Not possible!\n";
	else
	cout<<"Minimum number of coins whose total is equal to provided sum: "<<ans<<endl;
	return 0;
}

/*
e.g-1)
Enter number of coins: 4
Provide coins value: 2 3 4 1
22
Minimum number of coins whose total is equal to provided sum: 6
e.g-2)
Enter number of coins: 4
Provide coins value: 3 6 2 5
40
Minimum number of coins whose total is equal to provided sum: 7
*/


//Time complexity: O(n*sum)				----->where n is size of the array and sum is required sum
//Space Complexity = O(sum)
