/*
 * A happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit.
 * Example:
 *   19 = 1+81 = 82 = 64+4 = 68 = 36+64 = 100 = 1+0+0 = 1 
 */

import java.util.*;

public class happy_number
{
    void main()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number: ");
        int number = scanner.nextInt(); scanner.nextLine();

        if(is_happy(number)==true)
        {
            System.out.println(number+" is a happy number");
        }
        else
        {
            System.out.println(number+" is not a happy number");
        }
    }

    boolean is_happy(int number)
    {
        if(number >= 0 && number <= 9)
        {
            if(number == 1)
                return true;
            else
                return false;
        }
        else
        {
            while(number>9)
            {
                int temp = number, sum = 0;

                while(temp != 0)
                { 
                    sum += (temp % 10) * (temp % 10);
                    temp /= 10;
                }

                number = sum;
            }
            
            if(number == 1)
            return true;
            else
            return false;
        }
    }
}

/*
 * Test Cases-
 * 
 * 1.
 * Enter number: 
 * 19
 * 19 is a happy number
 * 
 * 2.
 * Enter number: 
 * 18
 * 18 is not a happy number
 * 
 * Time Complexity: O(n)
 * Space Complecity: O(n)
 * where n is the rounds
 */
                    