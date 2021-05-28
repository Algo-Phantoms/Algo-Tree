/*
 * A trimorphic number is whose cube ends with the number itself.
 * Example:
 *      49*49*49 = 117649
 *      which ends with 49
 * This code checks whehter the input number is trimorphic or not.
 */
import java.util.*;
class trimorphic_number
{
    void main()
    {
        //driver function
        
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number: ");
        int number = scanner.nextInt();
        scanner.nextLine();

        if(is_trimorphic(number) == true)
        {
            System.out.println(number+" is a Trimorphic number!");
        }
        else
        {
            System.out.println(number+" is not a Trimorphic number!");
        }
    }
    
    boolean is_trimorphic(int number)
    {
        //this function checks whether number is trimorphic or not
        
        int cube = number*number*number;
        
        if((cube % Math.pow(10,no_of_digits(number))) == number)
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
 * 24
 * 24 is a Trimorphic number!
 * 
 * 2.
 * Enter number: 
 * 21
 * 21 is not a Trimorphic number!
 *
 * Time Complexity: O(n)
 * where n is the number of digits in the number
 * Space Complexity: O(1)
 */
