/* Check for Palindrome Number 
To check whether the number is palindrome or not ,  
check if the number read backwards is equal to the original number if equal then,
it will be considered to be a palindrome number else it is not a palindrome number.
Algorithm :
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
	boolean Palindrome (int n)
	{
		//for remainder
		int rem=0;  
		int sum=0;  
		int temp=0;
		//assign n to temp
		temp=n; 
		//loop until n is greater than 0
		while(n>0){ 
			//extract the remainder to get the last digit
			rem= n % 10;   
			sum = (sum*10)+rem; 
			//divide the number by 10
			n = n/10;   
		}
		//original number is equal to reversed number
		if(sum==temp) {
			//true if number is a palindrome
			return true;  
		}
		else 
		{
			//false if number is not a palindrome
			return false; 
		}
	}
}
public class Palindrome_number {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean result; 
		int n1=0;
		//create object of class P
		P pa = new P();  
		System.out.println("-------To check whether a number is palindrome or not-------");
		System.out.println("Enter a number: ");
		n1 = sc.nextInt();
		System.out.println("Input: "+n1);
		result= pa.Palindrome(n1);
		System.out.println("Output: "+result);
	}
}
/*Test case 1: 
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

Time Complexity: O(log10​(n)) where n is the input number
Because we are dividing the number by 10 in every iteration. 
So the time complexity can be said is equal to the number of digits in a number.
Space complexity : O(1) //As Only the number is required to be stored. 
*/

