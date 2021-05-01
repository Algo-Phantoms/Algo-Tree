/*
A 2D Array is Used for Matrix, 1st Matrix size is taken first then 1st Matrix is taken
Then, 2st Matrix size is taken first then 2st Matrix is taken
After That if no of columns of 1st Matrix is equal to no of rows of 2nd Matrix
Then, Valid Multiplication is Made
Otherwise Retuns "Invalid Size of Matrix"
.
*/

package matrixop;
import java.util.Scanner;

public class MatrixOP {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Size of Array");
        // Taking Size of 1st Matrix
        int l1 = scan.nextInt();
        int h1 = scan.nextInt();
        int[][] twoDarr1 = new int[l1][h1];
        System.out.println("Enter All Values of 1st Matrix");
        // Taking Input of 1st Matrix
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < h1; j++) {
                twoDarr1[i][j] = scan.nextInt();
            }
        }
        // Taking Size of Second Matrix
        int l2 = scan.nextInt();
        int h2 = scan.nextInt();
        if (h1 == l2) {
            System.out.println("Enter All Values of 2nd Matrix :");
            int[][] twoDarr2 = new int[l2][h2];
            // Taking Input of 2nd Matrix
            for (int i = 0; i < l2; i++) {
                for (int j = 0; j < h2; j++) {
                    twoDarr2[i][j] = scan.nextInt();
                }
            }
            // Multiplication Two Matrix
            int[][] mul = new int[l1][h2];
            for (int i = 0; i < l1; i++) {
                for (int j = 0; j < h2; j++) {
                    int sum = 0;
                    for (int k = 0; k < h2; k++) {
                        sum += (twoDarr1[i][k] * twoDarr2[k][j]);
                    }
                    twoDarr1[i][j] = sum;
                }
            }

            //Printing Multiplication of 2 Matrix
            System.out.println("Multiplication of Two Matrix is :");
            for (int i = 0; i < l1; i++) {
                for (int j = 0; j < h2; j++) {
                    System.out.print(mul[i][j] + " ");
                }
                System.out.println();
            }
        }else {
            System.out.println("These Matrix can't be Multiplied");
        }
    }
}
/*
    Test Cases:
        Input : 2 3

                4 1 8
                9 4 3

                3 1

                1
                8
                2

        Output: 28
                47




        Input :  2 2

                 4 2
                 8 5

                 2 2

                 0 6
                -1 0

        Output:  -2 24
                 -5 48

        Time Complexity: O(n^3) where n is length of matrix
        Space Complexity: O(n^2)
 */
