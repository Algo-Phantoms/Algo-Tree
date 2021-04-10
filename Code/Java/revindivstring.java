/*
Here we will take input of String and then we will find index of space occured in
String, then upto that index we will reverse word & will add in temp String using
Concatenation & at last will reverse last word & hence will return the string temp
*/

package com;
import java.util.Scanner;

public class revindivstring {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Sentence : ");
        //Taking Input of String
	String txt = scan.nextLine();
	//String with Reversed Words Result Output
        System.out.println(RevIndivString(txt));
    }
    public static String RevIndivString(String txt){
        //Creating an Empty String to which the Reversed Words will be Concatenated
	String temp = "";
        int carry = 0;
        for (int i = 0;i<txt.length();i++){
        //Finding Last Index of Word    
	if (txt.charAt(i) == ' '){
		//Concatenating from 1 index behind space upto previous Carry
		//which forms a complete word
                for (int j = i-1;j>=carry;j--){
                    temp += txt.charAt(j);
                }
		//Adding Space for Next Reversed Word
                temp += ' ';
		// Carrying Starting Index of Next Word
                carry = i+1;
            }

        }
	//Concatenation Last Word in Reversed Order to String temp 
        for (int i = txt.length()-1;i>=carry;i--){
            temp += txt.charAt(i);
        }
        return temp;
    }
}
/*
    Test Cases:
        Input: He is Good
        Output: eH si dooG

        Input: I am krishna-NIT
        Output: I ma TIN-anhsirk

        Time Complexity: O(n)
        Space Complexity: O(1)


 */