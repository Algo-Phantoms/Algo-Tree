import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] prices = new int[n];
        for(int i=0;i<n;i++){
            prices[i] = scn.nextInt();
        }
        Stock(n,prices);
        
    }
    public static void Stock(int n,int[] prices){
        int leastSoFar = Integer.MAX_VALUE;
        int overallProfit=0;
        int profitIfSoldToday =0;
        
        for(int i=0;i<prices.length;i++){
        if(prices[i] < leastSoFar){
            leastSoFar = prices[i];
        }
        profitIfSoldToday = prices[i] - leastSoFar;
        if(profitIfSoldToday > overallProfit){
            overallProfit = profitIfSoldToday;
        }
    }
    System.out.println(overallProfit);
    }

}
