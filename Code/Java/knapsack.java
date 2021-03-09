/* We are given n items and for each item we have been given a corresponding weight and value. 
We need to pick certain items in such a way so as to maximize the total value of all the items such that the 
total weight of the items does not exceed the capacity of the knapsack.

For each items we have two options : 
    1) Case 1  - The item is included in the knapsack
    2) Case 2 - The item is not included in the knapsack

Hence we take the maximum of both the cases to obtain the optimal solution. 
We take the max of 
    1) not including the ith item i.e the optimal solution for i-1 items for a capacity of W 
    2) including the ith item i.e value of the ith item added to the optimal solution of i-1 items for a knapsack of size W-weights(i). 
    
*/

import java.util.*; 
public class Main
{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in); 
		int n = input.nextInt(); 
		int W = input.nextInt(); 
		int weights[] = new int[n]; 
		int values[] = new int[n]; 
		int dp[][] = new int[n+1][W+1]; 
		for(int i=0; i<n; i++)
		{
		    values[i] = input.nextInt();
		    weights[i] = input.nextInt(); 
		    
		}
		
		for(int i=0; i<n+1; i++)
        {
    	    dp[i][0] = 0;
        }   
        for(int i=0; i<W+1; i++)
        {
    	    dp[0][i] = 0;
        }
        
        for(int i=1; i<n+1; i++)
        {
        	for(int j=1; j<W+1; j++)
        	{
        		if(j<weights[i-1])
        		{
        			dp[i][j] = dp[i-1][j];
        		}
        		else
        		{
        			dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-weights[i-1]]+values[i-1]);
        		}
        	}
        }
        
        System.out.println("The maximum value obtained is : "+ dp[n][W]); 
    		
	}
}

/*
	Test Case : 
	1) Input :  6 15
                8 5
                5 6
                4 6
                6 6
                5 3
                2 9

	Output : 
	The maximum value obtained is : 19
	
	2) Input :  3 5
                6 1
                10 2
                12 3
        
	Output : 
	The maximum value obtained is : 22
	
	Time Complexity: O(N*W)
	Space Complexity: O(N*W)
*/