/*
ROW WISE SUM OF A 2D ARRAY

Question: For a given two-dimensional integer array/list of size (N x M), 
find and print the sum of each of the row elements in a single line, 
separated by a single space.
 */
import java.util.*;
class solution{
//function to insert elements in 2d array
 public static int[][] take2DInput()
    {
          Scanner s=new Scanner(System.in);
          int n_rows=s.nextInt();  //number of rows 
           int n_cols=s.nextInt(); //number of columns
           
           if(n_rows==0)
           {
               return new int[0][0] ;
           }
           int mat[][]=new int[n_rows][n_cols];
           
           for(int row=0 ; row<n_rows ;row++)
           {
               for(int col=0 ; col<n_cols; col++)
               { 
                    int item=s.nextInt(); //element to insert in 2d array
                    mat[row][col]=item;
               
               }
           }
           return mat;
           
    }
	
//calculates row wise sum in 2d array	
 public static void rowWiseSum(int[][] mat) {
	//Your code goes here
        if(mat.length!=0){
         int rows=mat.length; //length os row
         int cols=mat[0].length;    //length of column  
         int sumit=0;
        
        for( int k=0;k<rows;k++){
            for(int j=0;j<cols;j++) {
             sumit+=mat[k][j]; //sum of row elements
                          
              }
              System.out.print(sumit+" ");
              sumit=0;
	}
   }
  }  


}

public class RowWise_Sum {        
    public static void main(String[] args) {
          //function call to insert elements in 2d array
          int[][] mat = solution.take2DInput();
          solution.rowWiseSum(mat);
          System.out.println();
          
    }

}
/*Sample Input 1:
4 2 
1 2 
3 4 
5 6 
7 8

output-->
3 7 11 15 

Input 2-->
2 5 
4 5 3 2 6 
7 5 3 8 9
Output-->
20 32 

Time Complexity - O(m*n) ,where m and n are no. of rows and columns resp.
Space Complexity - O(1) ,as no extra space is used except sum variable.
*/
