/*

* longest common subsequence finds the longest subsequence that is present in both the strings.
* A subsequence is defined as the sequence that is same relative order but not neccesarily in a contiguous manner.
* Problem Statement : Given two strings s1 and s2 and we have to find the longest common subsequence from both the string
* Approach used : In this problem a dynamic programming solution will be used as the recursive algorithm have a overlapping
  subproblem which can be solved by using dynamic programming. We can use both tabulation and memoization but we will be using 
  tabulation in bottom up manner.
* First we will be considering a 2D array of size (n+1) * (m+1) where n and m are hthe size of first and second string respectively
  and we are taking an extra column and row to get the value of the substring of length 1 and 1 we need to have to value of 01, 00, 10
* Any position at i,j i.e dp[i][j] will denote the length of longest common subsequence of prefix string of s1[0...i-1] and prefix
  string of s2[0...j-1]
* An example to demostrate the table view of the solution is
  s1 : BAZ
  s2 : AXYZ

        B  A  Z
     0  0  0  0
  A  0  0  1  1
  X  0  0  1  1
  Y  0  0  1  1
  Z  0  0  1  2

  So dp[n] i.e 2 is the required answer here as we can see that "AZ" is the longest common subsequence int the example problem .
* Time complexity for this solution is O(nm)
* Space complexity for this solution is O(nm)

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    //Taking the number of test cases
    int t;
    cin >> t;
    while (t--)
    {
        //Taking input of the two strings
        string s1, s2;
        cin >> s1 >> s2;

        //Calculating the length of the two string
        int n = s1.length();
        int m = s2.length();

        //Constructing an 2D matrix of n+1 and m+1 size
        int dp[n + 1][m + 1];

        //Initializing the first row as 0
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        //Initializing the first column as 0
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }

        //Finding the longest common subsequence
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                //Checking if the last two character of both the string match or not
                //If the character matches then we calculate it as a operation so we
                //add a +1 to the solution
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                //Else we will take the maximum after reducing then length of either
                //first string or the second string
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        //This is out final answer for the LCS problem
        cout << dp[n][m] << endl;
    }
    return 0;
}

/*

* A sample test case for the LCS problem

TEST CASE:

    Input 1:
    2
    baz
    axyz
    aggtab
    gxtxayb

    Output 1:
    2
    4


Time Complexity: O(nm)
Space Complexity: O(nm)

*/