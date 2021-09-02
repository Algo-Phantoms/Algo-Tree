/*
Algorithm to find minimum characters to be inserted in beginning to make a string palindromic.

for example:-
string S = "BABC"
convert into S'="CBABC"(which is a palindrome)

                                    BABC
                                    / | \
                                   C BAB C => CBABC
     (No of strings to be added- 1)1  3  1

We can refer to the longest common Subsequence problem.
result:- minimum number of operations are 1.
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//function to count number of elements.
int CountingTheElements(string A) {
    if( A == "") return 0;
    int N = A.size();
    int array1[N];
    int array2[N];

    memset( array1 , 0 , sizeof array1 );
    memset(array2 , 0 , sizeof array2 );

    int left = 0 , right = -1 , k ;

    for( int i = 0 ; i < N ; i++ )
    {     k = i > right ? 1 : min( array1[ left + right - i ]  , right-i + 1 ) ;
          while( i-k >= 0 && i+k < N && A[i+k] == A[i-k] )k++;
          array1[i] = k--;

          if( i+k > right )
          {   right = i+k ;
              left = i-k ;
          }
    }

    left = 0 , right = -1 ;

    for( int i = 0 ; i < N ; i++ )
    {   if(i>right){
            k=0;}
        else{
           min( array2[left + right - i + 1 ] , right - i + 1 );
        }

         while( i - k - 1 >= 0 && i + k < N && A[i+k] == A[i-k-1] )k++;
         array2[i] = k--;
         if( i + k > right )
         {  right = i + k ;
            left = i - k - 1 ;
         }
    }

    int maxEle = 0 ;

    for( int i = 0 ; i < N ; i++ )
    {
        if( array1[i] == i+1 )
        { maxEle = max( maxEle , 2*array1[i] - 1 );
        }
        if( array2[i] == i )
        {
          maxEle = max( maxEle , 2*array2[i] );
        }
    }
return N - maxEle ;
}

int main() {
    string InputString;//this is the input string for which we need to find no. of operations
    cin>>InputString;//string that is taken as input
    cout<<"Enter the string:"<<endl;
    cout<<CountingTheElements(InputString)<<endl;
	return 0;
}

/*
Test Case 1
Input:DBABD
Output:0

test Case 2
Input:bcdf
Output:3

test Case 3
Input:CBCD
Output:1
*/
/*
Time Complexity:O(n)
Space Complexity:O(n)
*/

