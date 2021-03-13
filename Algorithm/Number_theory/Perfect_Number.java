//Program to check if the given number is a perfect number or not.

import java.util.*;
public class Main
{
  public static void main (String[]args)
  {

    int n, sum = 0;

      n = new Scanner (System.in).nextInt();
    // Find all divisors and add them
    for (int i=1; i<n; i++)

      {

	if (n % i == 0)

	  {

	    sum += i;

	  }

      }
    // If sum of divisors is equal to n, then it is confirmed that n is a perfect number.
    if (sum == n)

      {

	System.out.println (n +" is a perfect number.");

      }

    else

      {

	System.out.println (n + " is NOT A perfect number.");

      }
   }
}
