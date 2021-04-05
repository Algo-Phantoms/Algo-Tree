
/* Problem Statement: Find 'a' power to 'b' in O(log n) time.
   Sample input: a=2, b=3.
                 Then 2 power to 3 (2^3) is 8.
                 

   Approach: The brute force solution would be calculating 'a' with itself 'b' times.
             This will take O(b) time, but we can improve the solution to O(log b) time complexity.
             Here we split 'b' into exponents. If b is odd then multiply it with result variable and decrement 'a'.
             If b is even multiply base with itself and half the value of 'b'. Continue this process until 'b' is greater than 0.
*/
import java.util.*;
public class MyClass {
    // Iterative function to calculate power of a and b
    public static int calculatePower(int a,int b)
    {
        // Storing the result in 'result' variable
        int result=1;
        // Applying the logic
        while(b>0)
        {
            // If 'b' is odd then multiply 'result' with 'a' and decrement 'b'
            if(b%2==1)
            {
                 result=result*a;
                 b--;
            }
            // If 'b' is even then square the value of 'a' and assign it to 'a' and half the value of 'b'
            else
            {
                a=a*a;
                b/=2;
            }
        }
        // Return the final result to main function
        return result;
    }
    public static void main(String args[]) {
        
      // Creating an object for Scanner class inorder to access values from key board    
      Scanner s=new Scanner(System.in);
      // Taking input and storing in num1 variable
      int num1=s.nextInt();
      // Taking input and storing in num2 variable
      int num2=s.nextInt();
      // Calling the function calculatePower() which calculates the value of num1^num2 and returns to main.
      System.out.println(calculatePower(num1,num2));
    }
}

/*
Testcases:

     Input1 : 2 5
     Output1: 32
     
     Input2 :3 9
     Output2:19683

*/

/*  Time Complexity : O(log n)
    Space Complexity: O(1)
*/
