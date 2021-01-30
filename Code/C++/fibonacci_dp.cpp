/*
In Fibonacci series, the current number is the sum of previous two numbers. 
One approach is bottom-up: these methods start with lower values of input and keep building the solutions for higher values.
The other approach is top-down. In this method, we preserve the recursive calls and use the
values if they are already computed.
*/

#include<iostream>
using namespace std;


int top_down(int n, int dp[]){
				// save
	if(n==0 || n==1){
		dp[n] = n;				
		return dp[n];
	}

				// check
	if(dp[n]!=-1){				
       return dp[n];
	}
   int ans = top_down(n-1, dp)+top_down(n-2,dp);
   dp[n] = ans;			
	
 return dp[n];

}

int bottom_up(int n){
	int dp[100];				

				// initialization with base case
	dp[0] = 0;				
	dp[1] = 1;

	for(int i=2;i<=n;i++){
					// recursive relation
		dp[i] = dp[i-1] + dp[i-2];				
	}

	return dp[n];
}
int main() {

    int n;
    int dp[100];

    cin >> n;
    			//initilize with -1 
    for(int i=0;i<100;i++){				
    	dp[i] = -1;
    }

    cout<<"Top down - "<<top_down(n, dp)<<"\n";
    cout<<"Bottom up - "<<bottom_up(n);

  return 0;
}

/* 
 Test Case : 

 Input : 4
 
 Output : 
 Top down - 3
 Bottom up - 3

 Time Complexity: O(n)
 Space Complexity: O(n)
*/