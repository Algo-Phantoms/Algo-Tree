###################################################################
# LCS Algorithm

# Given two X=<x1,x2,....xn> and Y=<y1,y2,....,yn>, We have to find a common subsequence whose length is maximum.

# Subsequence need not be consecutive, but must be in order.

# Subsequence in sequence that appears in same relative order,but not neccessarily contiguous.

# More than 1 LCS can be present between two sequence , from those we have to find the subsequence of maximum length.

######################################################################

# Program Using Dynamic Programming Approach

X = input("Enter the first String -> ")
Y = input("Enter the second String -> ")
# Length of the two strings
m = len(X)
n = len(Y)
L = [[0 for i in range(n + 1)] for i in range(m + 1)]

# Algorithm for LCS
def lcs(X, Y):
    i = 0
    j = 0

    # Base Conditon For rows
    for i in range(1, m + 1):
        L[i][0] = 0
    # Base Conditon For columns
    for j in range(0, n + 1):
        L[0][j] = 0

    # Building L[m + 1][n + 1] in bottom up fashion
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                L[i][j] = L[i - 1][j - 1] + 1
            elif L[i - 1][j] >= L[i][j - 1]:
                L[i][j] = L[i - 1][j]
            else:
                L[i][j] = L[i][j - 1]


def lcs_display(X, Y):
    lcs(X, Y)

    # Length of LCS
    length = L[m][n]

    # Declaring a list of string to store the resultant LCS
    index = L[m][n]
    disp_lcs = [""] * (index + 1)
    disp_lcs[index] = ""

    i = m
    j = n

    # Getting a charcter one by one from the right bottom-up approach
    while i > 0 and j > 0:
        # If ith and jth charcter at the same position are same,then include the character
        if X[i - 1] == Y[j - 1]:
            disp_lcs[index - 1] = X[i - 1]
            i -= 1
            j -= 1
            index -= 1
        # If not equal then follow the path of the larger value
        elif L[i - 1][j] > L[i][j - 1]:
            i -= 1
        else:
            j -= 1

    # Display the LCS and its length
    print(
        f'Longest Common Subsequence of {X} and {Y} is {"".join(disp_lcs)} which is of length {length}'
    )


lcs_display(X, Y)

# Sample Input 1
# X="springtime" , Y="printing"

# Sample Output 1
# Longest Common Subsequence of springtime and printing is printi which is of length 6

# Sample Input
# X="abcdefghi" , Y= "ecdgi"

# Sample Output 2
# Longest Common Subsequence of abcdefghi and ecdgi is cdgi which is of length 4

# Time Complexity : O(m*n)
# Auxiliary Space : O(n)