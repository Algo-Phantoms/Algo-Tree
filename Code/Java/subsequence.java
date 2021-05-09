/*
 * A subsequence is a sequence that can be derived from another sequence by 
 * deleting some elements without changing the order of the remaining elements.
 */

import java.util.*;

public class subsequence
{
    public void main()
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter string 1: ");
        String str1 = scanner.nextLine();
        
        System.out.println("Enter string 2: ");
        String str2 = scanner.nextLine();
        
        if(subsequence(str1, str2))
        {
            System.out.println(str1+" is a subsequence of "+str2);
        }
        else
        {
            System.out.println(str1+" is a not subsequence of "+str2);
        }
    }
    
    boolean subsequence(String str1, String str2)
    {
        int l1 = str1.length();
        int l2 = str2.length();
        
        int i, j;
        
        for (i = 0, j = 0; i < l2 && j < l1; i++, j++)
            if (str1.charAt(j) == str2.charAt(i))
                j++;
 
        return (j == l1);
    }
}
 
/*
 * Test Cases-
 * 
 * 1.
 * Enter string 1: 
 * KPK
 * Enter string 2: 
 * KPOK
 * KPK is a subsequence of KPOK
 * 
 * 2.
 * Enter string 1: 
 * KPOK
 * Enter string 2: 
 * KPK
 * KPOK is a not subsequence of KPK
 * 
 * Time Complexity: O(n)
 * where n is length of str2
 */
        
            