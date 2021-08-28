#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lis(int* input, int n) {
	int* dp = new int[n];
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (input[j] > input[i]) {
				continue;
			}
			int possibleAns = dp[j] + 1;
			if (possibleAns > dp[i]) {
				dp[i] = possibleAns;
			}
		}
	}
	int best = 0;
	for (int i = 0; i < n; i++) {
		if (best < dp[i]) {
			best = dp[i];
		}
	}
	delete [] dp;
	return best;
}

int main() {
	int n;
	cin >> n;
	int * input = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	int ans = lis(input, n);
	cout << ans << endl;
	delete [] input;
}

   
//    n=5
//    input=[50,3,10,20,30]
//    ans=4(3,10,20,30)

//    test case:
//    sample input:
//    6
//    50 3 10 7 40 80
//    Sample output:
//    4

//    Explanation:
//    {3,7,40,80}
//    dp=[1,1,2,2,3,4]
//    As first niumber is 50 so increasing number is only 1 so:
//    dp[0]=1,then after that the number is 3 which is not increasing so 
//    dp[1]=1,then 10 is greater than 3 so ,
//    dp[2]=(1+1=2),now then 7 is lesser than 10 so:
//    dp[3]=dp[2]as (dp[2]>1) ,now next no is 40 which is greater than 7 so:
//    dp[4]=dp[3]+1=3,so now the last number is 80 which is greater than 40 so:
//    dp[5]=dp[4]+1=4,so the greatest value is 4 ,
//    and the answer is 4.

// Time Complexity:O(N^2)
// Space Complexity:O(N)