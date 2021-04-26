/* Check for Palindrome Number */
/* To check whether the number is palindrome or not ,  
 * check if the number read backwards is equal to the original number if equal then,
 *  it will be considered to be a palindrome number else it is not a palindrome number.*/

/* Algorithm :
Step 1:Get the number to check for palindrome
Step 2: Hold the number in temporary variable (temp)
Step 3: Reverse the number
Step 4: Compare the temporary number with reversed number
Step 5: If both numbers are same, return true
Step 6: Else return false */

package palin;
import java.util.*;
class P
{
	boolean Panlindrome (int n)
	{
		int rem=0;  //for remainder
		int sum=0;  
		int temp=0;
		temp=n;   //assign n to temp
		while(n>0){  //loop until n is greater than 0
			rem= n % 10;   //extract the remainder to get the last digit
			sum = (sum*10)+rem; 
			n = n/10;   //divide the number by 10
		}
		if(sum==temp) {   //original number is equal to reversed number 
			return true;  //true if number is a palindrome
		}
		else 
		{
			return false; //false if number is not a palindrom
		}
	}
}
public class Pmain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		boolean result; 
		int n1=0;
		P pa = new P();  //create object of class P
		System.out.println("-------To check whether a number is palindrome or not-------");
		System.out.println("Enter a number: ");
		n1 = sc.nextInt();
		System.out.println("Input: "+n1);
		result= pa.Panlindrome(n1);
		System.out.println("Output: "+result);
	}
}
/*The time complexity to check if a number is a palindrome or not is  O(log10​(n)), n is the number
 * Because we are dividing the number by 10 in every iteration. 
 * So the time complexity can be said is equal to the number of digits in a number.*/

/* Test case 1: 
-------To check whether a number is palindrome or not------- 
Enter a number: 
124
Input: 124
Output: false

Test case 2:
-------To check whether a number is palindrome or not-------
Enter a number: 
656
Input: 656
Output: true
*/

