
/*
 * This program returns the first non repeating character 
 * in a string input by the user.
 * 
 * Makes use of the function indexOf()
 */

import java.util.*;

public class nonrepeating_char
{
    public void main()
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter word: ");
        String str = scanner.nextLine();
        
        System.out.println("First non repeating character in the word is: "+nonrepchar(str));
    }
    
    char nonrepchar(String str)
    {
        int i = 0;
        for(i = 0; i < str.length(); i++)
        {
            // condition 1 checks if character appears in the string after the index i
            // condition 2 checks if character appears in the string before the index i
            if((str.indexOf(str.charAt(i), i+1) == -1) && ((str.substring(0,i)).indexOf(str.charAt(i)) == -1))
                break;
        }
        
        return str.charAt(i);
    }
}

/*
 * Test Cases-
 * 
 * 1.
 * Enter word: 
 * madam
 * First non repeating character in the word is: d
 * 
 * 2.
 * Enter word: 
 * abcdaeecd
 * First non repeating character in the word is: b
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where n is the length of the string
 */