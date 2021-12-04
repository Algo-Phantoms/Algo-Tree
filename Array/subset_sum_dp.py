# Ques: Check wheather it is possible or not to get subset sum equal to given sum in an array of size n
# Algorithm: DP
# language: Python


def subset_sum(arr, sum, n):  # this function takes set of integers array (arr) with its size (n) and an integer (sum)
    ss = ([[False for i in range(sum + 1)] for i in range(n + 1)])
    
    for i in range(n + 1): # when given sum is 0 then answer will be "yes" always, as every integer array has subset sum 0 indeed as 
        ss[i][0] = True  #row index indicates array size and column index indicates all possible subset sum so we are storing this info in our "ss" 2d array 
       
    for i in range(1, sum + 1):
        ss[0][i] = False

    for i in range(1, n + 1):
        for j in range(1, sum + 1):
            if j < arr[i - 1]:
                ss[i][j] = ss[i - 1][j]
            if j >= arr[i - 1]:
                ss[i][j] = (ss[i - 1][j] or ss[i - 1][j - arr[i - 1]])
    return ss[n][sum]       #dp[n][sum] stores the actual answer


if __name__ == "__main__":
    n = int(input("Enter number of elements you want: ")) #n-size of array (taking user input )
    arr = []
    arr = list(map(int, input('Enter elements of array: ').strip().split()))   #arr- elements in series 
    sum = int(input('Enter sum you want to check: '))       #we need to find result for this sum
    if subset_sum(arr, sum, n):
        print('Yes!')
    else:
        print('Sorry, No!')
       
