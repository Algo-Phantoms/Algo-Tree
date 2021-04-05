//Given a number n find the smallest number evenly divisible by each number 1 to n.
import java.util.Scanner;

class Smallest_divisble_number
{
	static long gcd(long a, long b)
	{
	if(a%b != 0)
		return gcd(b,a%b);
	else
		return b;
	}

// Function returns the lcm of first n numbers
	static long lcm(long n)
	{
		long ans = 1;
		for (long i = 1; i <= n; i++)
			ans = (ans * i)/(gcd(ans, i));
		return ans;
	}

// Driver program to test the above function
	public static void main(String []args)
	{
		long n;
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter the number: ");
	    // This method reads the number provided using keyboard
	    n = scan.nextInt();
		System.out.println("Smallest number divisible is: "+lcm(n));

	}
}

/*
##Example :
1.Input : Enter the number: 4
  Output: 12
Explanation : 12 is the smallest numbers divisible by all numbers from 1 to 4
2.Input : Enter the number: 6
  Output: 60
##Time Complexity:O(nlogn)
##Space Complexity:O(1)								 
*/

