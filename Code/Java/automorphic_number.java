/*
 * An automorphic number is whose square ends with the number itself.
 * Example:
 *      25*25 = 625
 *      which ends with 25
 * This code checks whehter the input number is automorphic or not.
 */

import java.util.*;
public class automorphic_number
{
    void main()
    {
        //driver function
        
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number: ");
        int number = scanner.nextInt();
        scanner.nextLine();

        if(is_automorphic(number) == true)
        {
            System.out.println(number+" is an Automorphic number!");
        }
        else
        {
            System.out.println(number+" is not an Automorphic number!");
        }
    }
    
    boolean is_automorphic(int number)
    {
        //this function checks whether number is automorphic or not
        
        int square = number*number;
        
        if((square % Math.pow(10,no_of_digits(number))) == number)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int no_of_digits(int number)
    {
        //this function counts the number of digits
        
        int count = 0;
        
        while(number!=0)
        {
            count++;
            number/=10;
        }
        
        return count;
    }
}

/*
 * Test Cases-
 * 
 * 1.
 * Enter number: 
 * 76
 * 76 is an Automorphic number!
 * 
 * 2.
 * Enter number: 
 * 7
 * 7 is not an Automorphic number!
 *
 * Time Complexity: O(n)
 * where n is the number of digits in the number input
 * 
 * Space Complexity: O(1)
 */