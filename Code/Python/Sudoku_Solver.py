# Title: Sudoku Solver
# Program to solve a Sudoku puzzle by filling the empty cells.A sudoku solution must satisfy all of the following rules:

# Each of the digits 1-9 must occur exactly once in each row.
# Each of the digits 1-9 must occur exactly once in each column.
# Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
# The '0' character indicates empty cells.

def solve(bo):
    """The algorith that's gonna backtrack"""
    find = find_empty(bo)
    
    if not find:
        return True
    else:
        row, col = find
    
    for i in range(1, 10):
        if is_valid(bo, i, (row, col)):
            bo[row][col] = i

            if solve(bo):
                return True
            
            bo[row][col] = 0
        
    return False



def is_valid(bo, num, pos):
    """Returns bollean expresion whether inserting some number
    in an empty space is valid or not"""

    #Check whether the number is already in the current row
    for i in range(len(bo[0])):
        if bo[pos[0]][i] == num and pos[1] != i:
            return False
    #Check whether the number is already in the current column 
    for i in range(len(bo)):
        if bo[i][pos[1]] == num and pos[0] != i:
            return False
    #Check whether the number is already in the current box
    box_X_coo = pos[1] // 3 #Will be an integer from 0-2
    box_Y_coo = pos[0] // 3

    for i in range(box_Y_coo * 3, box_Y_coo * 3 + 3):
        for j in range(box_X_coo * 3, box_X_coo * 3 + 3):
            if bo[i][j] == num and (i, j) != pos:
                return False
    return True

def print_board(bo):
    for i in range(len(bo)):
        if i % 3 == 0 and i != 0:
            print('- - - - - - - - - -')
        
        for j in range(len(bo[0])):
            if j % 3 == 0 and j != 0:
                print('|', end = "")
            
            if j == 8:
                print(str(bo[i][j])) #When it prints the 9th element of a row, inserts a \n
            else:                    #Otherwhise, remains in the same line
                print(str(bo[i][j]) + " ", end = "")
            
def find_empty(bo):
    """Returns a tuple (row, col) with the coordinates of an 
    empty space on the board"""

    for i in range(len(bo)):
        for j in range(len(bo[0])):
            if bo[i][j] == 0:
                return (i, j)
    return None


solve(board)
print_board(board)

#Test Cases
      
# 1st Case
# board = [
#     [7,8,0,4,0,0,1,2,0],
#     [6,0,0,0,7,5,0,0,9],
#     [0,0,0,6,0,1,0,7,8],
#     [0,0,7,0,4,0,2,6,0],
#     [0,0,1,0,5,0,9,3,0],
#     [9,0,4,0,6,0,0,0,5],
#     [0,7,0,3,0,0,0,1,2],
#     [1,2,0,0,0,7,4,0,0],
#     [0,4,9,2,0,6,0,0,7]
# ]

# Output:
# 7 8 5 |4 3 9 |1 2 6
# 6 1 2 |8 7 5 |3 4 9
# 4 9 3 |6 2 1 |5 7 8
# - - - - - - - - - -
# 8 5 7 |9 4 3 |2 6 1
# 2 6 1 |7 5 8 |9 3 4
# 9 3 4 |1 6 2 |7 8 5
# - - - - - - - - - -
# 5 7 8 |3 9 4 |6 1 2
# 1 2 6 |5 8 7 |4 9 3
# 3 4 9 |2 1 6 |8 5 7
      
      
#2nd case
   
# board =[[5, 3, 0, 0, 7, 0, 0, 0, 0],
# [6, 0, 0, 1, 9, 5, 0, 0, 0],
# [0, 9, 8, 0, 0, 0, 0, 6, 0],
# [8, 0, 0, 0, 6, 0, 0, 0, 3],
# [4, 0, 0, 8, 0, 3, 0, 0, 1],
# [7, 0, 0, 0, 2, 0, 0, 0, 6],
# [0, 6, 0, 0, 0, 0, 2, 8, 0],
# [0, 0, 0, 0, 1, 9, 0, 0, 5],
# [0, 0, 0, 0, 0, 0, 0, 0, 0]]


# Output:
# 5 3 4 |6 7 8 |1 9 2
# 6 7 2 |1 9 5 |3 4 8
# 1 9 8 |3 4 2 |5 6 7
# - - - - - - - - - -
# 8 5 9 |7 6 1 |4 2 3
# 4 2 6 |8 5 3 |9 7 1
# 7 1 3 |9 2 4 |8 5 6
# - - - - - - - - - -
# 9 6 1 |5 3 7 |2 8 4
# 2 8 7 |4 1 9 |6 3 5
# 3 4 5 |2 8 6 |7 1 9


#Time complexity: O(9^(n*n))
# Space Complexity: O(n*n)

