/*
* Russian peasant multiplication is an interesting way to multiply numbers that uses a process of halving and doubling without using multiplication operator. 
* The idea is to double the first number and halve the second number repeatedly till the second number doesn’t become 1.
* The basic concept is that to multiply n by m, we can compute (n/2)*(2m) if n is even and ((n-1)/2)*(2m) + m if n is odd instead.
* 
* It is also known as the Ancient Egyptian Multiplication, used by scribes to do multiplication
* without using the multiplication table.
*
* Note: This algorithm only works for positive numbers.
*/

import java.util.*;

public class RussianPeasant {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 2 numbers to multiply:");
        int a = sc.nextInt();
        int b = sc.nextInt();

        int result = 0;
        // for storing the product

        // loop till second number i.e. b > 0
        while (b > 0) {

            // if 'b' is odd add 'a' to result
            if ((b & 1) != 0) {
                result += a;
            }

            // double 'a' and halve 'b'
            a = a << 1;
            b = b >> 1;
        }

        System.out.println("Product is " + result +".");
        sc.close();
        //closing the scanner
    }
}


/*
* Test Cases:
* 1. 
* Enter 2 numbers to multiply:
* 8 9
* Product is 72.
*
*
* 2. 
* Enter 2 numbers to multiply:
* 77 65
* Product is 5005.
*
*
* Time Complexity: Θ(logn)
* Space Complexity: Θ(1)
*/
