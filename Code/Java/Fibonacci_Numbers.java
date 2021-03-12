/*
Fibonacci series is number series where the next number is the
sum of previous two numbers. The first two numbers of the series are 0 and 1
A fibonacci series of 10 terms looks like: 0 1 1 2 3 5 8 13 21 34
The first two numbers are 0 and 1, the next number is the sum of 0 and 1 (The previous numbers)
2 is the sum of 1 and 1, 3 is the sum of 1 and 2, 5 is the sum of 2 and 3 and so on.....
*/

import java.util.Scanner;

public class Fibonacci_Numbers
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int a = 0, b = 1;
        int n = sc.nextInt();
        fibonacci(a, b, n);
    }

    static void fibonacci(int a, int b, int n)
    {
        if(n > 0)
        {
            System.out.print(a + " ");
            fibonacci(b, a+b, --n);
        }
    }
}

/*
    Test Cases:

    Input: 5
    Output: 0 1 1 2 3

    Input: 10
    Output: 0 1 1 2 3 5 8 13 21 34

    Input: 20
    Output: 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181
*/