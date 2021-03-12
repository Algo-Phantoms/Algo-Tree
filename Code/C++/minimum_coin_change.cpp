/*
Minimum coin change

Coins of different denominations are given and a total amount of money amount for which we have to find
the minimum number of coins needed to make that amount, if it is not possible then we have to print -1.
Also, infinite number of coins of each type is given.

Approach -
Dynamic programming algorithm will be used to find the minimum number of coins.

First we will be considering a 1D array of size (k+1) where k is the total amount for which
change is needed and initialize the array with infinity.

Then for each value from 1 to k, we iterate the coins whose value is smaller than i and find the minimum, one by
taking that coin and by not taking the coin.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int coins[n];
    for(int i=0;i<n;i++)
        cin>>coins[i];

    int dp[k+1];
    dp[0]=0;    // base case

    // Initialize all table values as Infinite
    for (int i=1; i<=k; i++)
        dp[i] = INT_MAX;

    // Compute minimum coins required for all values from 1 to k
    for (int i=1; i<=k; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<n; j++)
        {
            if (coins[j] <= i)
            {
                int cur = dp[i-coins[j]];
                if (cur != INT_MAX && cur+1 < dp[i])
                    dp[i] = cur + 1;
            }

        }
    }

    int ans=0;
    if(dp[k]==INT_MAX)
        ans = -1;

    ans = dp[k];
    cout<<ans;
}

/*
	Testcases
	Input :
	3 30
	25 10 5
	Output : 2

	Input :
	4 11
	9 6 5 1
	Output : 2

	Time complexity : O(n*k)
	Space complexity : O(k)
*/
