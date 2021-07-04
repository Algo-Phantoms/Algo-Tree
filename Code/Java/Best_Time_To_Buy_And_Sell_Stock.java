/* Best Time to Buy and Sell Stock
The cost of a stock on each day is given in an array where prices[i] is the price of a given stock on the ith day.
We want to maximize our profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit one can achieve from this transaction. If you cannot achieve any profit, return 0.

Approach: The idea is to find the minimum element in the array and subtract with all elements in the array and find the maximum value.
*/

import java.io.*;
import java.util.*;

public class BuyStock {
     
    public static int maxProfit(int[] prices)
      {
        int n = prices.length;
	int cost = 0;
	int maxCost = 0;

	  if (n == 0) 
              {
	     return 0;
	      }

	// store the first element of array in a variable

	 int min_price = prices[0];

	for (int i = 0; i < n; i++) {

	// now compare first element with all the
	// element of array and find the minimum element

		min_price = Math.min(min_price, prices[i]);

		// since min_price is smallest element of the
		// array so subtract with every element of the
		// array and return the maxCost

		cost = prices[i] - min_price;

		maxCost = Math.max(maxCost, cost);
		}
		return maxCost;
	}

	// Driver Code
	public static void main(String[] args)
	{
                Scanner sc=new Scanner(System.in);
                //length of price array
                int l=sc.nextInt();
		// stock prices on consecutive days
                int prices[]=new int[l];
		for(int i=0;i<l;i++)
                  {
                   prices[i]=sc.nextInt();
                  }
		System.out.print(maxProfit(prices));
	}
   }

/*
Test Cases:
Input: prices = [7,1,5,3,6,4]
Output: 5

Input: prices = [7,6,4,3,1]
Output: 0

Time Complexity: O(n)
Space complexity: O(1)
*/
