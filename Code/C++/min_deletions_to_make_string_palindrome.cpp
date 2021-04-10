/*
 PROBLEM-Remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.
                                                    agbcba
                                                   /   |    \
                                                  /    |     \
                    for palindrome sequence-    bcb   abcba   a
                                  deletions-    3		1	  5	
                                  
           ->for above exaple answer will be min among 3,1 and 5 i.e 1
           
 *Note: The order of characters in the string should be maintained.
 *you may refer longest commen Subsequence(longest_common_subsequence.cpp) in current file because logic is same.  
*/

#include <bits/stdc++.h>
using namespace std;

#define LIMIT 1000		  //Max possible string length in most of the coding platforms. 	

int dp[LIMIT+1][LIMIT+1]; /*We have initialized DP array globaly */

int longestPalindromicSubsequence(string str1){
  /*
	-The longest commen Subsequence for given string and it's reverse string is longest Palindromic Subsequence.
	 
	 i.e, longestPalindromicSubsequence(string1)=longest_common_subsequence(string1,reverse of string1)
  */
    string str2=str1;
    
    reverse(str2.begin(),str2.end());
    
    int len=str1.length();
    
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    return dp[len][len];
}

int minimumNumberOfDeletions(string S) { 
    
    memset(dp,0,sizeof dp); 						//initialized dp array to 0   
    
    int maxLen= longestPalindromicSubsequence(S);	//length of longest Palindromic Subsequence for given string
    
    int minDeletions=S.length()-maxLen;				//minimum Number Of Deletions possible
    
    return minDeletions;
}

int main(){
        string S;
        cout<<"Enter String--";
        cin >> S;
        cout <<"\nMinimum no of Deletions to make a palindrome--"<<minimumNumberOfDeletions(S) << endl;
    
return 0;
}

/*
* A sample test case for this problem

TEST CASE:
    Input : aebcbda
    
    Output : 2
    
    Remove characters 'e' and 'd'
    Resultant string will be 'abcba' which is a palindromic string

* An example to demostrate the table view of the solution is
  str1 : aebcbda 
  str2 : adbcbea
	"" a d b c b e a  
  "" 0 0 0 0 0 0 0 0 
   a 0 1 1 1 1 1 1 1 
   e 0 1 1 1 1 1 2 2 
   b 0 1 1 2 2 2 2 2 
   c 0 1 1 2 3 3 3 3 
   b 0 1 1 2 3 4 4 4 
   d 0 1 2 2 3 4 4 4 
   a 0 1 2 2 3 4 4 5 
   
   Here, dp[7][7]=5(abcba) is length longest Palindromic Subsequence
   
  So, length of string - dp[7][7]  i.e 2 is the required answer 
  Input : krishna
  
  Output : 6
  
* Time Complexity: O(n*n)-- >n=length of string
* Space Complexity: O(n*n)
*/
