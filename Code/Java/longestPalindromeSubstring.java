/*Aim: To print Longest Palindromic Substring of input string str in java
Approach: The outer two loops pick all substrings one by one by fixing the corner characters
Then palindrome function is called for each substring and it checks if its is Palindrome or not 
then if case check if s is palindrome and greater than maxlength then it overwrites maxLength
and at last print max Length substring.*/
import java.util.Scanner;
public class longestPalindromeSubstring {    
    public static boolean palindrome(String str){
        int i = 0,j = str.length()-1;
        while(i < j){
            if(str.charAt(i++) != str.charAt(j--))
               return false;
        }
        return true;
    }
    public static void print(String str, int low, int high){
        for (int i = low; i <= high; ++i)
        System.out.print(str.charAt(i));
    }
    public static void longestPalindromeSubstring(String str){
        int n = str.length();
        int maxLength = 1, start = 0;
        for(int i = 0; i < str.length(); i++){
            for(int j = i; j < str.length();j++){
	    	    String s = str.substring(i,j+1);
	    	    if(palindrome(s) && (j - i + 1) > maxLength) {
                    start = i;
                    maxLength = j - i + 1;
	    	    }
	    	  }
        }
        print(str, start, start + maxLength - 1);
    }
	public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
		String str = scn.next();
        longestPalindromeSubstring(str);
	}
}
/* Time Complexity : O(3n)
Space Complexity : O(1)
Test Cases
Test Case 1 :
input = babad
output = bab
Test Case 2 :
input = cbbd
output = bb
Test Case 3 :
input = aaaabbaa
output = aabbaa */
