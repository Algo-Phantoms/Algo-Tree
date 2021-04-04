/*Reverse string
Problem Statement:  Reverse the given string from user.
                    For e.g initial string: Hello, reversed string: olleH
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class StringReverse{
    // function for reversing the given string
	public static void ReverseTheString(){
	    
        Scanner sc = new Scanner(System.in); 
        String input = sc.nextLine();       //taking input string from user
        int k = input.length();                      //size of the string
        char[] output = input.toCharArray();         //converting it into array to access each Character of string
        /*using two pointer type approach to swap the characters of string 
        one pointer points to starting and other to ending*/
        for(int itr = 0, ptr = k-1; itr < ptr; itr++, ptr--){
            char flag = output[itr];                //swapping the characters
            output[itr] = output[ptr];
            output[ptr] = flag;
        }

        System.out.print("Reversed string: ");
        // printing the reversed string
        for(int itr = 0; itr < k; itr++){
            System.out.print(output[itr]);
        }
    }

    public static void main (String[] args) throws java.lang.Exception{
        ReverseTheString();         //calling for the reverse function from main
    }
}

/*
Test Case 1:
Input -
towerofhanoi
Output -
Reversed string: ionahforewot

Test Case 2:
Input -
reversemalayalam
Output -
Reversed string: malayalamesrever

Time Complexity: O(k), for traversing the array of characters
Space Complexity: O(1), no extra space is used
*/