# Title: Sudoku Solver
# Link: https://leetcode.com/problems/sudoku-solver/

board = [["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]

import collections
class Solution:
    def solveSudoku(self, board: list(list())) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def is_valid(r, c, n):
            if n in self.rows[r] or n in self.columns[c] or n in self.sub_boxes[(r//3,c//3)]:
                return False
            return True

        def place_num(r, c, n):
            self.rows[r].add(n)
            self.columns[c].add(n)
            self.sub_boxes[(r//3,c//3)].add(n)
            board[r][c] = n

        def remove_num(r, c, n):
            self.rows[r].remove(n)
            self.columns[c].remove(n)
            self.sub_boxes[(r//3,c//3)].remove(n)
            board[r][c] = "."

        def backtrack(emp_key, emp_indice):
            row = emp_key
            col = self.emp[emp_key][emp_indice]
            # based on the dict self.emp key value and the indice value, we retrieve the column value.
            resolved = False
            for num in range(1, 10):
                # iterate through numbers 1-9 at the current cell.
                if is_valid(row, col, str(num)):
                    # examining if the num meets the rules 
                    place_num(row, col, str(num))
                    # fill the cell in the 2-D array and update the tracking dicts
                    if row + 1 == 9 and emp_indice + 1 == len(self.emp[emp_key]):
                        # we reach the bottom row and the last column elememt in the list, i.e. we find a solution!
                        resolved = True
                        return resolved
                    elif emp_indice + 1 < len(self.emp[emp_key]):
                        # we move on to the next column in the same row
                        resolved = backtrack(emp_key, emp_indice+1)
                    elif emp_indice + 1 == len(self.emp[emp_key]):
                        # we move on to the next row with the first empty cell
                        resolved = backtrack(emp_key+1, 0)
                    if not resolved:
                        # backtrack, i.e. remove the num from the 2-D array and from the tracking dicts
                        remove_num(row, col, str(num))
                    else:
                        break
            return resolved
        
        self.rows = collections.defaultdict(set)
        # using dict self.rows to track the digits in each row
        self.columns = collections.defaultdict(set)
        # using dict self.columns to track the digits in each column
        self.sub_boxes = collections.defaultdict(set)
        # using dict self.sub_boxes to track the digits in each 3x3 sub-box
        self.emp = collections.defaultdict(list)
        # using dict self.emp to track the empty cells in the 2-D array
        # Note that for dict self.emp, the key is the 2-D array row number, and the value is the 2-D array column numbers.
        # E.g., 0:[2, 3, 5, 6, 7, 8] --> row number is 0, column numbers are 2, 3, 5, 6, 7, and 8
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    self.rows[i].add(board[i][j])
                    self.columns[j].add(board[i][j])
                    self.sub_boxes[(i//3,j//3)].add(board[i][j])
                else:
                    self.emp[i].append(j)
        # we work on dict self.emp, pass in the first row number 0, and the first indice value of the dict value list
        # which includes the column number values.
        backtrack(0, 0)

solution = Solution()
solution.solveSudoku(board)
