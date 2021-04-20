/*Finding Long Factorial
Problem  Statement:
Factorial of a non-negative integer, is the multiplication of all integers starting from 1, smaller than or equal to n.
Implement the factorial function which will calculate the factorials of large number having range greater than range of int or long int.
For e.g factorial of 5 = 120.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class Long_Factorial{
        
        //function to find and print the factorial
        static void find_factorial(int n){
            //array to store the number of factorials 
            int ans[] = new int[1000];          
            ans[0] = 1;
            // initialising the size of array with 1
            int ans_size = 1;                  
            
            //applying the simple formula i.e- '1*2*3.....(n-1)*n'
            for(int y = 2; y <= n ; y++){
                ans_size = multiplication(y, ans, ans_size);  
            }
            
            System.out.print("Factorial of the number is: ");
            for(int i = ans_size - 1; i >= 0; i--){
                System.out.print(ans[i]);                   
            }
        }
        
        // function to multiply the number 'y' i.e 'num' with the numbers stored in 'ans' array till the end of the array.
        static int multiplication(int num, int ans[], int ans_size){
            int carry = 0;
            //multiplication of the number 'fact' one by one with the elements of 'arr'
             for(int i = 0; i < ans_size ; i++){
                int fact = ans[i]*num + carry;
                ans[i] = fact%10;  
                carry = fact/10;
            }
            
            //putting carry in the 'ans' array and increasing it size
            while(carry != 0){
                ans[ans_size] = carry%10;
                carry = carry/10;
                ans_size++;
            }
            return ans_size;        
        }
    
	public static void main (String[] args) throws java.lang.Exception
	{
	        Scanner sc = new Scanner(System.in);
            System.out.print("Enter the number: ");     
            int n = sc.nextInt();                   
    		find_factorial(n);                 
	}
}

/*
Test Cases
1. 
Input: 
Enter the number: 50
                
Output: 
Factorial of the number is: 30414093201713378043612608166064768844377641568960512000000000000
                
2. 
Input:
Enter the number: 100                
Output:
Factorial of the number is: 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000

Time Complexity: O(n^2) for the loop for applying the multiplication formula and calling the function "multiplication inside it
                 where n is the number whose factorial is to be calculated

Space Complexity: O(n) for creating the array of size n, where n is the number whose factorial is to be calculated            
*/
