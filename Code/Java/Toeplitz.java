/*

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
or
A Toeplitz (or diagonal-constant) matrix is a matrix in which each descending diagonal
from left to right is constant, i.e., all elements in a diagonal are same.
So, Starting from [0][0], Here We will check Elements one by one but next element will be always
in the next row and next column. if its not found as previous element then its not following Torplitz
Algorithm so, Return False else if It runs upto end with no retuen means Its Following Toeplitz algo,
So Return True.

*/
package tmatrix;
import java.util.Scanner;


public class CheckToePlitxMatrix {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        //Taking Size of Matrix
        int l = scan.nextInt();
        int b = scan.nextInt();
        int[][] matrix = new int[l][b];
        //Taking Matrix Values
        for (int i = 0; i < l; i++){
            for (int j = 0; j < b; j++){
                matrix[i][j] = scan.nextInt();
            }
        }
        System.out.println(isToeplitzMatrix(matrix));
    }
    public static boolean isToeplitzMatrix(int[][] matrix) {
        int rlen = matrix.length;
        int clen = matrix[0].length;

        //horizontal checking
        for (int i = 0; i < clen; i++){
            //temp is count so that j will move till till max row length
            int temp = 0;
            int val = matrix[temp][i];
            temp++;
            for (int j = i+1; j < clen && temp < rlen; j++){
                if (val != matrix[temp][j]){
                    return false;
                }
                temp++;
            }
        }

        //vertical checking
        for (int i = 1; i < rlen; i++){
            //temp is count so that j will move till till max column length
            int temp = 0;
            int val = matrix[i][temp];
            temp++;
            for (int j = i+1; j < rlen && temp < clen; j++){
                if (val != matrix[j][temp]){
                    return false;
                }
                temp++;
            }
        }
        return true;
    }
}
/*
    Test Cases:
        Input: 3
               4
               1 2 3 4
               5 1 2 3
               9 5 1 2
        Output: true

        Input: 2
               2
               1 2
               2 2
        Output: false

        Time Complexity: O(n^2) where n is No. of Diagonal Elements in Matrix
        Space Complexity: O(1)
 */
