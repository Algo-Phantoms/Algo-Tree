/* Factorial of a number using Recursion

    According to wikipedia,the factorial of a positive integer n, denoted by n!, is the product of all positive integers less than or equal to n.
    Given a positive integer n, we have to find the factorial of that integer according to above definition.

    Intution - We will solve this problem using Recursion. Recursion is bascically a function calling itself.
    So we will have a function named fact which will calculate the factorial of the given integer input.
    For n=0, its factorial is said to be 1 and for n=1 it is 1, so the base case will be either n=0 or n=1 and for this output will be 1.
    And if the given integer is neither of them, then we will recursively call fact function as: n*fact(n-1), where fact() is the function which returns the factorial of the given integer.
    Hence we calculate n! as n*(n-1)*(n-2)*(n-3)……..1
    Here is the implementation :-
*/

#include<bits/stdc++.h>
using namespace std;

int fact(int n) //function for calculating factorial
{
    if(n==0 || n==1) // base case
    {
        return 1;
    }
    else 
    {
        return n*fact(n-1); 
    }
}

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n; //taking the input from user
    cout<<"Factorial of the given number is : "<<fact(n)<<"\n"; //for every input n we will call function fact and print its output
    return 0;
}

/*
Testcases - 
    Input 1 -
    Enter the number : 5

    Output 1 -
    Factorial of the given number is : 120

    Input 2 -
    Enter the number : 0

    Output 2 - 
    Factorial of the given number is : 1

Time Complexity - O(n)  where n is the input
Space Complexity - O(n)

*/