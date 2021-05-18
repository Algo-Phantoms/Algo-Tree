/*
 * A Unique Number is the difference between a number formed of n consecutive digits and its reverse.
 * For example,
 *           U3 = 543 - 345 = 198
 *           U4 = 7654 - 4567 = 3087
 * 
 * This program generates the first n unique numbers.
 */

import java.util.*;

public class unique_number
{
    void main()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter n: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        int count = 1, digit_count = 1, number = 0;

        System.out.println("First "+n+" unique numbers are: ");
        while(count <= n)
        {
            digit_count = 1;
            number = 0;

            while(digit_count <= count)
            {
                number = number * 10 + digit_count;
                digit_count++;
            }

            System.out.print((reverse(number) - number)+", ");

            count++;
        }
    }

    int reverse(int number)
    {
        int right_digit = 0, reverse = 0;
        
        while(number!=0)
        {
            right_digit = number%10;
            reverse = reverse*10 + right_digit;
            number/=10;
        }
        
        return reverse;
    }
}
        
/*
 * Test Case-
 * 
 * Enter n: 
 * 5
 * First 5 unique numbers are: 
 * 0, 9, 198, 3087, 41976, 
 * 
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 * where n is the number of terms extracted
 */        
        

            