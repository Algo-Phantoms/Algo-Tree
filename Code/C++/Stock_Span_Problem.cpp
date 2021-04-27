/*
Stock Span Problem
=======================================
You are given the price of a stock for N consecutive days 
and are required to find the span of stock's price on ith day. 
The span of a stock's price on a given day i, is the maximum
consecutive days before the (i+1)th day, for which the stock's 
price is less than equal to that on the ith day.

The stock span problem is a financial problem where we have a 
series of n daily price quotes for a stock and we need to calculate 
the span of stock’s price for all n days. The span Si of the stock’s 
price on a given day i is defined as the maximum number of consecutive 
days just before the given day, for which the price of the stock on 
the current day is less than or equal to its price on the given day.
========================================
*/

#include<iostream>
#include<stack>
using namespace std;

int main() {

    // n : Total number of days
    int n; cin >> n;
    int price[n];
    int span[n];

    // Input price for n days
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    // Stack for keeping track of span of largest element till now
    stack<pair<int, int>> s;
    // Push first element in the stack
    s.push({1, price[0]});
    // Span for first day will always be 1
    span[0] = 1;

    // Looping through rest of the days
    for (int i = 1; i < n; i++) {
        // Initally the curr span of a day will be 1, i.e, itself
        int currSpan = 1;
        int currPrice = price[i];

        // Taking the topmost element in the stack
        // p : Temporary Variable used to store topmost element of Stack 's'.
        auto p = s.top();
        int topSpan = p.first;
        int topPrice = p.second;

        // While we have elements in the stack and currPrice is greater than equal to topPrice
        // keeping popping out elements and update the currSpan
        while (s.size() && topPrice <= currPrice) {

            // Update currSpan
            currSpan += topSpan;

            // Pop out the topmost element as its price was less than currPrice
            s.pop();

            // Update top element after popping
            if (s.size()) {
                p = s.top();
                topSpan = p.first;
                topPrice = p.second;
            } else {
                // Stack is empty
                break;
            }
        }

        // Finally update ans
        span[i] = currSpan;
        // Push curr element into the stack
        s.push({currSpan, currPrice});
    }

    // Print ans
    for (int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
}

/*
------------------------
Sample Input :
5
30 35 40 38 35

Sample Output :
1 2 3 1 1
------------------------
Sample Input: 
7
100 80 60 70 60 75 85

Smaple Output:
1 1 1 2 1 4 6

Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.
------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/
