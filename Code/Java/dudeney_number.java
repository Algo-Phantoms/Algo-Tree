/*
 * A Dudeney number is a positive integer that is a perfect cube such that 
 * the sum of its decimal digits is equal to the cube root of the number.
 */

import java.util.*;

public class dudeney_number
{
    public void main()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number: ");
        int number = scanner.nextInt(); scanner.nextLine();

        if(is_dudeney(number) == true)
        {
            System.out.println(number+" is a dudeney number");
        }
        else
        {
            System.out.println(number+" is not a dudeney number");
        }
    }

    boolean is_dudeney(int number)
    {
        int sumdigits = sum_of_digits(number);

        int cube = sumdigits * sumdigits * sumdigits;

        if(cube == number)
            return true;
        else
            return false;

    }

    int sum_of_digits(int number)
    {
        int sum = 0;

        while(number != 0)
        {
            sum += number % 10;
            number /= 10;
        }

        return sum;
    }
}

/*
 * Test Cases-
 * 
 * 1.
 * Enter number: 
 * 512
 * 512 is a dudeney number
 * 
 * 2.
 * Enter number: 
 * 64
 * 64 is not a dudeney number
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where n is the number of digits in the number input
 */