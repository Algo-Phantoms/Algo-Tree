/* 
 * A smith number is a composite number, the sum of whose digits is the 
 * sum of the digits of its prime factors obtained as a result of prime 
 * factorization (excluding 1).
 */

import java.util.*;

public class smith_number
{
    public void main()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number: ");
        int number = scanner.nextInt(); scanner.nextLine();

        if(is_smith(number) == true)
        {
            System.out.println(number+" is a smith number");
        }
        else
        {
            System.out.println(number+" is not a smith number");
        }
    }

    boolean is_smith(int number)
    {
        int sum_prime = 0, i;

        for(i = 2; i < number; i++)
        {
            if(is_prime(i) == true && number % i == 0)
                sum_prime += i;
        }
        
        if(sum_of_digits(number) == sum_of_digits(sum_prime))
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

    boolean is_prime(int i)
    {
        int j, c = 0 ;

        for(j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                c++;
                break;
            }
        }

        if(c == 0)
            return true;
        else
            return false;
    }

}

/*
 * Test Cases-
 * 
 * 1.
 * Enter number: 
 * 22
 * 22 is a smith number
 * 
 * 2.
 * Enter number: 
 * 21
 * 21 is not a smith number
 * 
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^3)
 * where n is the number of digits in the number input
 */