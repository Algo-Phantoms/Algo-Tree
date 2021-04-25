/*
Two strings are said to be an Anagram if all the characters of a string are equal and have same frequency but arranged in different order.
The simple logic to solve is taking the two strings into a character array and sort both the arrays and again store it to the same string variable,
if both the strings are equal then one string is said to be anagram of another.
*/
package p1;

import java.util.*;
public class Anagram {

	public static void main(String[] args) {
	
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter string 1: ");
		String s = sc.next();
		System.out.println("Enter string 2: ");
		String s1 = sc.next();
		 // storing the length of both the strings       
		int l1 = s.length(),l2 = s1.length(); 
		
		if(l1!=l2) {
			//if both are of unequal length then its for sure that they are not an anagram
			System.out.println("Two strings are not Anagram"); 
		}
		else {
			char c1[] = s.toCharArray(),c2[] = s1.toCharArray();
			
			s = ""; s1 = "";
			//sorting both the array.
			Arrays.sort(c1);Arrays.sort(c2);
			
			for(char ch:c1) {
				s = s + ch;
			}
			
			for(char ch:c2) {
				s1 = s1 + ch;
			}
			if(s.compareTo(s1)==0) {
				System.out.println("Two strings are Anagram");
			}else
				System.out.println("Two strings are not Anagram");
				
		}
	}
}


/* 
Test Cases
1.	     
INPUT: 
Enter string 1: prateek
Enter string 2: eektarp
OUTPUT:
Two strings are Anagram

2.
INPUT:
Enter string 1: abcde
Enter string 2: cdba       
OUTPUT:
Two strings are not Anagram
      
      
Time Complexity-O(nlog n)
Space Complexity-O(n) 
where n: number of characters in string
    
    */
