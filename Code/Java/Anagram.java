
/*Two strings are said to be an Anagram if all the characters of a string are equal and have same frequency but arranged in different order.
The simple logic to solve is taking the two strings into a character array and sort both the arrays and again store it to the same string variable,
if both the strings are equal then one string is said to be anagram of another.
*/
package p1;

import java.util.*;
public class Anagram {

	public static void main(String[] args) {
	
		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter string 1:");
		String s=sc.next();
		System.out.println("Enter string 2:");
		String s1=sc.next();
		        
		int l1=s.length(),l2=s1.length(); // storing the length of both the strings
		
		if(l1!=l2) {
			System.out.println("OUTPUT:Two strings are not Anagram"); //if both are of unequal length then its for sure that they are not an anagram
		}
		else {
			char c1[]=s.toCharArray(),c2[]=s1.toCharArray();
			
			s="";s1="";
			Arrays.sort(c1);Arrays.sort(c2);//sorting both the array.
			
			for(char ch:c1) {
				s=s+ch;
			}
			
			for(char ch:c2) {
				s1=s1+ch;
			}
			if(s.compareTo(s1)==0) {
				System.out.println("OUTPUT:Two strings are Anagram");
			}else
				System.out.println("OUTPUT:Two strings are not Anagram");
				
		}
	}
}


/*  OUTPUT
    1. Enter string 1-prateek
	   Enter string 2-eektarp
       OUTPUT-Two strings are Anagram
    
    2. Enter string 1-abcde
       Enter string 2-cdba       
      OUTPUT-Two strings are not Anagram
      
      
      Time Complexity-O(nlog n)
      Space Complexity-O(n)    
    
    */
