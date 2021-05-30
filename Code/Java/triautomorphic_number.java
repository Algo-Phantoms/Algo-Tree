/*
 * A number n is called triautomorphic if 3n^2 ends in n.
 * Example:
 *         n=667
 *         3n^2 = 1334667
 *         which ends with 667
 * This code checks whehter the input number is triautomorphic or not.
 */
import java.util.*;
public class triautomorphic_number
{
    void main()
    {
        //driver function
        
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number: ");
        int number = scanner.nextInt();
        scanner.nextLine();

        if(is_triautomorphic(number) == true)
        {
            System.out.println(number+" is a Triautomorphic number!");
        }
        else
        {
            System.out.println(number+" is not a Triautomorphic number!");
        }
    }
    
    boolean is_triautomorphic(int number)
    {
        //this function checks whether number is triautomorphic or not
        
        int triauto = 3*number*number;
        
        if((triauto % Math.pow(10,no_of_digits(number))) == number)
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
 * 1.
 * Enter number: 
 * 5
 * 5 is a Triautomorphic number!
 * 
 * 2.
 * Enter number: 
 * 8
 * 8 is not a Triautomorphic number!
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where n is the number of digits in the number
 */