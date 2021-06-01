/* Unbounded Knapsack
Given:  a knapsack of weight W and n number of items
Task: find the maximum value of items that can be packed into the knapsack if unlimited number of each item can be included
*/

#include <bits/stdc++.h>
using namespace std;
int Knapsack(int w[], int val[], int n, int W)
{
    //Initialization of the array
    int dp[n + 1][W + 1];

    //Base conditions
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (w[i - 1] <= j)
                dp[i][j] = max((val[i - 1] + dp[i][j - w[i - 1]]), dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    int n;
    cin >> n;
    int w[n], val[n];
    for (int i = 0; i < n; i++)
        cin >> w[i] >> val[i];
    int W;
    cin >> W;
    cout << Knapsack(w, val, n, W);
}

/*
TEST CASE 1:

INPUT:
5
10 200
5 60
3 90
2 10
1 6
20

OUTPUT:
552

TEST CASE 2:

INPUT:
2
10 100
2 40
15

OUTPUT:
280

Time Complexity: O(N*W)
Space Complexity: O(N*W)
*/
