/*
Given prices of a stock over n days,
Find the maximum Profit earned in at most k transactions over n days.
A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed. 
*/

/*
DYNAMIC PROGRAMMING APPROACH:-
(I) We will a 2d dp array 
    profit[t][i] represents the maximum profit using at most t transactions up to day i (includeing day i) 

    Then profit[t][i]=max(profit[t][i-1],max(price[i]-price[j]+profit[t-1][j]));
        for all j in range[0,i-1]

    profit[t][i] will be maximum of-
        1) profit[t][i-1] which represents not doing any transaction on day i
        2) Maximum profit gained by selling on ith day. in order to sell stock on ith day, we need to purchase it on the any of the [0..i-1] days. 
            So if we buy shares on jth day and sell it on ith day, max profit earned will be price[i]-price[j] + profit[t-1][j] where j varies from 0 to i-1.

    profit[t][i] = max(profit[t][i-1],price[i]-price[j] + profit[t-1][j]);

    This approach will give a Time Complexity of O(k*n*n)
            where k is the number of transactions and n is the number of days.

OPTIMISED DYNAMIC PROGRAMMING APPROACH
 If we are able to calculate the maximum profit gained by selling shares on the ith day in constant time then the time complexity can be reduces to O(n*k)
Now 
    profit[i][j]=max(profit[t][i-1],max(price[i]-price[j]+profit[t-1][j])) for all j in range 0 to i-1

If we carefully observe
    max(price[i]-price[j]+profit[t-1][j]) for all j in range[0,i-1] 
        can be written as 
    prices[i]+max(profit[t-1][j]-price[j])
        for all in range[0,i-1]
        =price[i]+max(prevDiff,profit[t-1][j]-price[j]) 
            where prevDiff is max(profit[t-1][j]-price[j]) where j ranges[0,i-2]
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

/*Utility function to find the maximum profit */
int maxProfit(int price[], int n, int k){

    /*matrix to store results of sub Problems
    profit[t][i] stores maximum profit using atmost t transactions up to day i
    */
    int profit[k+1][n+1];

    //for day 0 profit earned will be 0
    for(int i=0;i<=k;i++)
    profit[i][0]=0;

    //for 0 no of transactions the profit earned will be 0
    for(int i=0;i<=n;i++)
    profit[0][i]=0;

    //fill the matrix in bottom up manner
    for(int i=1;i<=k;i++)
    {
        //initialise a minimum variable to store the difference between profit earned and price on previous day
        int prevDiff=INT_MIN;
        for(int j=1;j<n;j++)
        {
            //update the previous difference with maximum profit that can be earned till j-1 day
            prevDiff = max(prevDiff, profit[i-1][j-1]-price[j-1]);

            //update profit[i][j]
            profit[i][j]=max(profit[i][j-1],price[j]+prevDiff);
        }
    }

    //return the maximum profit earned from k transactions after n days.
    return profit[k][n-1];
}

signed main(){
    
    //Take input of the number of days and no of transactions allowed.
    int n,k;
    cin>>n>>k;

    //Input the price of stock on n days.
    int price[n];
    for(int i=0;i<n;i++)
         cin>>price[i];

    cout<<"Maximum Profit earned : "<<maxProfit( price , n , k )<<endl;

    return 0;

}

/*
Test Case: 
    Input: 
        8 3
        12 14 17 10 14 13 12 15
    
    Output:
        Maximum Profit earned : 12

    Input:
        3 2
        2 4 1
    
    Output:
        Maximum Profit earned : 2  

Time Complexity: O(n*k)
                    where n is the no of days and k is the number of transactions 

Space Complexity: O(1)
*/