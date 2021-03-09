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

n = int(input())
W = int(input())
weights = []
values = []
dp = []

for i in range(0,n):
    value = int(input())
    values.append(value)
    weight = int(input())
    weights.append(weight)

for i in range(0,n+1):
    x=[]
    for j in range(0, W+1):
        x.append(0)
    dp.append(x)
        

for i in range(1,n+1):
    for j in range(1,W+1):
        if(j<weights[i-1]):
            dp[i][j] = dp[i-1][j]
        else:
            if(dp[i-1][j]>=dp[i-1][j-weights[i-1]]+values[i-1]):
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j-weights[i-1]]+values[i-1]

print("The maximum value obtained is : ", dp[n][W])

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