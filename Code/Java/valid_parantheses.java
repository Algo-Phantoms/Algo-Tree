/*
Generate all valid parentheses

Problem  Statement: Write a program to generate all possible "n" pairs of balanced parantheses where "n" is the input from user.
                    For e.g if  n = 2, the possible combinations are {}{}, {{}} only. I have solved it by storing the combination of parantheses
                    and calling for the next set recursively.
                    
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class valid_parantheses{
        
        //function to print all valid pairs of parantheses by storing the count of opening and closing brackets
        static void generate_parantheses(char str[], int pos, int n, int start, int end){
            if(end == n){
                for(int i = 0; i < str.length; i++){
                    //printing all pairs of parantheses
                    System.out.print(str[i]);           
                }
                
                System.out.println();
                return;
            }
            else{
                //checking the condition for inserting the closing parantheses
                if(start > end){
                    str[pos] = '}';
                    generate_parantheses(str, pos+1, n, start, end+1);     
                }
                //checking the condition for inserting the opening parantheses
                if(start < n){                          
                    str[pos] = '{';
                    generate_parantheses(str, pos+1, n, start+1, end);   
                }
            }
        }
        
        //function to call the generate_parantheses function with initial values
        static void valid_parantheses_call(char ans[], int n){
            if( n > 0)
                generate_parantheses(ans, 0, n, 0 , 0);
            
            return;
        }
    
    	public static void main (String[] args) throws java.lang.Exception
    	{
    	        Scanner sc = new Scanner(System.in); 
                int n = 0;
                n = sc.nextInt();        
                //generating a character array for storing parantheses
                char [] arr = new char[2*n];
                valid_parantheses_call(arr, n);
    	}
}

/*Test Cases:
1.
        Input: 
                3
        Output:
                {}{}{}
                {}{{}}
                {{}}{}
                {{}{}}
                {{{}}}
               
2. 
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

               
Time Complexity: O(2^n), where n is the number for which, pairs of balanced parantheses are to generated

Space Complexity: O(n), since we have created character array of size 2*n where n is the number for which, pairs of balanced parantheses are to generated
              
*/
