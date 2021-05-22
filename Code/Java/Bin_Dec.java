/*

 */
package binTOdecimal;
import java.util.Scanner;

public class BinaryToDecimal {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Binary Number :");
        int n = scan.nextInt();
        System.out.println("Decimal Representation is :");
        bintodec(n);
    }
    public static void bintodec(int n){
        int dec = 0;
        int dummy = n;
        int count = 0;
        while (dummy > 0){
            int lastdigit = dummy % 10;
            dummy /= 10;
            dec += (lastdigit * Math.pow(2,count));
            count++;
        }
        System.out.println(dec);
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