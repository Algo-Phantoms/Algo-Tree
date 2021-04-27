/*
A 2D Array is Used for Matrix, firstly size of matrix is take then that Matrix of that Size is taken
for Inverse we Need to find Adjoint of Matrix.
Inverse of a matrix exists only if the matrix is non-singular i.e., determinant should not be 0.
Using determinant and adjoint, Here we will find the inverse of a square matrix using this formula,
    [ Inverse Matrix ] A^(-1) = adj(A)/det(A)
    where adj(A) is adjoint Matrix of A.
    and for adjoint we need cofactor matrix so, Method getCofactor is added
Inverse of any Square Matrix
*/

package matrixop;
import java.util.Scanner;

public class MatrixOP {
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Size of Square Matrix");
        int l1 = scan.nextInt();
        int[][] A = new int[l1][l1];
        System.out.println("Enter All Values of 1st Matrix");
        // Taking Input of Matrix
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < h1; j++) {
                A[i][j] = scan.nextInt();
            }
        }
        // For adjoint of A[][]
        int [][]adj = new int[A.length][A[0].length];
        // For Inverse of A[][]
        float [][]inv = new float[A.length][A[0].length];
        System.out.println("Entered matrix is :");
        display(A);
        //System.out.println("rx");
        System.out.println("Adjoint of Entered Matrix is :");

        adjoint(A, adj);
        display(adj);
        System.out.println("Inverse of Matrix is :");
        if (inverse(A, inv)) {
            display(inv);
        }else{
            System.out.println("Inverse Doset Exist");
        }
    }
    // Function to get cofactor of A[p][q] in temp[][]. n is current
    public static void getCofactor(int A[][], int temp[][], int p, int q, int n)
    {
        int i = 0, j = 0;
        // Looping for each element of the matrix
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // Copying into temporary matrix only those element which are not in given row and column
                if (row != p && col != q)
                {
                    temp[i][j++] = A[row][col];
                    // Row is filled, so increase row index and reset col index
                    if (j == n - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    // Determinant of matrix using Recursion.
    public static int determinant(int A[][], int n)
    {
        int D = 0;
        // case 1 : if matrix contains single element
        if (n == 1) {
            return A[0][0];
        }
        // For cofactors
        int [][]temp = new int[A.length][A[0].length];
        // For sign multiplier
        int sign = 1;
        // Iterate first row's each element
        for (int f = 0; f < n; f++)
        {
            // Getting Cofactor of A[0][f]
            getCofactor(A, temp, 0, f, n);
            D += sign * A[0][f] * determinant(temp, n - 1);
            // terms are to be added with alternate sign
            sign = -sign;
        }
        return D;
    }

    // Function to get adjoint of A[N][N] in adj[N][N].
    public static void adjoint(int A[][], int [][]adj)
    {
        if (A.length == 1)
        {
            adj[0][0] = 1;
            return;
        }
        // temp to keep cofactors of A[][]
        int sign = 1;
        int [][]temp = new int[A.length][A[0].length];
        for (int i = 0; i < A.length; i++){
            for (int j = 0; j < A[0].length; j++){
                getCofactor(A, temp, i, j, A.length);
                // sign of adj[j][i] positive if sum of row and column indexes is even.
                sign = ((i + j) % 2 == 0)? 1: -1;
                // Interchanging rows and columns to get the transpose of the cofactor matrix
                adj[j][i] = (sign)*(determinant(temp, A.length-1));
            }
        }
    }

    // Method to calculate Inverse
    public static boolean inverse(int A[][], float [][]inverse) {
        // Find determinant of A[][]
        int det = determinant(A, A.length);
        if (det == 0) {
            System.out.print("A is a Singular matrix so Inverse dosent Exist");
            return false;
        }
        // Getting adjoint
        int[][] adj = new int[A.length][A[0].length];
        adjoint(A, adj);
        // Inverse using formula "inverse(A) = adj(A)/det(A)"
        for (int i = 0; i < A.length; i++){
            for (int j = 0; j < A.length; j++) {
                inverse[i][j] = (adj[i][j] / (float) det);
            }
        }
        return true;
    }

    // Method to display the matrix
    public static void display(int A[][])
    {
        for (int i = 0; i < A.length; i++)
        {
            for (int j = 0; j < A[0].length; j++) {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static void display(float A[][])
    {
        for (int i = 0; i < A.length; i++)
        {
            for (int j = 0; j < A[0].length; j++) {
                System.out.printf("%.6f ", A[i][j]);
            }
            System.out.println();
        }
    }
}

/*
    Test Cases:
        Input : 2 2
                1 2
                3 4

        Output: -2.000000  1.000000 
                 1.500000 -0.500000
             

        Input :  3 3
                 2 4 5
                 1 6 8
                 3 1 4

        Output:  0.592593   -0.407407   0.074074
                 0.740741   -0.259259  -0.407407
                -0.629630    0.370370   0.296296

        Time Complexity: O(n^2) where n is the length of matrix
        Space Complexity: O(n^2)
 */
