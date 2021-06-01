/*
Reverse a string using 2 pointer Approach

Problem Statement:  Reverse the given string from user.
                    For e.g initial string: hello, reversed string: olleh.
		    Using two pointer approach, firstly 'h' and 'o' are swapped similarly other characters follow the same sequence.
		    In this way, the string is reversed without using extra space.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class reverse_string{
	
   	// function for reversing the given string
	public static void ReverseTheString(){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();       
        int k = input.length();
	//converting it into array to access each Character of string
        char[] output = input.toCharArray();        
		
        //using two pointer type approach to swap the characters of string 
        //one pointer points to starting and other to ending
        for(int itr = 0, ptr = k-1; itr < ptr; itr++, ptr--){
            char flag = output[itr];                
            output[itr] = output[ptr];
            output[ptr] = flag;
        }
		
        System.out.print("Reversed string: ");
        for(int itr = 0; itr < k; itr++){
            System.out.print(output[itr]);
        }
    }

    public static void main (String[] args) throws java.lang.Exception{
	    //calling for the reverse function from main
	    ReverseTheString(); 
    }
}

/*
Test Cases:
1.
Input -
towerofhanoi
Output -
Reversed string: ionahforewot

2.
Input -
reversemalayalam
Output -
Reversed string: malayalamesrever

Time Complexity: O(k), for traversing the array of characters where 'k' is the size of input string
Space Complexity: O(1), no extra space is used
*/
