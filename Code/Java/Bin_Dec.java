/*

 */
package binTOdecimal;
import java.util.Scanner;

public class BinaryToDecimal {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter No : ");
        int n = scan.nextInt();
        System.out.println(isPrime(n));
    }
}
/*
    Test Cases:
        Input:
        Output:

        Input:
        Output:

        Time Complexity: O(n)
        Space Complexity: O(1)
 */