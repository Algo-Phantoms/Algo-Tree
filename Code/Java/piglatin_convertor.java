/*
 * In Pig Latin -
 * - words starting with consonant - take the consonant cluster and 
 *   move it to the end of the word, adding the suffix - 'ay'.
 * - words starting with vowel - add the suffix 'hey' to the word
 */

import java.util.*;

public class piglatin_convertor
{
    public void main()
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter a string: ");
        String str = scanner.nextLine();
        
        System.out.println("In piglatin: ");
        System.out.println(string_piglatin(str));
    }
    
    String string_piglatin(String str)
    {
        str = str + " ";
        
        String w = "", piglatin = "";
        char ch;
        int i;
        
        for(i = 0; i < str.length(); i++)
        {
            ch = str.charAt(i);
            
            if(ch == ' ')
            {
                piglatin += word_piglatin(w) + ' ';
                w = "";
            }
            else
            {
                w += ch;
            }
        }
        
        return piglatin;
    }
    
    String word_piglatin(String w)
    {
        int i; 
        char ch, ch1 = w.charAt(0);
        
        w.toLowerCase();
        
        if(ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u')
        {
            return w+"hay";
        }
        
        for(i = 0;  i < w.length(); i++)
        {
            ch = w.charAt(i);
            
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                break;
        }
        
        return ( w.substring(i) + w.substring(0,i) + "ay");
    }
}
      
/*
 * Test Cases-
 * 
 * 1.
 * Enter a string: 
 * how are you
 * In piglatin: 
 * owhay arehay ouyay 
 * 
 * 2.
 * Enter a string: 
 * i am good
 * In piglatin: 
 * ihay amhay oodgay 
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) 
 * where n is the number of characters in the string
 */ 
        
                
        