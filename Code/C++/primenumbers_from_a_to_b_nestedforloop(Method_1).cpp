/*
Prime till From a to b --> This is the algorithm in which we will be findind all prime numbers from a to b.
As a & b will be taken as input from the user.

The basic flow of the algorithm is :
--> Take input from the user (a,b)
--> Check each number from a to b is it prime or not
--> For this we will assign a new function 
--> The function will take two argument a,b 
--> The function will check each number from a to b is it prime or not 
--> In last we will give two ouputs 
--> 1. Total No. of prime numbers 
--> 2. Prime numbers 

In this algorithm we will take data type unsigned long long int so almost all test cases can be passed
You can change the datatype depending on the testcases you are going to pass

*/

/*
Author :- Rohan Kulkarni
Date :- 11 March 2021
*/

#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef unsigned long long int ll;
// We are using typedef function for our convinence it will not affect our algorithm just in place of writing 'long long int' we can write 'll'

// As told we are going to create a function named "Check_Prime" which is two argument function
ll Check_Prime(ll a,ll b)
{
    ll count = 0; // Initialised the count to 0;
    for (ll num = a; num <= b; num++) // Running for loop to transverse all numbers from a till b
    {
        ll i; // Initialised i before for loop because we are going to use i outside for loop 
        for (i = 2; i < num; i++) // for loop to check is the num (which is current iteration of first for loop) is divisible by  any  number from a to b
        {
            if (num % i == 0) // if the num is divisible by any single number  then it is not the prime number so we break the second for loop for current num
            { 
                //it is not prime
                break;
            }
        }
        if (i == num) // If the number is not prime then the loop must be completed and now the value of i should be equal to num 
        {
            cout << num << endl; // this will output the num which is prime number 
            count = count + 1; // THis will update the count updater 
        }
    }
    cout << "Total Prime Number from "<<a<<" to "<<b<<" are : " << count << "\n";  // This will print the total number of prime number till n
    return 0;
}



int main()
{
    
    ll a,b;   // Initialisation of N
    cout<<"Enter No. 1: "<<"\n";

    cin>>a;

    cout<<"Enter No. 2: "<<"\n";

    cin>>b;

    Check_Prime(a,b); // Called the function Check_Prime and passed the argument N

    return 0;
}

/* 
    Sample cases : You can give value of N as input till 18,446,744,073,709,551,615
/*

Test Cases :
1.

Input : 10 20
Output : 

11
13
17
19
Total Prime Number from 10 to 20 are : 4

2.

Input : 100 135
Output : 
101
103
107
109
113
127
131
Total Prime Number from 100 to 135 are : 7


*/

/*

Time Complexity :- O(N^2)

*/

/*
Space Complexity :- O(2)
*/
