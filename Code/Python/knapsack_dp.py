"""
Ques: We have weights and values of n items, put these items in a knapsack(container) of capacity 'w' to get the maximum total value in the knapsack,
now find that possible maximum value we could make.
Language: Python 3

In knapsack function we have dp[][] table let’s consider all the possible weights from ‘1’ to ‘w’ as the columns and weights that can be kept as the rows.
The state dp[i][j] will denote maximum value of ‘j-weight’ considering all values from ‘1 to ith’. So for ‘wi’ (weight in ‘ith’ row) we can fill
it in all columns which have ‘weight values > wi’.
Now two possibilities can take place:
1.Fill ‘wi’ in the given column.
2.Do not fill ‘wi’ in the given column.
and we have to take maximum of these two possibilities, formally if we do not fill ‘ith’ weight in ‘jth’ column then dp[i][j] state will
be same as dp[i-1][j] but if we fill the weight, dp[i][j] will be equal to the value of ‘wi’+ value of the column weighing ‘j-wi’ in the
previous row. So we take the maximum of these two possibilities to fill the current state of dp table.

input:
Enter number of elements:      ---->(n)
Enter weight that knapsack can hold:            ------->(w)
Enter weight of each n space seperated elements:      ----->weight of each elements a[]
Enter value of each n space seperated elements:         ----->value each element hold val[]
output:
                            -----> Maximum possible value we could find from given set of weight and their values

"""
def knapsack(a, val, n, w):
    dp = [[0 for i in range(w + 1)] for i in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, w + 1):
            if j >= a[i - 1]:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + val[i - 1])
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][w]

if __name__ == "__main__":
    n = int(input('Enter number of elements: '))
    w = int(input('Enter weight that knapsack can hold: '))
    wgt = list(map(int, input('Enter weight of each n space seperated elements: ').split(' ')))[:n]
    val = list(map(int, input('Enter value of each n space seperated elements: ').split(' ')))[:n]
    print(knapsack(wgt, val, n, w))


#Time Complexity: O(n*w)          ----->where n is size of array and w is the maximum weight knapsack can hold
#Space Complexity: O(n*w)

"""
e.g -1)
Enter number of elements: 4
Enter weight that knapsack can hold: 10
Enter weight of each n space seperated elements: 2 1 3 4
Enter value of each n space seperated elements: 10 20 30 40
100

2)
Enter number of elements: 3
Enter weight that knapsack can hold: 50 
Enter weight of each n space seperated elements: 10 20 30
Enter value of each n space seperated elements: 50 100 150
250
"""
