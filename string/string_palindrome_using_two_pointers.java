import java.util.Scanner;
import java.io.*;

public class Palidrome_using_two_pointers 
{	
	public static boolean isPalindrome(String str1)
	{
		 	if (str1.length() == 0)//checking that string length is 0
	       	{
	        	return true;
	        }
		 	
	     	str1 = str1.toLowerCase(); // change all to lower case
	        int i = 0;
	        int j = str1.length() - 1;
	         
	        while (i < j)
	        {
	            if (!(  (str1.charAt(i) >= 'a' && str1.charAt(i) <='z') || (str1.charAt(i) >='0' && str1.charAt(i) <= '9') ))
	            {
	                i++;
	                j--;
	                continue;
	            }
	             
	            if (str1.charAt(i) == str1.charAt(j))
	            {
	                i++;
	                j--;
	                continue;
	            }
	             
	            if (str1.charAt(i) != str1.charAt(j))
	            {
	                return false;
	            }
	        }
	        return true;
	}
		
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the string : ");
		String str = sc.nextLine();
		
		System.out.print(isPalindrome(str));
		
		sc.close();
	}
}
