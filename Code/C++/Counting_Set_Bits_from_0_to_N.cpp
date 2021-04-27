//C++ code for sum of the count of set bits of all numbers from 0 to N (both inclusive).
/*
         Approach
         =========
         
         1. We'll take the value of N using user input.
         2. Then we will create a sum variable initialize it with zero.
         3. We will traverse from 1 to N.
         4. Using inbuilt STL function for counting the number of set bits.
         5. We'll add in the sum variable.
         6. Finally we'll print the result.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum = 0;
    cout << "Enter the value of N :";
    cin >> n;
    for (int i = 1; i <= n; i++)
        sum += __builtin_popcount(i);
    cout << "\nSum of the count of set bits of all numbers from 0 to N :";
    cout << sum << "\n";
    return 0;
}
/*
         Time complexity : O(n)
         
         Sample Input Output
         
         Sample Input 1:
         5
         Sample Output 1:
         Enter the value of N :
         Sum of the count of set bits of all numbers from 0 to N :7
         
         Sample Input 2:
         7
         Sample Output 2:
         Enter the value of N :
         Sum of the count of set bits of all numbers from 0 to N :12
         
         Sample Input 3:
         37
         Sample Output 3:
         Enter the value of N :
         Sum of the count of set bits of all numbers from 0 to N :93


*/