/*
Problem Statement:
Given a N*N board with the Knight placed on the given row and column, as a starting point for a knight piece. Moving according to the rules of chess knight must visit 
each square exactly once. Print the order of each the cell in which they are visited.
When moving from (r, c) to the possible 8 options give first precedence to (r - 2, c + 1) and move in clockwise manner to explore other options.
*/


import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        
        Scanner scn = new Scanner (System.in);
        int n = scn.nextInt();                         // size of chess board
        int[][] chess = new int[n][n];
        int row = scn.nextInt();                      // starting row
        int col = scn.nextInt();                      // starting column
        printKnightsTour(chess,row,col,1);            // calling function
        
    }

    public static void printKnightsTour(int[][] chess, int row,int col,int count ) {
       
       if(row < 0 || row >= chess.length || col < 0 || col >= chess.length || chess[row][col] != 0)  // check for invalid moves i.e if box is already visited, or for non exixting points
        {
            return; 
        } 
        
        
        if(count == (chess.length*chess.length))       // if all boxes of chess board visited
        {
            chess[row][col] = count;                  // put the count value in the box
            displayBoard(chess);                    // print the result
            chess[row][col] = 0;                      // undo the changes made in box so that next solution can be generated
            return;
        }
        
        
        chess[row][col] = count;                     // if no base cases applies then put the count value in the currrent block
       
        
       printKnightsTour(chess, row - 2, col + 1, count + 1); // solution is searching clock wise all these functions are calling row and columns accordingly
       printKnightsTour(chess, row - 1, col + 2, count + 1); // by using backtracking function will print all possible solutions in which knight will be able to cover whole board
       printKnightsTour(chess, row + 1, col + 2, count + 1);
       printKnightsTour(chess, row + 2, col + 1, count + 1);
       printKnightsTour(chess, row + 2, col - 1, count + 1);
       printKnightsTour(chess, row + 1, col - 2, count + 1);
       printKnightsTour(chess, row - 1, col - 2, count + 1);
       printKnightsTour(chess, row - 2, col - 1, count + 1);
       
       chess[row][col] = 0;                            // undo the changes made in box so that next solution can be generated
        
        
        
    }

    public static void displayBoard(int[][] chess){
        for(int i = 0; i < chess.length; i++){
            for(int j = 0; j < chess[0].length; j++){
                System.out.print(chess[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println();
    }
}

/*
Test Case 1 : 
input : 5
        2
        0
output : 
25 2 13 8 23 
12 7 24 3 14 
1 18 15 22 9 
6 11 20 17 4 
19 16 5 10 21 

19 2 13 8 21 
12 7 20 3 14 
1 18 15 22 9 
6 11 24 17 4 
25 16 5 10 23 

25 2 13 8 19 
12 7 18 3 14 
1 24 15 20 9 
6 11 22 17 4 
23 16 5 10 21 

19 2 13 8 25 
12 7 18 3 14 
1 20 15 24 9 
6 11 22 17 4 
21 16 5 10 23 

21 2 17 8 19 
12 7 20 3 16 
1 22 13 18 9 
6 11 24 15 4 
23 14 5 10 25 

23 2 17 8 25 
12 7 24 3 16 
1 22 13 18 9 
6 11 20 15 4 
21 14 5 10 19 

25 2 17 8 23 
12 7 24 3 16 
1 18 13 22 9 
6 11 20 15 4 
19 14 5 10 21 

19 2 17 8 21 
12 7 20 3 16 
1 18 13 22 9 
6 11 24 15 4 
25 14 5 10 23 

25 2 15 8 19 
16 7 18 3 14 
1 24 11 20 9 
6 17 22 13 4 
23 12 5 10 21 

19 2 15 8 25 
16 7 18 3 14 
1 20 11 24 9 
6 17 22 13 4 
21 12 5 10 23 

21 2 15 8 19 
16 7 20 3 14 
1 22 11 18 9 
6 17 24 13 4 
23 12 5 10 25 

23 2 15 8 25 
16 7 24 3 14 
1 22 11 18 9 
6 17 20 13 4 
21 12 5 10 19 

23 2 13 8 21 
14 7 22 3 12 
1 24 9 20 17 
6 15 18 11 4 
25 10 5 16 19 

21 2 13 8 23 
14 7 22 3 12 
1 20 9 24 17 
6 15 18 11 4 
19 10 5 16 25 

25 2 13 8 19 
14 7 18 3 12 
1 24 9 20 17 
6 15 22 11 4 
23 10 5 16 21 

19 2 13 8 25 
14 7 18 3 12 
1 20 9 24 17 
6 15 22 11 4 
21 10 5 16 23 

21 2 11 16 19 
12 17 20 3 10 
1 22 7 18 15 
6 13 24 9 4 
23 8 5 14 25 

23 2 11 16 25 
12 17 24 3 10 
1 22 7 18 15 
6 13 20 9 4 
21 8 5 14 19 

23 2 11 16 21 
12 17 22 3 10 
1 24 7 20 15 
6 13 18 9 4 
25 8 5 14 19 

21 2 11 16 23 
12 17 22 3 10 
1 20 7 24 15 
6 13 18 9 4 
19 8 5 14 25 

21 2 9 14 19 
10 15 20 3 8 
1 22 5 18 13 
16 11 24 7 4 
23 6 17 12 25 

23 2 9 14 25 
10 15 24 3 8 
1 22 5 18 13 
16 11 20 7 4 
21 6 17 12 19 

25 2 9 14 23 
10 15 24 3 8 
1 18 5 22 13 
16 11 20 7 4 
19 6 17 12 21 

19 2 9 14 21 
10 15 20 3 8 
1 18 5 22 13 
16 11 24 7 4 
25 6 17 12 23 

23 2 7 12 21 
8 13 22 17 6 
1 24 3 20 11 
14 9 18 5 16 
25 4 15 10 19 

21 2 7 12 23 
8 13 22 17 6 
1 20 3 24 11 
14 9 18 5 16 
19 4 15 10 25 

25 2 7 12 23 
8 13 24 17 6 
1 18 3 22 11 
14 9 20 5 16 
19 4 15 10 21 

19 2 7 12 21 
8 13 20 17 6 
1 18 3 22 11 
14 9 24 5 16 
25 4 15 10 23 

25 4 15 10 23 
14 9 24 5 16 
1 18 3 22 11 
8 13 20 17 6 
19 2 7 12 21 

19 4 15 10 21 
14 9 20 5 16 
1 18 3 22 11 
8 13 24 17 6 
25 2 7 12 23 

25 4 15 10 19 
14 9 18 5 16 
1 24 3 20 11 
8 13 22 17 6 
23 2 7 12 21 

19 4 15 10 25 
14 9 18 5 16 
1 20 3 24 11 
8 13 22 17 6 
21 2 7 12 23 

21 6 17 12 19 
16 11 20 7 4 
1 22 5 18 13 
10 15 24 3 8 
23 2 9 14 25 

23 6 17 12 25 
16 11 24 7 4 
1 22 5 18 13 
10 15 20 3 8 
21 2 9 14 19 

25 6 17 12 23 
16 11 24 7 4 
1 18 5 22 13 
10 15 20 3 8 
19 2 9 14 21 

19 6 17 12 21 
16 11 20 7 4 
1 18 5 22 13 
10 15 24 3 8 
25 2 9 14 23 

25 8 5 14 19 
6 13 18 9 4 
1 24 7 20 15 
12 17 22 3 10 
23 2 11 16 21 

19 8 5 14 25 
6 13 18 9 4 
1 20 7 24 15 
12 17 22 3 10 
21 2 11 16 23 

21 8 5 14 19 
6 13 20 9 4 
1 22 7 18 15 
12 17 24 3 10 
23 2 11 16 25 

23 8 5 14 25 
6 13 24 9 4 
1 22 7 18 15 
12 17 20 3 10 
21 2 11 16 19 

21 12 5 10 19 
6 17 20 13 4 
1 22 11 18 9 
16 7 24 3 14 
23 2 15 8 25 

23 12 5 10 25 
6 17 24 13 4 
1 22 11 18 9 
16 7 20 3 14 
21 2 15 8 19 

23 12 5 10 21 
6 17 22 13 4 
1 24 11 20 9 
16 7 18 3 14 
25 2 15 8 19 

21 12 5 10 23 
6 17 22 13 4 
1 20 11 24 9 
16 7 18 3 14 
19 2 15 8 25 

21 14 5 10 19 
6 11 20 15 4 
1 22 13 18 9 
12 7 24 3 16 
23 2 17 8 25 

23 14 5 10 25 
6 11 24 15 4 
1 22 13 18 9 
12 7 20 3 16 
21 2 17 8 19 

25 14 5 10 23 
6 11 24 15 4 
1 18 13 22 9 
12 7 20 3 16 
19 2 17 8 21 

19 14 5 10 21 
6 11 20 15 4 
1 18 13 22 9 
12 7 24 3 16 
25 2 17 8 23 

23 16 5 10 21 
6 11 22 17 4 
1 24 15 20 9 
12 7 18 3 14 
25 2 13 8 19 

21 16 5 10 23 
6 11 22 17 4 
1 20 15 24 9 
12 7 18 3 14 
19 2 13 8 25 

25 16 5 10 23 
6 11 24 17 4 
1 18 15 22 9 
12 7 20 3 14 
19 2 13 8 21 

19 16 5 10 21 
6 11 20 17 4 
1 18 15 22 9 
12 7 24 3 14 
25 2 13 8 23 

23 10 5 16 21 
6 15 22 11 4 
1 24 9 20 17 
14 7 18 3 12 
25 2 13 8 19 

21 10 5 16 23 
6 15 22 11 4 
1 20 9 24 17 
14 7 18 3 12 
19 2 13 8 25 

25 10 5 16 19 
6 15 18 11 4 
1 24 9 20 17 
14 7 22 3 12 
23 2 13 8 21 

19 10 5 16 25 
6 15 18 11 4 
1 20 9 24 17 
14 7 22 3 12 
21 2 13 8 23 
        
*/
/*
Time Complexity : O(8^(N^2))
Space Complexity: O(N*N), Where N is the length of board.
*/

