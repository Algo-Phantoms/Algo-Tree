/* 
 Problem description:

 Given two strings, find the length of longest common
 substring between them (Substring is a contiguous sequence
 of characters within a string).


                           APPROACH
-------------------------------------------------------------------  
We will use Dynamic Programming approach to solve this problem.
Firstly, We will fill our dp matrix in such a way, that for any i,j
dp[i][j] stores the length of longest common substring, considering
first 'i' characters of the first string and first 'j' characters 
of second string. Then we will return the maximum value stored in 
the matrix after traversing the whole dp matrix.
  
*/

#include<bits/stdc++.h>
using namespace std;

//Function which evaluates the length of longest common substring 
//between two strings.
int LongestCommonSubstr(string x, string y, int x_len, int y_len ){
    
    
    //Checking if length of any of the strings is 0.
    if(x_len==0 || y_len==0){
        return 0;
    }

    //Declaring dp matrix
    int dp[x_len + 1][y_len + 1]; 

    //Initialising dp matrix with 0
    memset(dp, 0, sizeof(dp));
    /*
      Filling DP matrix int dp[][], where dp[i][j] stores the length of longest common substring,
      considering first 'i' characters of the first string and first 'j' characters of second string.

    */
    for(int i=1; i<=x_len; i++){
        for(int j=1; j<=y_len; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
          
        }
    }
    /*
      Traversing the dp matrix and returning the maximum value stored, which represents the length
      of longest common substring between given strings.
     */
    int max_len=INT_MIN;
    for(int i=0; i<=x_len; i++){
        for(int j=0; j<=y_len; j++){
            max_len=max(max_len, dp[i][j]);
               
        }
    }
    return max_len;

}



int main(){
    string A, B;
    cin >> A;
    cin >> B;
    int A_len= A.size(), B_len=B.size();
    
    cout << LongestCommonSubstr(A, B, A_len, B_len); 
      
    return 0;
}


/*
Sample Test Cases:

Input: 
agchgvskudh
afchgvksudh
Output:
4

Input:
abcdef
zxywpqg
Output:
0

Time Complexity: O(len_1*len_2)
Auxiliary Space: O(len_1*len_2)
where,
len_1 = length of first string,
len_2 = length of second string

*/
