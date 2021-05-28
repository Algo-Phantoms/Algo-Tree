/*
A 2D Array is Used for Matrix, size is taken first then 2 Matrix of that Size is taken
(i,j)th Element of 1st Matrix is subtracted only from (i,j)th Element of 2nd Matrix in Matrix Addition.
*/

package matrixop;
import java.util.Scanner;


public class MatrixOP {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Size of Matrix");
        int l = scan.nextInt();
        int h = scan.nextInt();
        int[][] twoDarr1 = new int[l][h];
        
        System.out.println("Enter All Values of 1st Matrix");
        // Taking Input of 1st Matrix
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < h; j++) {
                twoDarr1[i][j] = scan.nextInt();
            }
        }
        
        System.out.println("Enter All Values of 2nd Matrix :");
        int[][] twoDarr2 = new int[l][h];
        // Taking Input of 2nd Matrix
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < h; j++) {
                twoDarr2[i][j] = scan.nextInt();
            }
        }
        
        
        // Subtracting Two Matrix
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < h; j++) {
                twoDarr1[i][j] -= twoDarr2[i][j];
            }
        }

        
        //Printing Matrix after Subtraction
        System.out.println("Matrix after subtraction is :");
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < h; j++) {
                System.out.print(twoDarr1[i][j] + " ");
            }
            System.out.println();
        }
        
    }
}
/*
    Test Cases:
        Input : 2 3
                4 1 8
                9 4 3
                1 2 3
                8 6 7

        Output: 3  -1  5
                1  -2 -4




        Input :  2 2
                 4 2
                 8 5
                 1 6
                -1 3

        Output:  3 -4
                 9  2

        Time Complexity: O(n^2) where n is the length of matrix
        Space Complexity: O(n^2)
 */
