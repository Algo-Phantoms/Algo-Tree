/*
The idea is to extract the digits of a given binary number starting from the rightmost digit
and keep a variable dec. At the time of extracting digits from the binary number,
multiply the digit with the (Power of 2) that will be made via Math.pow in which increment of i
will increase the power as we proceed to move towards digit at first place and add it to the variable
dec. In the end, the variable dec will store the required decimal number.

For Example:
If the binary number is 10110.
If we move from last digit to the first one
dec = 0*(2^0) + 1*(2^1) + 1*(2^2) + 0*(2^3) + 1*(2^4) = 22
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
        Input: 10110
        Output: 22

        Input: 1110010
        Output: 114

        Time Complexity: O(n) where n is the Number of Digits in Decimal Number
        Space Complexity: O(1)
 */
