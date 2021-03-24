"""
A dynamic programming based Python program print shortest supersequence of two strings.
"""
# Function to return an SCS of substrings `X[0…m-1]`, `Y[0…n-1]`
def SCS(X, Y, m, n, T):
 
    # if the end of the first string is reached,
    # return the second string
    if m == 0:
        return Y[:n]
 
    # if the end of the second string is reached,
    # return the first string
    if n == 0:
        return X[:m]
 
    # if the last character of `X` and `Y` matches, include it in SSC
    # and recur to find SCS of substring `X[0…m-2]` and `Y[0…n-1]`
    if X[m - 1] == Y[n - 1]:
        return SCS(X, Y, m - 1, n - 1, T) + X[m - 1]
    else:
        # if the last character of `X` and `Y` don't match
 
        # if the top cell of a current cell has less value than the left
        # cell, then include the current character of string `X` in SCS
        # and find SCS of substring `X[0…m-2]` and `Y[0…n-2]`
 
        if T[m - 1][n] < T[m][n - 1]:
            return SCS(X, Y, m - 1, n, T) + X[m - 1]
 
        # if the left cell of a current cell has less value than the top
        # cell, then include the current character of string `Y` in SCS
        # and find SCS of substring `X[0…m-1]` and `Y[0…n-2]`
        else:
            return SCS(X, Y, m, n - 1, T) + Y[n - 1]
 
 
# Function to fill the lookup table by finding the length of SCS of
# sequences `X[0…m-1]` and `Y[0…n-1]`
def SCSLength(X, Y, m, n, T):
 
    # initialize the first column of the lookup table
    for i in range(m + 1):
        T[i][0] = i
 
    # initialize the first row of the lookup table
    for j in range(n + 1):
        T[0][j] = j
 
    # fill the lookup table in a bottom-up manner
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            # if the current character of `X` and `Y` matches
            if X[i - 1] == Y[j - 1]:
                T[i][j] = T[i - 1][j - 1] + 1
            # otherwise, if the current character of `X` and `Y` don't match
            else:
                T[i][j] = min(T[i - 1][j] + 1, T[i][j - 1] + 1)
 
 
if __name__ == '__main__':
 
    X = input("Enter String 1 : ")
    print(X)
    Y = input("Enter String 2 : ")
    print(Y)
    
    m = len(X)
    n = len(Y)
 
    # lookup table stores solution to already computed subproblems
    # `T[i][j]` stores the length of SCS of substring `X[0…i-1]` and `Y[0…j-1]`
    T = [[0 for x in range(n + 1)] for y in range(m + 1)]
 
    # fill the lookup table in a bottom-up manner
    SCSLength(X, Y, m, n, T)
 
    # find the shortest common supersequence by reading the lookup
    # table in a top-down manner
    print(f"The shortest common supersequence of {X} and {Y} is", SCS(X, Y, m, n, T))


""" INPUT AND OUTPUT
 Enter string 1 : AGGTAB
 AGGTAB
 Enter string 2 : GXTXAYB
 GXTXAYB
 The shortest common supersequence of AGGTAB and GXTXAYB is AGGXTXAYB
 Enter String 1 : LUCK
 LUCK
 Enter String 2 : CYK
 CYK
 The shortest common supersequence of LUCK and CYK is LUCYK
TIME AND SPACE COMPLEXITY
 Time Complexity: O(nm)
 Space Complexity : O(nm)
"""
