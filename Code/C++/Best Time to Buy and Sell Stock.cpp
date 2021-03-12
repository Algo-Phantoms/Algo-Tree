#include <bits/stdc++.h>
using namespace std;
 
/*Function to calculate the maximum profit 
one can get by buying stocks*/
int calcProfit(int price[], int begin, int end)
{
 
    // If the stocks can't be bought
    if (end <= begin)
        return 0;
 
    // profit intialized to 0
    int profit = 0;
 
    // Buying days of the stocks
    for (int i = begin; i < end; i++) {
 
        // Selling day of the stocks
        for (int j = i + 1; j <= end; j++) {
 
            // Checking if byuing the stock at ith day and
            // selling it at jth day is profitable or not
            if (price[j] > price[i]) {
 
                // current profit updated
                int curr_profit = price[j] - price[i]
                                  + calcProfit(price, begin, i - 1)
                                  + calcProfit(price, j + 1, end);
 
                // new profit updated
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}
 
// Driver code
int main()
{
    cout<<"Enter number of days : ";
    int days;
    cin>>days;
    int price[days];
    cout<<"Enter the prices of each of the days :";
    for(int i=0 ; i<days ; i++)
      cin>>price[i];
    cout<<"The Maximum profit is" << calcProfit(price, 0, days - 1);
    return 0;
}
/*
Test case 1:
Enter number of days : 7
Enter the prices of each of the days :455 433 231 434 657 890 900
The Maximum profit is 669
*/
