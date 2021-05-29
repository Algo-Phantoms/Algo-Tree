'''
        N queen problem is  a backtracking problem in which we place
        N queens(no of queens is specified by the user) on the N x N chessboard so that they do not attack each other
        A queen can move: Horizontally, diagonally or vertically.

        Backtracking Approach:
        1. We will place the queen column by column
        2. Base case- if all the queens have been placed, i.e. col==n, then print the solution and backtrack for other solutions
        3. For placing a queen in the given column, try it for every row,
            if it is safe to place the queen at particular row and column, then mark chessboard[row][col]=1.
            explore with the choice of the queen placed in row and column
            if placing a queen isn't possible further then unmark this row, column , ie, chessboad[row][col]=0
        4. If queen can't be placed at all rows of the given column, then return false to backtrack.
        
'''

# Checking if the position of the queen is safe and is not been attacked
# horizontally, vertically and diagonally.
# Checking the queen for the attacks from left side only
# because 0 to col-1 queens have been placed on the left
def isSafe(chessboard, row, col):
    # checking the row on the left
    for i in range(col):
        if chessboard[row][i]:
            return False
    # checking the lower diagonal on right side of the queen
    i=row
    j=col
    while i<n and j>=0:
        if chessboard[i][j]:
            return False
        i+=1
        j-=1
    # checking the upper diagonal on left side of the queen
    i=row
    j=col
    while i>=0 and j>=0:
        if chessboard[i][j]:
            return False
        i-=1
        j-=1
    return True

# printing the n queen chessboard
def printSol(chessboard):
    for i in range(n):
        for j in range(n):
            # queen is present
            if chessboard[i][j]==1: 
                print("Q",end=" ")
            # queen is absent at this cell so print *
            else:
                print("*", end=" ")
        print()
    print()
    print()
    return

# function for the backtracking approach for n queens problem
def recursiveBacktracking(chessboard, col):
    # when all queens are placed
    # base case
    if col==n:
        # print the n queens chessboard
        printSol(chessboard)
        # return false to print all possible solutions
        return False

    res=False
    for i in range(n):
        # backtrack when placing the queen at row i and column col is safe
        if isSafe(chessboard,i,col):
            # make a choice
            # place the queen here
            chessboard[i][col]=1
            # explore with the choice
            res=recursiveBacktracking(chessboard, col+1)
            # undo choice
            chessboard[i][col]=0
    # return false when queen could not be placed in any row of this column
    return res


if __name__=='__main__':
    n=int(input())
    # initialising the chessboard
    chessboard=[[0 for i in range(n)] for j in range(n)]
    # calling the backtracking function
    recursiveBacktracking(chessboard,0)

'''
TEST CASE 1:
Input: 4
Output:
* * Q * 
Q * * * 
* * * Q 
* Q * * 


* Q * * 
* * * Q 
Q * * * 
* * Q * 


TEST CASE 2:
Input: 5
Output:
Q * * * * 
* * * Q * 
* Q * * * 
* * * * Q 
* * Q * * 


Q * * * * 
* * Q * * 
* * * * Q 
* Q * * * 
* * * Q * 


* * Q * * 
Q * * * * 
* * * Q * 
* Q * * * 
* * * * Q 


* * * Q * 
Q * * * * 
* * Q * * 
* * * * Q 
* Q * * * 


* Q * * * 
* * * Q * 
Q * * * * 
* * Q * * 
* * * * Q 


* * * * Q 
* * Q * * 
Q * * * * 
* * * Q * 
* Q * * * 


* Q * * * 
* * * * Q 
* * Q * * 
Q * * * * 
* * * Q * 


* * * * Q 
* Q * * * 
* * * Q * 
Q * * * * 
* * Q * * 


* * * Q * 
* Q * * * 
* * * * Q 
* * Q * * 
Q * * * * 


* * Q * * 
* * * * Q 
* Q * * * 
* * * Q * 
Q * * * * 

Time Complexity: O(N!), where N is the input given by user, for placing N queens on N X N chessboard.
Space complexity: O(N^2), for storing the N X N chessboard.
'''
