/* Description: A transpose matrix is formed by interchanging the rows and columns of
a given matrix.

Approach: An arbitrary variable is taken which stores the array element of mth row and nth column.
It is then swapped with the array element corresponding to nth row and mth column. 
This process is continued till the last element.
*/
import java.util.Scanner;
public class transpose
{
       public static void main(String [] args)
       {
           Scanner scan=new Scanner(System.in);
           int order;
           int swap=0;
           System.out.println("Enter the order of square matrix");
           order=scan.nextInt();

           int [][] matrix = new int[order][order];
	   System.out.println("Enter the elements of the matrix");
	   for(int row=0; row < order; row++)
	   {
		for(int column=0; column < order; column++)
		{
		     matrix[row][column]=scan.nextInt();
		}
	   }

           for(int count=1; count < order; count++)
           {
		for(int count1=0; count1 <= count; count1++)
		{
               	      swap=matrix[count][count1];
               	      matrix[count][count1]=matrix[count1][count];
                      matrix[count1][count]=swap;
		}
           }
	   System.out.println("Transpose:");
	   for(int row1=0; row1 < order; row1++)
           {
                for(int column1=0; column1 < order; column1++)
                {
                      System.out.print(matrix[row1][column1]+" ");
                }
                System.out.println();
           }
        
       }
}
/*  
Test Case 1:

Enter the order of square matrix
5

Enter the elements of the matrix
23 43 89 67 5
34 54 56 7 89
57 96 42 87 9
79 34 32 1 23
46 7 78 3 65 

Transpose:
23 34 57 79 46
43 54 96 34 7
89 56 42 32 78
67 7 87 1 3
5 89 9 23 65


Test Case 2:

Enter the order of square matrix
3

Enter the elements of the matrix
34 87 58
33 5 6
563 65 5

Transpose: 
34 33 563
87 5 65
58 6 5

Time Complexity: O(n^2)
Here n is the order of matrix
Space Complexity: O(1)
*/

