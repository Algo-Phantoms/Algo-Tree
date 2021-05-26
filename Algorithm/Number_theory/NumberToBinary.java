/*
 Integers that we use on daily basis have base value of 10.
 But a binary number is a number with base value of 2.
 The binary numbers consists only of digits 0 and 1.
 In the below algorithm to convert an integer to binary number we basically use two operations
          1. Modulo
          2. Division.

 ALGORITHM:-

 In this algorithm we will divide the number by 2 till it becomes 0.
 In each step we will first take modulo 2 of that number and append it to beginning of a String (initially initialized with NULL)
          and then divide the number by 2.

Below is the java implementation of the above approach:
 */
package numberToBinary;
import java.util.Scanner;

public class NumberToBinary {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
        System.out.println("Enter A Number :");
        int n = scan.nextInt();
        System.out.println("It's Binary Representation is :");
        int_to_bin(n);

	}
	public static void int_to_bin(int n){
        String str="\0";
        do
        {
        	if(n%2==0)
        		str='0'+str;
        	else
        		str='1'+str;
        	n/=2;
        }while(n!=0);
        System.out.println(str);
    }

}

/*
           Test Cases:
                      Input: 22
                      Output: 10110

                      Input: 114
                      Output: 1110010

            Time Complexity: O(log(n)) where n is the Number as a input.
            Space Complexity: O(1)
*/
