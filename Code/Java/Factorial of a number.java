/*
Factorial is the product of all positive integers less than or equal to a given positive integer 
and denoted by that integer and an exclamation point. 
Thus, factorial five is written 5!, meaning 1 × 2 × 3 × 4 × 5.
Factorial zero is defined as equal to 1.
*/

import java.util.Scanner;
public class math {
   static int factorial(int n){
        int res = 1, i;
        for (i=2; i<=n; i++)
            res *= i;
        return res;
   }
public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
   System.out.println("Enter number :");
   int n = sc.nextInt();
   System.out.println("Factorial of " +n+" is: "+factorial(n))
}
}
/*
    Test Cases:
    Enter Number: 7
    Factorial of 7 is: 5040

    Enter Number: 0
    Factorial of 0 is: 1
    
    Enter Number:5
    Factorial of 5 is: 120

    Time Complexity: O(n)
    Space Complexity: O(n)
*/