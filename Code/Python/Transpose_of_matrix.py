'''
PROBLEM STATEMENT:
Given a matrix with m rows and n columns. Print its transpose. Transpose of a
matrix is obtained by changing the rows to columns and columns to rows i.e., by
changing mat[i][j] to mat[j][i].
'''


# A function to print the transpose of the given matrix
def Transpose(mat, m, n):
    # Creating a matrix with n rows and m columns
    trans = [[0 for y in range(m)] for x in range(n)]
    for x in range(n):
        for y in range(m):
            trans[x][y] = mat[y][x]
    # Printing the transposed matrix
    print(trans)


# Driver Code
# User inputs the the dimension of matrix
m = int(input("Enter the no. of rows: "))
n = int(input("Enter the no. of columns: "))

# Creating a matrix with m rows and n columns
mat = [[0 for j in range(n)] for i in range(m)]
print("Enter elements of matrix:")
# User inputs matrix elemnents
for i in range(m):
    for j in range(n):
        num = int(input())
        mat[i][j] = num
# Printing the entered matrix
print("The entered matrix is:")
print(mat)
# A function call to transpose the matrix
print("The transpose of the entered matrix is:")
Transpose(mat, m, n)


'''
TEST CASES:
1.
Input:
Enter the no. of rows: 4
Enter the no. of columns: 3
Enter elements of matrix:
1
2
2
2
3
3
3
4
4
4
1
1
Output:
The entered matrix is:
[[1, 2, 2], [2, 3, 3], [3, 4, 4], [4, 1, 1]]
The transpose of the entered matrix is:
[[1, 2, 3, 4], [2, 3, 4, 1], [2, 3, 4, 1]]

2.
Input:
Enter the no. of rows: 2
Enter the no. of columns: 1
Enter elements of matrix:
8
10
Output:
The entered matrix is:
[[8], [10]]
The transpose of the entered matrix is:
[[8, 10]]

TIME COMPLEXITY: O(m*n), because we're traversing each and every elemnt of the
matrix of size mXn
SPACE COMPLEXITY: O(m*n), due to the transpose matrix created of size nXm
where 'm' and 'n' denotes the dimension of the matrix as entered by the user.
'''
