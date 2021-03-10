/*
* Shortest Common Supersequence finds the shortest supersequence which consist of all the characters of both the string in the order specified.
* Supersequence have the same relative order but may or may not be continuous.
* Problem Statement :- Given two strings s1 and s2 and we have to find the shortest supersequence consisting of both s1 and and s2.
* Approach used :- As we see we have 2 options either we should include a character of a string or either not.Thus we have to make choices and hence we will be using dynamic programming approach as the same process is repeated again and again.
* First we will be considering a 2D array of size (n+1) * (m+1) where n and m are the size of first and second string respectively
  and we are taking an extra column and row to get the value of the substring of length 1 to n (by 0 we determine the base conditions)
* Any position at i,j i.e dp[i][j] will denote the length of longest common subsequence of prefix string of s1[0...i-1] and prefix
  string of s2[0...j-1]
* For the shortest superstring, the common character between s1 and s2 should be included once and as we know the sequence of common character is what we call as LCS i.e. LCS should be included once in the result and all other characters will be concatenated as it is to mmake a final superstring.
* Therefore, we conclude that Shortest Supersequence = n+m - LCS.

*/
#include<bits/stdc++.h>
using namespace std;

	//defining function to calculate lcs
int LCS(string s1, string s2, int n, int m){
	 	 //constructing an 2D matrix of size n+1 and m+1 
  	int dp[n+1][m+1];

  for(int i=0;i<=n;i++)
  	for(int j=0;j<=m;j++)
  	{	//base condition
  		//initializing the first row and first column as 0
  			if(i==0 || j==0)
  			dp[i][j]=0;
  	}

  		//finding LCS
  	for(int i=1;i<n+1;i++)
  	{	for(int j=1;j<m+1;j++)
  		{	 //cheking if character matches or not
  			//and if it matches then we add 1 to the solution
  			if(s1[i-1]==s2[j-1])
  				dp[i][j]=1+dp[i-1][j-1];

  			//else length should be reduced and maximum of first or second string should be taken
  			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
  		}
    }
  	return dp[n][m];

}

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cin.tie(NULL);
 	// taking two strings
  	string s1,s2;
  	cin>>s1>>s2;
  	//calculating length of string
  	int n=s1.length();
  	int m=s2.length();
  	// calculating shortest supersequence
  	cout<< m+n-LCS(s1,s2,n,m)<<endl;


}

/*
Sample Test cases :-

	Input 1:
	aggtab
	gxtxayb

	Output 1:
	9

	Input 2:
	luck
	cyk

	Output 2:
	5

	Table view of input 1:-

			l  u  c  k
		 0	0  0  0  0
	 c   0  0  0  1  1
     y   0  0  0  1  1
	 k	 0  0  0  1  2
	
	Largest Supersequence : luckcyk (concatenating both strings)
	 LCS=2
	 shortest subsequence =m+n-LCS

* TIme Complexity: O(m*n)
* Space Complexity: O(m*n)

*/
