
/*
 * An evil number is a non-negative number that has an even number of 1s in its binary expansion.
 */

import java.util.*;

public class evil_number
{
    void main()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number: ");
        int number = scanner.nextInt(); scanner.nextLine();

        if(is_evil(number) == true)
        {
            System.out.println(number+" is an evil number");
        }
        else
        {
            System.out.println(number+" is not an evil number");
        }
    }

    boolean is_evil(int number)
    {
        int count_one = 0;

        while(number != 0)
        {
            if(number % 2 == 1)
                count_one++;

            number /= 2;
        }

        if(count_one % 2 == 0)
            return true;
        else
            return false;
    }
}

/*
 * Test Cases:
 * 
 * 1.
 * Enter number: 
 * 23
 * 23 is an evil number
 * 
 * 2.
 * Enter number: 
 * 32
 * 32 is not an evil number
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where n is the number of rounds
 */