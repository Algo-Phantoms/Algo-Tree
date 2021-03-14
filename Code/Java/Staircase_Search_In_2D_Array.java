

	//Approach

		// Start from top-right corner of  square 2D array 

		        //if array element is same as given element print indices of that element

		        //if array element is less than given element increase row in same column

		        //if array element is greater than given element decrease column by one in same row

		        //if element is nort present in given 2D array Print "Element is not present in given 2D array"



		package staircase;

		import java.io.*;
		import java.util.*;


		public class Staircase_Search_In_2D_Array
		{

		public static void main(String[] args) 
		{
		
		       Scanner sc=new Scanner(System.in);
		        
		       int s=sc.nextInt();               
			   // taking input size of square 2D array
		       int [][] arr=new int[s][s];       
			   //declaring the 2D array of size s*s
		        
		       	       		
		       for(int i=0; i<arr.length; i++)
			   {   
					//for loop for rows in given array
		       for(int j=0; j<arr[0].length; j++)
			   {  
					//For loop for column in given array
		            arr[i][j]=sc.nextInt();         
				     // taking array element as input
		       }
		        		
	           }
		        
		       int n=sc.nextInt();              
			   // taking n as input element to be searched                             
		       			       
		       int i=0;                           
		       int j=arr[0].length-1;
			   // For starting from top right corner initialise row index with 0  and column index with arr[0].length-1 
		        
		       while(i<arr.length && j>=0)
			   {     
		            			
		    	   if(n==arr[i][j])
				   {                 
					// if array element is same as given element to be searched print index of that element in two lines
		                System.out.println(i);
		               	System.out.println(j);
		                return;                      
						//exit
		           }
		            			
		    	   else if(n<arr[i][j])
				   {             
					// if array element is greater than given element decrease column by one
		                j--;
		           }
		           else
				   {                            
					// if array element is less than given element increase row by one
		                i++;
		           }
		       }
		        
		       System.out.println("Element is not present in given 2D array");       
			   //if element is not present in given array

			}

			}



		/*	Test Case 1:

			INPUT:

		   	4
		   	12 22 32 42
		   	15 25 35 45
		   	17 27 37 47
		        19 29 39 49
			29

		        OUTPUT:
		        3
		        1

			Test Case 2:

			INPUT:

		   	5
		   	11 22 31 41 51
		   	14 24 34 44 54
		   	16 26 36 46 56
		        17 27 37 47 57
		        19 28 38 49 58
			36

		        OUTPUT:
		        2
		        2

		*/


		/*	Time Complexity :
		              

		        For matrix of size m*n time complexity will be O(n+m).
		        For matrix of size n*n time complexity will be O(n).    */
	


