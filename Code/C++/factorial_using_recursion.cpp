/*  In this Problem, our objective was to find the factorial of a number n entered by the user.
    Factorial of a number n is n! = n*(n-1)*(n-2)*........*1
    Using recursion we can write factorial of n as n! = n*(n-1)!
    We used n = 0 as our base case (0! = 1), i.e.
    if(n == 0) : return 1;  
*/

#include<iostream>                      // header file required for Input/Output in the program
using namespace std;

int factorial(int n)                    // Function to calculate this factorial
{   if(n == 0)                          // Base Case if n = 0
        return 1;                       // 0! = 1
    return n*factorial(n-1);            // Multiplied the current number and recursed the factorial (n-1)
}

int main()                              // main function from where the execution of code starts
{   int n;                              // number for which we need to find factorial
    cin >> n;                           // number input by the user
    cout << factorial(n) <<endl;        // calling the factorial function created
    return 0;
}


/*  Test Case :
        Input   : 5   
        Output  : 120
        
        Input   : 5   
        Output  : 120
        
*/


/*   Time Complexity in this case is : O(N)
     Space Complexity in this case is : O(1)
*/  

