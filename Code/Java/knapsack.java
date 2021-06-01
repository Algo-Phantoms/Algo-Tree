/*
For each item you are given its weight and its value. You want to maximize the total value of all the 
items you are going to put in the knapsack such that the total weight of items is less than knapsack’s capacity. What is this maximum total value?


To consider all subsets of items, there can be two cases for every item:

	(1) the item is included in the optimal subset, 
	(2) not included in the optimal set. Therefore, the maximum value that can be obtained from n items is max of following two values.

Maximum value obtained by n-1 items and W weight (excluding nth item).
Value of nth item plus maximum value obtained by n-1 items and W minus weight of the nth item (including nth item).
If weight of nth item is greater than W, then the nth item cannot be included and case 1 is the only possibility.

Approach :
	 we can see that the dp solution with states (i,j) will depend on state (i-1, j) or (i-1, j-wt[i-1]). 
	 In either case the solution for state (i,j) will lie in the i-1th row of the memoization table. 
	 So at every iteration of the index, we can copy the values of current row and use only this row for building the 
	 solution in next iteration and no other row will be used. Hence, at any iteration we will be using only a single 
	 row to build the solution for current row. Hence, we can reduce the space complexity to just O(W).

*/

import java.util.Scanner;
public class Main
{
    public static int topdown(int[] price,int[] weigth,int n,int capacity,int[][] dp){

	if(n==0 || capacity==0){
		dp[n][capacity] = 0;
		return 0;
	}



	if(dp[n][capacity]!=-1){
		return dp[n][capacity];
	}

	int inc=0,exc=0;


	if(capacity>=weigth[n-1]){
					// include
		inc = price[n-1] + topdown(price,weigth,n-1,capacity-weigth[n-1],dp); 
	} 
				// exclude
	exc =  0 +  topdown(price,weigth,n-1,capacity,dp); 

				// take minimum 
	dp[n][capacity] = Math.max(inc,exc); 
	return Math.max(inc,exc);

}

public static int bottom_up(int[] price, int[] weight,int n, int capacity){

	int[][] dp = new int[100][100];

	for(int items = 0; items<=n;items++){
		for(int wei = 0; wei<=capacity;wei++){
			if(items==0 || wei == 0){ 
				dp[items][wei] = 0;
			}
			else{

				int inc = 0, exc = 0;
				if(wei >= weight[items-1]){
								// include
					inc = price[items-1] + dp[items-1][wei-weight[items-1]]; 

				}
							// exclude
				exc = 0 + dp[items-1][wei];  
							// take minimum
				dp[items][wei] = Math.max(inc, exc); 
			}
		}
	}

  return dp[n][capacity];
}
	public static void main(String[] args) {
		int[] price=new int[100];
	int[] weigth = new int[100];
	Scanner s=  new Scanner(System.in);
	int n;
	n=s.nextInt();
	for(int i=0; i<n; i++){
		price[i]=s.nextInt();
	}
	for(int i=0; i<n; i++){
		weigth[i]=s.nextInt();
	}

	int capacity;
	capacity= s.nextInt();

	int[][] dp = new int[100][100];
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			dp[i][j]=-1;
		}
	}
	
  System.out.println("Top Down - " + topdown(price,weigth,n,capacity,dp));
  System.out.println("Bottom up - " + bottom_up(price,weigth,n,capacity));


	}
}


/*
	Test Case : 
	Input : 4
	10 20 10 15
	2 2 3 1
	30

	Output : 
	Top down - 55
	Bottom up - 55

	Time Complexity: O(N*W)
	Space Complexity: O(W)

*/