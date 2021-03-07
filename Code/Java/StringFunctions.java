//Java has multiple inbuilt functions which are specially used to solve problems on strings.
import java.util.*;

public class StringFunctions{
    
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        //Taking a string as input from user
        String input=sc.nextLine();
        //String Functions
        //1-.length() -gives the length of the string
        
        int l=input.length();
        System.out.println(l);
        
        
        //2-.substring() function returns a subsequence of the given string 
        //Syntax-substring(startIndex,EndIndex);
        String sub=input.substring(1,l);
        System.out.println(sub);
        
        String s1=input;
        //3-.equals() function checks if 2 strings are equal or not
        if(input.equals(s1))
        {
            System.out.println("Equal Strings");
        }
        //4-.isEmpty Function Checks is String is null/Empty
        if(input.isEmpty())
        {
            System.out.println("Empty");
        }
        else
        {
            System.out.println("Not Empty");
            
        }
        
        
        /*Test Cases:
           1.input="Anjali"
           Output:
           
           6
           njali
           Equal Strings
           Not Empty
           */
        
    
    }
}


    
