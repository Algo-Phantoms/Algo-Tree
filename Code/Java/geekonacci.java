/*
 * Geek created a random series and given a name geek-onacci series. 
 * Given four integers A, B, C, N. A, B, C represents the first three numbers of geek-onacci series. 
 * Find the Nth number of the series. 
 * The nth number of geek-onacci series is a sum of the last three numbers 
 * (summation of N-1th, N-2th, and N-3th geek-onacci numbers).
 */

import java.util.*;

public class geekonacci
{
    public void main()
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter A: ");
        int A = scanner.nextInt();
        scanner.nextLine();
        
        System.out.println("Enter B: ");
        int B = scanner.nextInt();
        scanner.nextLine();
        
        System.out.println("Enter C: ");
        int C = scanner.nextInt();
        scanner.nextLine();
        
        System.out.println("Enter N: ");
        int N = scanner.nextInt();
        scanner.nextLine();
        
        System.out.println(N+"th term of the geek-onacci series is: "+geekonacci(A,B,C,N));
    }
    int geekonacci(int A, int B, int C, int N)
    {
        // function to find nth term of the geekonacci series
        int count = 4, sum = 0;
        
        while(count<=N)
        {
            sum = A + B + C;
            A = B;
            B = C;
            C = sum;
            count++;
        }
        
        return sum;
    }
}
    
/*
 * Test Cases-
 * 
 * 1.
 * Enter A: 
 * 1
 * Enter B: 
 * 2
 * Enter C: 
 * 3
 * Enter N: 
 * 4
 * 4th term of the geek-onacci series is: 6
 * 
 * 2.
 * Enter A: 
 * 1
 * Enter B: 
 * 3
 * Enter C: 
 * 2
 * Enter N: 
 * 6
 * 6th term of the geek-onacci series is: 19
 * 
 * Time Complexity = O(log n)
 * Space Complexity = O(1)
 */