
/*
 * Harshad/ Niven Number is an integer that is divisible by the sum of its digits.
 */

import java.util.*;

public class harshad_number
{
    public void main()
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter number: ");
        int number = scanner.nextInt(); scanner.nextLine();
        
        if(is_harshad(number) == true)
        {
            System.out.println(number+" is a harshad number");
        }
        else
        {
            System.out.println(number+" is not a harshad number");
        }
    }
    
    boolean is_harshad(int number)
    {
        int sum = 0, temp = number;
        
        while(temp != 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        
        if(number % sum == 0)
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
 * 81
 * 81 is a harshad number
 * 
 * 2.
 * Enter number: 
 * 53
 * 53 is not a harshad number
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where n is the number of rounds
 */