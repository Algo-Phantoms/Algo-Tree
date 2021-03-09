''' 
          N Queens Problem using Backtracking
    N Queens Problem is a puzzle, where n queens should be placed in an n x n chessboard, such that no two queens attack each other.
    The below code provides a solution to this puzzle using Backtracking in Python.
    
    Input: Number of queens to be placed - 'n'
    Output: The coordinates (x, y) in the chessboard where the queens can be placed.
 '''

def initialize(n):
    # initializes the created board with some initial values for each coordinates.
    # creates a dictionary called board with 5 types of keys: 'queen' ,'row', 'col' - represented explicitly
    # 'nwtose' - coordinates in NorthWest to Southeast direction - represents the Main diagonal.
    # 'swtone' - coordinates in Southwest to Northeast direction - represents the opposite diagonal.
    for key in ['queen','row','col','nwtose','swtone']:
        board[key] = {}
    for i in range(n):
        board['queen'][i] = -1
        board['row'][i] = 0
        board['col'][i] = 0
    for i in range((1 - n), n):
        board['nwtose'][i] = 0
    for i in range(2 * n - 1):
        board['swtone'][i] = 0

def printboard():
    # A function to print the coordinates in the chessboard where the queens can be placed.
    # prints the row and its corresponding value (key, value) from the dictionary, board['queen'].
    for row in sorted(board['queen'].keys()):
        print((row, board['queen'][row]))

def free(i, j):
    # checks if the particular coordinate is free or occupied. 
    # Returns True if (i, j) is free, else returns False.
    return((board['row'][i] == 0) and (board['col'][j] == 0) and (board['nwtose'][j - i] == 0) and (board['swtone'][j + i] == 0))

def addqueen(i, j):
    # Assigns position to a queen in the coordinate (i, j). 
    board['queen'][i] = j
    board['row'][i] = 1
    board['col'][j] = 1
    board['nwtose'][j - i] = 1
    board['swtone'][j + i] = 1

def undoqueen(i, j):
    # Removes queen from the position (i, j) by updating the value as -1.
    board['queen'][i] = -1
    board['row'][i] = 0
    board['col'][j] = 0
    board['nwtose'][j-i] = 0
    board['swtone'][j+i] = 0

def placequeen(i):
    # The main backtracking process happens here.
    # This function places each queen 'i' in an optimum coordinate in the chessboard.
    # If a particular position (i, j) is free in the chessboard, it is occupied by the queen using the addqueen() function.
    # This is done until the 'n-1'th queen is placed on the chessboard.
    # If it is not possible, it returns False.
    n = len(board['queen'].keys())
    for j in range(n):
        if free(i,j):
            addqueen(i,j)
            if i == n-1:
                return(True)
            else:
              extendsoln = placequeen(i+1)
            if extendsoln:
              return(True)
            else:
              undoqueen(i,j)
    else:
        return(False)

# start of the main function.
# The execution starts from here.
board = {}
n = int(input("How many queens? "))
initialize(n)
if placequeen(0):
    printboard()

'''
Sample Input #1:
    How many queens? 4
Sample Output #1:
    (0, 1)
    (1, 3)
    (2, 0)
    (3, 2)

Sample Input #2: 
    How many queens? 8
Sample Output #2:
    (0, 0)
    (1, 4)
    (2, 7)
    (3, 5)
    (4, 2)
    (5, 6)
    (6, 1)
    (7, 3)

Time Complexity: O(n*n)
Space Complexity: O(n)

Solution by Nithiyashree M G (github.com/mgncodes)
'''
