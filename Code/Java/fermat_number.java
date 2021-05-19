
/*
 * A Fermat Number can be defined by the formula:
 *        k
 *       2
 *      2    +    1
 *      
 *    where k = 1, 2, 3...
 * This program gives the user the first n fermat numbers.
 */

import java.util.*;

public class fermat_number
{
    void main()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter n: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        int count = 0;

        System.out.println("First "+n+" Fermat numbers are: ");
        while(count<n)
        {
            System.out.print(fermat(count)+", ");
            count++;
        }
    }

    double fermat(int k)
    {
        return (Math.pow(2,Math.pow(2,k))) + 1;
    }
}

/*
 * Test Case-
 * 
 * Enter n:
 * 5
 * First 5 Fermat numbers are: 
 * 3.0, 5.0, 17.0, 257.0, 65537.0, 
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where n is the number of terms extracted
 */