/*
Factorial is the product of all positive integers less than or equal to a given positive integer 
and denoted by that integer and an exclamation point. 
Thus, factorial seven is written 5!, meaning 1 × 2 × 3 × 4 × 5.
Factorial zero is defined as equal to 1.
*/

import java.util.Scanner;

public class factorial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        intgit  n = sc.nextInt();
        System.out.println(fact(n));
    }
    public static int fact(int n){
        if(n==0)
            return 1;

        return n*fact(n-1);
    }
}

/*
    Test Cases:
    Input: 5
    Output: 120

    Input: 0
    Output: 1

    Time Complexity: O(n)
    Space Complexity: O(n)
*/