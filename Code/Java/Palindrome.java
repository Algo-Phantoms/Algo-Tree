package java.palindrome;

import java.util.*;
/*
A palindrome number is a number that is same after reverse.
For example 545, 151, 34543, 343, 171, 48984 are the palindrome numbers. It can   also be a string like LOL, MADAM etc.
*/
class Palindrome
{
	public static int minDeletions(String X, int i, int j)
	{
		if (i >= j) {
			return 0;
		}
		if (X.charAt(i) == X.charAt(j)) {
			return minDeletions(X, i + 1, j - 1);
		}

		return 1 + Math.min(minDeletions(X, i, j - 1), minDeletions(X, i + 1, j));
	}

	public static void main(String[] args)
	{   Scanner sc=new Scanner(System.in);
		String X=sc.nextLine();
		int n = X.length();

		System.out.print(minDeletions(X, 0, n - 1));
	}
}

/*
Test Case:-1
OPENGENUS
6

Test Case:-2
ABBABBC
2

*/
