'''
Longest repeating subsequence is finding 2 subsequences of a string such that ith character in both the strings doesn't come from the same index in the given string.
Problem Statement: Given a string find the length of the longest possible substring.
Solution: Using the solution of Longest Common subsequence Problem, here we add a addition condition, as we compare same strings.
Conditions are when i!=j and string[i]==string[j] then dp[i][j] = 1+dp[i-1][j-1] (1+max length encountered till i-1,j-1)
Else : dp[i][j] = max(dp[i-1][j],dp[i][j-1])
'''


def lrs(string, dp):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            # Conditions as mentioned above
            if i != j and string[i - 1] == string[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[n][n]


print("Enter the string: ")
string = input()
n = len(string)

# initializing a dp with length (n+1)*(n+1)
dp = [[-1 for i in range(n + 2)] for j in range(n + 2)]
for i in range(n + 1):
    dp[0][i] = 0  # As there will be no matching with 0 length string
    dp[i][0] = 0  # same as above

length = lrs(string, dp)

print("Length of the longest repeating subsequence is " + str(length))
'''
Time Complexity : O(n*n) where n is the length of the given string.
Space Complexity : O(n*n) where n is the length of the given string for dp storing.

Sample Input 1:
Enter the string:
bbc
Sample Output 1:
Length of the longest repeating subsequence is 1
Explanation : b,b we cannot consider c as it we be in same index in both subsequences.
Sample Input 2:
Enter the string:
bbcc
Sample Output 2:
Length of the longest repeating subsequence is 2
Explanation : bc(pos 1,3) ,bc (pos 2,4)
Sample Input 3:
Enter the string:
abcadbacdbofpp
Sample Output 3:
Length of the longest repeating subsequence is 6
Explanation : abadbp (pos 1,2,4,5,6,13) , abadbp (pos 4,6,7,9,10,14). No two positions are sames

'''
