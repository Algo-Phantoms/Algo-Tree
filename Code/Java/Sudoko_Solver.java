/*
We need to write a program to solve a Sudoku puzzle by filling the cells which are having 0.
A sudoku solution must satisfy all of the following rules:
->Each of the digits 1-9 must occur exactly once in each row.
->Each of the digits 1-9 must occur exactly once in each column.
->Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '0' character indicates empty cells.

We will iterate over entire matrix row by row.When we encounter non zero element,we will just move to another one.When we encounter zero 
we will place number from 1 to 9 after calling isValid() function and move to next block. At any point if we feel that we have taken wrong step 
we will backtrack to previous step and change the value then again move forward.
*/

import java.util.*;

public class Main {
  //Function to display the board when it is filled
  public static void display(int[][] board){
    for(int i = 0; i < board.length; i++){
      for(int j = 0; j < board[0].length; j++){
        System.out.print(board[i][j] + " ");
      }
      System.out.println();
    }

  }

  public static void solveSudoku(int[][] board, int i, int j) {
    if (i == board.length){
      display(board);
        return;
    }

    int ni = 0;
    int nj = 0;

    //Storing next block to be checked
    if(j == board[0].length - 1){
      ni = i + 1;
      nj = 0;
    } else {
      ni = i;
      nj = j + 1;
    }

    if(board[i][j] != 0){
      solveSudoku(board, ni, nj,solve);
    } else {
      for(int val = 1; val <= 9; val++){
        if(isValid(board, i, j, val)){
          board[i][j] = val;
          solveSudoku(board, ni, nj,solve);
          if(solve==1)break;
          board[i][j] = 0;
        }
      }
    }
  }

  //To check whether current entry is valid or not
  public static boolean isValid(int[][] board, int x, int y, int val) {
    int n = board.length;

    //To check for Column
    for (int i = 0; i < n; i++) {
      if (board[x][i] == val) {
        return false;
      }
    }
    //To check for row
    for (int i = 0; i < n; i++) {
      if (board[i][y] == val) {
        return false;
      }
    }

    //To check in 3x3 respective block
    x = x / 3 * 3;
    y = y / 3 * 3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[x + i][y + j] == val) {
          return false;
        }
      }
    }

    return true;
  }

  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int[][] arr = new int[9][9];
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        arr[i][j] = scn.nextInt();
      }
    }
    
    solveSudoku(arr, 0, 0, 0);
  }
}

/*
Test Cases:
      
1st Case
board = [
    [7,8,0,4,0,0,1,2,0],
    [6,0,0,0,7,5,0,0,9],
    [0,0,0,6,0,1,0,7,8],
    [0,0,7,0,4,0,2,6,0],
    [0,0,1,0,5,0,9,3,0],
    [9,0,4,0,6,0,0,0,5],
    [0,7,0,3,0,0,0,1,2],
    [1,2,0,0,0,7,4,0,0],
    [0,4,9,2,0,6,0,0,7]
]

Output:
7 8 5 |4 3 9 |1 2 6
6 1 2 |8 7 5 |3 4 9
4 9 3 |6 2 1 |5 7 8
- - - - - - - - - -
8 5 7 |9 4 3 |2 6 1
2 6 1 |7 5 8 |9 3 4
9 3 4 |1 6 2 |7 8 5
- - - - - - - - - -
5 7 8 |3 9 4 |6 1 2
1 2 6 |5 8 7 |4 9 3
3 4 9 |2 1 6 |8 5 7
      
      
2nd case
board =[
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 0, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 0, 0, 0, 0, 0]
]


Output:
5 3 4 |6 7 8 |1 9 2
6 7 2 |1 9 5 |3 4 8
1 9 8 |3 4 2 |5 6 7
- - - - - - - - - -
8 5 9 |7 6 1 |4 2 3
4 2 6 |8 5 3 |9 7 1
7 1 3 |9 2 4 |8 5 6
- - - - - - - - - -
9 6 1 |5 3 7 |2 8 4
2 8 7 |4 1 9 |6 3 5
3 4 5 |2 8 6 |7 1 9


Time complexity: O(9^(n*n))
Space Complexity: O(n*n)
*/