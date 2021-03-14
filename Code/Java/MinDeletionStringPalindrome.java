import java.util.*;
/*
Problem:-Remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.
A palindrome number may be a number that's same after reverse
For example 121, 131, 454, 343 are the palindrome numbers. It can   also be a string like NITIN  etc.
*/
class MinDeletionStringPalindrome
{
	public static void main(String[] args)
	{   Scanner sc=new Scanner(System.in);
		String obj=sc.nextLine();
		int n = obj.length();

		System.out.print(minDeletions(obj, 0, n - 1));
	}
	public static int minDeletions(String obj, int i, int j)
	{   //base condition
		if (i >= j) {
			return 0;
		}
		//last character of the string same as first character of the string
		if (obj.charAt(i) == obj.charAt(j)) {
			int minDeletions = minDeletions(obj, i + 1, j - 1);
			return minDeletions;
		}
        // if last character of the string different from first character of the string
		// ->remove last character
		// ->remove first character
		// ->return 1 + min of two values
		int min = Math.min(minDeletions(obj, i, j - 1), minDeletions(obj, i + 1, j));
		return 1 + min;
	}

	
}

/*
Test Case:-1
OPENGENUS
6

Test Case:-2
ABBABBC
2
* Time Complexity: O(2^n)
* Space Complexity: O(n)
*/
