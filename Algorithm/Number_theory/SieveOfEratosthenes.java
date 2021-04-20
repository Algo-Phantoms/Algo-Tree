
//        Prime Numbers(Using Sieve of Eratosthenes)

import java.util.*;
public class SieveOfEratosthenes {
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the input :");
        int n=in.nextInt();
        System.out.println("Following are the prime numbers ");    
        boolean prime[]=new boolean[n+1];
        for(int i=0;i<=n;i++)
            prime[i]=true;

        for(int p=2;p*p<=n;p++)
        {
            if(prime[p] == true)
            {
                for(int i=p*p;i<=n;i+=p)
                    prime[i] = false;
            }
        }

        for(int i=2;i<=n;i++)
        {
            if (prime[i] == true)
                System.out.print(i + " ");
        }

        in.close();
    }
}

/*
 * Test Case 1:
 * Enter the input :
   20
   Following are the prime numbers 
   2 3 5 7 11 13 17 19 

   Test Case 2 :
   Enter the input :
   10
   Following are the prime numbers 
   2 3 5 7 
 */
