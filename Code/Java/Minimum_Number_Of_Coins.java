
/*Approach
 * 
 * After taking inputs , Consider a 2d matrix with number of rows equals (number of elements in "coins" +1) 
 *                                            and number of columns equals (given "sum"+1)
 *  Each block with index i and j represent minimum of coins required to give sum j using coins from coins[0] to coins[i]
 *  
 *  for first column number of coins which give sum "0" is 0 . 
 *  for first row number of coins for getting sum j is j.
 *  if coins[i] >j will required number of coins equal that is required by dp[i-1][j]
 *  if else required number of coins equals dp[i][j]=Math.min(dp[i-1][j], 1+dp[i][j-coins[i]]);
 */



package gssoc;

import java.io.*;
import java.util.*;



public class Minimum_Number_Of_Coins {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();              // number of coins
		int[] coins=new int[n];           
		for(int i=0;i <coins.length; i++)
		{
			coins[i]=sc.nextInt();       // taking input of value of coins
		}
		int sum=sc.nextInt();            //taking required sum as input
		
		int[][] dp=new int[coins.length][sum+1];   //declaring a 2d array
		
		for(int i=0;i<dp.length; i++)          //for loop for rows 
		{
			for(int j=0;j<dp[0].length;j++)       //for loop for column
			{
				if(j==0) {                       //for first column for getting sum "0" Number of coins Required will be zero
					dp[i][0]=0;
				}
				else if(i==0) {                 // for first row for getting sum j number of coins required is j
					dp[i][j]=j;
				}

				else if(coins[i]>j)            // sum is less than the value of coin then the number of coins required will be same as required by getting sum using previous coins
				{
					dp[i][j]=dp[i-1][j];
				}
				
				else
				{
					dp[i][j]=Math.min(dp[i-1][j], 1+dp[i][j-coins[i]]); // number of coins required will be smaller one out of sum using previous coins or 1+coins required for getting sum -value of coin i
				}
			}
		}
		System.out.println(dp[dp.length-1][dp[0].length-1]);               // last element of dp array represent number of coins having sum ="sum" using all coins
		

	}

}

/*
 Test Case 1:
 INPUT:
 5
 1 4 7 8 5
 8
 OUTPUT:
 1
 
  Test Case 2:
  INPUT:
  6
  1 4 6 9 2 7
  8
  OUTPUT:
  2
 
 */

/* 
  Time Complexity will be O(n*sum)
         where n= number of elements in coins array and sum is the required sum
 */
