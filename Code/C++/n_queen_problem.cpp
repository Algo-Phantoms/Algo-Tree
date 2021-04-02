/*
    N queen problem is a standard backtracking problem where according to the
    users input we have to place N queens on a (N X N) chessboard so that they do not attack each other.
    
    Movement of a queen on any board:  Diagonally or horizontally or vertically
    
    Backtracking approach:
    In this method we place one queen row by row using recursion, Before placing the queen we check
    whether it will be attacked by other queens or not,
    if not, we can place the queen in that particular coulumn of that row
    if the queen is being at that partiular column, we try placing it in the next column of that row,
    if it is not possible to place the queen in any column of that row, we backtrack and change the position of the queen that was placed in the previous row and so on.
    in the similar way we place all the N queens on the (N X N) board. 
*/
#include <iostream>
#include <cstring>
using namespace std;

//A queen is safe if there is not queen horizontally, verically and diagonal on both sides of elements
bool isSafe(int chessboard[][100], int row, int col, int n){
    //storing the position in x and y for reference; 
    int x = row;
    int y = col;
    //checking left diogonal
    while(x >= 0 && y >= 0){
        if(chessboard[x][y] == 1){
            //if any queen is already present on that diagonal we cannot place the queen
            return false;
        }
        //cordinate we can get of row by reducing 1 and of column by reducing 1;
        x--;
        y--;
    }
    //Again storing the position in x and y for reference
    x = row;
    y = col;
    //checking right diagonal
    while(x >= 0 && y < n){
        if(chessboard[x][y] == 1){
            //if any queen is already present on that diagonal we cannot place the queen
            return false;
        }
        //cordinates we can get of row by reducing 1 and of column by increasing 1;
        x--;
        y++;
    }
    //At last checking vertically, if there is any queen or not
    //only checking till row(not n) because we are placing queen row wise so there is no possibility that there will be a queen after row passes in function
    for(int i = 0; i < row; i++)
    {
        if(chessboard[i][col] == 1){
            // if queen is present vertically then queen cannot be placed and return false
            return false;
        }
    }
    //if till now there is no false encountered then the queen can be placed so return true
    return true;
}
//this is a recursive approch using backtracking
bool recursiveBacktracking(int chessboard[][100],int row, int n){
    //base condition for recusion(when all rows have been filled then row will be n)
    if(row == n){
        //since all the quuens have been placed 
        //print the solution
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //if chessboard[i][j]==1 then queen is present
                if(chessboard[i][j] == 1){
                    // print Q
                    cout << "Q ";
                }
                else{
                    //if chessboard[i][j] is equal to zero
                    // that means queen is not present here 
                    // print *
                    cout << "* ";
                }
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
        //to print only one solution return true 
        // returning false will print all possible solution
        return false;
    }
    //backtracking and placing queens
    for(int j = 0; j < n; j++){
        //check whether a queen can be places at that particular row, coloumn or not
        if(isSafe(chessboard, row, j, n)){
            //since it is safe
            //place the queen i.e put 1 at that place
            chessboard[row][j] = 1;
            //check if next queen we are able to place or not in next row
            bool nextQueen = recursiveBacktracking(chessboard, row + 1, n);
            // if we are able to place then we continue placing queens
            if(nextQueen){
                return true;
            }
            // if next queen connot be placed in any column, then we remove the queen we have placed earlier and try placing it in different column of this row
            chessboard[row][j] = 0;
        }
    }
    // if control comes here that mean we are not able to place all the queen 
    // so return false
    return false;
}

int main(){
    int n;
    cin >> n;
    //defining a 2d matrix 100 X 100 (Can be defined as per your input range)
    int chessboard[100][100];
    //initializing the 2d matrix with initial value 0
    memset(chessboard, 0, sizeof(chessboard));
    //function defined for backtracking approach
    recursiveBacktracking(chessboard, 0, n);
    return 0;
}
/*
TEST CASE 1:
INPUT: 4
OUTPUT: 

* Q * *
* * * Q
Q * * *
* * Q *


* * Q *
Q * * *
* * * Q
* Q * *

TEST CASE 2:
INPUT: 5
OUTPUT:

Q * * * * 
* * Q * *
* * * * Q
* Q * * *
* * * Q *


Q * * * *
* * * Q *
* Q * * *
* * * * Q 
* * Q * *


* Q * * *
* * * Q *
Q * * * *
* * Q * *
* * * * Q


* Q * * *
* * * * Q
* * Q * *
Q * * * *
* * * Q * 


* * Q * *
Q * * * *
* * * Q *
* Q * * *
* * * * Q 


* * Q * *
* * * * Q
* Q * * *
* * * Q *
Q * * * * 


* * * Q *
Q * * * *
* * Q * *
* * * * Q
* Q * * *


* * * Q *
* Q * * *
* * * * Q
* * Q * * 
Q * * * *


* * * * Q
* Q * * *
* * * Q *
Q * * * *
* * Q * *


* * * * Q
* * Q * *
Q * * * *
* * * Q *
* Q * * *

TIME COMPLEXITY: O(N!)  (N is the user input, that is the number of queens to be placed on a N X N chessboard)
SPACE COMPLEXITY: O(N^2) 
*/




