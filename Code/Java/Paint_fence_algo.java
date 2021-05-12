/*

 In this problem given a fence with n posts and k colors we have to find out the 
 number of ways of painting the fence such that atmost 2 adjacent posts have the 
 same color.
 For Ex:
         If  number of posts=3
             number of colors=3(red,green,blue)
         We can paint in 24 ways such that more than two consectutive fences do not have the
         same color.
         
*/

import java.util.*;
import java.lang.*;
import java.io.*;

 class painting_fence
 {
 	public static void main (String[] args) throws java.lang.Exception
 	{
        //TAKING INPUT
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter the number of posts:\n");
        int n=scn.nextInt();
        System.out.println("Enter the number of colors:\n");
        int k=scn.nextInt();
        
        /*
        Here same variable will store the number of ways in which i posts can be colored 
        such that the color of last two posts is same.
        
        The diff variable will store the number of ways in which i posts can be coloured with 
        last two posts of different color.
        
        The tot variable conatains sum of all ways.
        */
        long same,diff,tot;
        same=k;
        diff=k*(k-1);
        tot=same+diff;
        for(int i=3;i<=n;i++)
        {
            same=diff;
            diff=tot*(k-1);
          //We use mod 10^9 +7 so that if we get large values we can handle them
            tot=(same+diff)%1000000007;
        }
        
        //OUTPUT
        System.out.println("The number of ways of painting this fence is:"+tot); 
 	}
 }
 /*
    
    TEST CASES
 
    1)  INPUT:
            Enter the number of posts:
            9
            Enter the number of colors:
            3
            
      OUTPUT:
            10032
   
    1)  INPUT:
            Enter the number of posts:
            11
            Enter the number of colors:
            5
            
      OUTPUT:
            35481600
 
 
 
 Time complexity - O(n)
 Space complexity - O(n), where n is the number of posts
 */
