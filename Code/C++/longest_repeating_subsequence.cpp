/*
 * longest repeating subsequence find's the length of the longest repeating subsequence so that two subsequence do not have 
   a same string chracter at the same position which means that any character at i'th position should not have same index
   in the original string
 * A subsequence is defined as the sequence that has same relative order but not neccesarily in a contiguous manner.
 * This is an application of the longest common subsequence(LCS) problem with some added conditions
 * Approach used :
   --> In this problem a dynamic programming solution will be used as the recursive algorithm have a overlapping
       subproblem which can be solved by using dynamic programming. We can use both tabulation and memoization but we will be using 
       tabulation in bottom up manner.
   --> First we will be considering a 2D array of size (n+1) * (n+1) where n is the size of given string
       and we are taking an extra column and row to get the value of the substring of length 1 and 1 we need to have to value of 01, 00, 10
   --> In this problem only a single string will be given but we will consider the same string twice and solve the problem    
   --> Any position at i,j i.e dp[i][j] will denote the length of longest repeating subsequence of prefix string of s[0...i-1] and prefix
       string of s[0...j-1]
   --> we will iterate over each row and then iterate over each column of the respective row simultaneously
       and match the last character and check whether the i'th character is not same as the j'th character and if it matches
       we calculate this step as an operation and add 1 to the solution whereas if it do not match then we take the maximum by reducing
       the length of the row or the column by one.
   --> After completing the operation we print out the dp[n][n] which is the last cell of the matrix and that is the required answer length of the
       longest repeating subsequence     
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
     //Fast Input Output (I/O) operation by matching the synchronization
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     //Taking the number of Test Cases
     int t;
     cin >> t;
     while (t--)
     {
         //Taking the input of the string
         string s;
         cin >> s;

         //Calculating the length of the string
         int n = s.length();

         //Constructing a 2D matrix of size n+1 and n+1 size
         int dp[n + 1][n + 1];

         //Initializing the first row as 0
         for (int i = 0; i <= n; i++)
         {
             dp[i][0] = 0;
         }

         //Initializing the first column as 0
         for (int j = 0; j <= n; j++)
         {
             dp[0][j] = 0;
         }

         //Traversing over each row followed by traversing of the column
         //of that particular row of the dp table
         for (int i = 1; i <= n; i++)
         {
             for (int j = 1; j <= n; j++)
             {
                 ////Checking if the last two character of both the string match or not
                 //and the i'th character is not matching with the j'th character
                 //If the character matches and the i and j are not matching then we
                 //calculate it as a operation so we add a +1 to the solution
                 if (s[i - 1] == s[j - 1] && i != j)
                 {
                     dp[i][j] = 1 + dp[i - 1][j - 1];
                 }
                 //Else we will take the maximum after reducing then length of either
                 //first string or the second string
                 else
                 {
                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                 }
             }
         }
         //This is out final answer for the Longest repeating subsequence problem
         cout << dp[n][n] << endl;
     }
     return 0;
 }

 /*
 * Sample Test cases for the longest repeating subsequence problem :
     Input 1:
     3
     aabb
     aabcbc
     addrty
     Output 1:
     2
     3
     1
     Input 2:
     3
     aab
     abc
     axxxy
     Output 2:
     1
     0
     2
 * An example to demostrate the table view of the solution is
     Input: aab
     Output: 1
         a  a  b
      0  0  0  0
   a  0  0  1  1
   a  0  1  1  1
   b  0  1  1  1
   
 * So dp[n][n] i.e 1 is the required length of the longest repeating subsequence.
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 */