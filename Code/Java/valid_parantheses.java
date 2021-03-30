/*Generate all valid parantheses
Problem  Statement: Write a program to generate all possible "n" pairs of balanced parantheses.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class Paranthesis{
        
        //function to print all valid pairs of parantheses by storing the count of opening and closing brackets
        static void generate_paranthesis(char str[], int pos, int n, int start, int end){
            if(end == n){
                for(int i = 0; i < str.length; i++){
                    System.out.print(str[i]);           //printing all pairs of parantheses
                }
                
                System.out.println();
                return;
            }
            else{
                if(start > end){                       //checking the condition for inserting the closing parantheses
                    str[pos] = '}';
                    generate_paranthesis(str, pos+1, n, start, end+1);     //calling the function for the next position using recursion
                }
                if(start < n){                          //checking the condition for inserting the opeing paranthesis
                    str[pos] = '{';
                    generate_paranthesis(str, pos+1, n, start+1, end);    //calling the function for the next position using recursion
                }
            }
        }
        
        //function to call the generate_parantheses function with initial values
        static void valid_paranthesis(char ans[], int n){
            if( n > 0)
                generate_paranthesis(ans, 0, n, 0 , 0);
            
            return;
        }
    
    	public static void main (String[] args) throws java.lang.Exception
    	{
    	        Scanner sc = new Scanner(System.in); 
                int n = 0;
                n = sc.nextInt();                               //input from the users
                char [] arr = new char[2*n];                    //generating a character array for storing parantheses
        		valid_paranthesis(arr, n);                      //calling the function
    	}
}

/*Test Case 1: 
        Input: 
                3
        Output:
                {}{}{}
                {}{{}}
                {{}}{}
                {{}{}}
                {{{}}}
               
Test Case 2: 
        Input: 
                 4
        Output:
                {}{}{}{}
                {}{}{{}}
                {}{{}}{}
                {}{{}{}}
                {}{{{}}}
                {{}}{}{}
                {{}}{{}}
                {{}{}}{}
                {{}{}{}}
                {{}{{}}}
                {{{}}}{}
                {{{}}{}}
                {{{}{}}}
                {{{{}}}}

               
Time Complexity: O(2^n)

Space Complexity: O(n)
              
*/
