/*
In this Reverse string technique ,Stack implementation is used.At first Stack is created from java.util.* package and each character(Including Spaces) of 
a string is pushed into the stack and after all the character are pushed then we start popping from the top of stack. As it follows LIFO therefore the top
of the stack contains the last character of string therefore when we pop the stack and store it in a string "S" and doing this repeatedly then string in "S"
is the reverse of the input string and we get our output.

*/
package p1;

import java.util.*;

public class Reverse {

	public static void main(String[] args) {
		
	Scanner sc=new Scanner(System.in);
		
        System.out.print("Enter a String:");
        
	String s=sc.nextLine();//Enter the string you want to reverse

        int l=s.length();//Storing the length of the string

        Stack<Character> a=new Stack<>();//Creating a stack named "a"   

        for(char ch:s.toCharArray()){			
	//adding each character to the stack																									//iterating through the string using forEach loop
            a.push(ch);        
	}
        s="";
				
        while(l-->0){
	//as pop occurs from top therefore while popping a character we add it to a string which is stored in reverse order			
            s=s+a.pop(); 					
        }		
        System.out.println("Output-"+s);         
	}
}

/* Output
1.	Enter a String: Prateek
   	Output: keetarP
	
2.	Enter a String: This is the end of world
	Output: dlrow fo dne eht si sihT
		
	Time Complexity: O(n)
	Space Complexity: O(n)
	
*/
