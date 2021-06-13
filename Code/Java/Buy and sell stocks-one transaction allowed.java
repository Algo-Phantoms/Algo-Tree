import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);   // Taking inputs
        int n = scn.nextInt();
        int[] prices = new int[n];
        for(int i=0;i<n;i++){
            prices[i] = scn.nextInt();
        }
        Stock(n,prices);
        
    }
    public static void Stock(int n,int[] prices){
        int leastSoFar = Integer.MAX_VALUE; // Maintaing a least i.e stock when price is least
        int overallProfit=0;        // overall Profit
        int profitIfSoldToday =0;   // Amount of profit if stock is sold today
        
        for(int i=0;i<prices.length;i++){
        if(prices[i] < leastSoFar){
            leastSoFar = prices[i];
        }
        profitIfSoldToday = prices[i] - leastSoFar; // profit if sold today will be equal to price of stock on today minus least price till now when share is bought
        if(profitIfSoldToday > overallProfit){
            overallProfit = profitIfSoldToday;
        }
    }
    System.out.println(overallProfit);
    }

}
/* CONSTRAINTS */
/*
0 <= n <= 20
0 <= n1, n2, .. <= 10
*/

/*   SAMPLE INPUT   */

/*
9
11
6
7
19
4
1
6
18
4
*/

/*  SAMPLE OUTPUT*/

/*
17
*/
