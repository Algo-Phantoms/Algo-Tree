/*
Fibonacci series : is a series where each number is the sum of the previous two ,
starting from 0 and 1.

We created a array an store sum of previous two element in ith index
*/
import java.util.*;

public class Fibonacci {

    public static void main (String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        // Test case
        int t = scanner.nextInt();
        while(t-- > 0) {
            // Input the number
            int n = scanner.nextInt();
            int[] fibonacci = fibonacci(n);
            int sum = 0;
            System.out.println("Fibonacci Series :");
            for (int num :
                    fibonacci) {
                sum += num;
                System.out.print(num + " ");
            }
            System.out.println();
            System.out.println("Sum of "+n+" fibonacci number is = "+sum);
        }
    }
    static int[] fibonacci(int n)
    {
        // Declare an array to store n fibonacci numbers.
        int[] f = new int[n];

        // 0th and 1st number of the series are 0 and 1
        f[0] = 0;
        f[1] = 1;

        if(n>2) {
            for (int i = 2; i < n; i++) {
                //Add the previous 2 numbers in the series and store
                f[i] = f[i - 1] + f[i - 2];
            }
        }
        return f;
    }
}
/*
3
2
Fibonacci Series :
0 1
Sum of 2 fibonacci number is = 1

6
Fibonacci Series :
0 1 1 2 3 5
Sum of 6 fibonacci number is = 12

45
Fibonacci Series :
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 165580141 267914296 433494437 701408733
Sum of 45 fibonacci number is = 1836311902

Time Complexity:O(n)
Extra Space: O(n)
*/