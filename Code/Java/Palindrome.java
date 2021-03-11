import java.util.*;
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