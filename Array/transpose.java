/* Description: A transpose matrix is formed by interchanging the rows and columns of
a given matrix.

Approach: An arbitrary variable is taken which stores the array element of mth row and nth column.
It is then swapped with the array element corresponding to nth row and mth column. 
This process is continued till the last element.
*/
//mypack;
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

           int [][] matrix=new int[order][order];
	   System.out.println("Enter the elements of the matrix");
	   for(int row=0;row<order;row++)
	   {
		for(int column=0;column<order;column++)
		{
		     matrix[row][column]=scan.nextInt();
		}
	   }

           for(int count=1;count<order;count++)
           {
		for(int count1=0;count1<=count;count1++)
		{
               	      swap=matrix[count][count1];
               	      matrix[count][count1]=matrix[count1][count];
                      matrix[count1][count]=swap;
		}
           }
	   System.out.println();
	   for(int row1=0;row1<order;row1++)
           {
                for(int column1=0;column1<order;column1++)
                {
                      System.out.print(matrix[row1][column1]+" ");
                }
                System.out.println();
           }
        
       }
}
