/*
Prime till N --> This is the algorithm in which we will be findind all prime numbers from 2 to N.
As N will be taken as input from the user.

The basic flow of the algorithm is :
--> Take input from the user (N)
--> Check each number till N is it prime or not
--> For this we will assign a new function 
--> The function will take single argument N 
--> The function will check each number from 2 is it prime or not 
--> If the number is prime then it will be  added in a array else the loop will continue
--> We can use the concept of  vector also for storing array but our main objective is to find the prime numbers till n it dont matter a lot.
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

// As told we are going to create a function named "Check_Prime" which is single argument function
ll Check_Prime(ll n)
{
    ll count = 0; // Initialised the count to 0;
    for (ll num = 2; num <= n; num++) // Running for loop to transverse all numbers from 2 till N
    {
        ll i; // Initialised i before for loop because we are going to use i outside for loop 
        for (i = 2; i < num; i++) // for loop to check is the num (which is current iteration of first for loop) is divisible by  any  number till N 
        {
            if (num % i == 0) // if the num is divisible by any single number till n then it is not the prime number so we break the second for loop for current num
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
    cout << "Total Prime Number till N are : " << count << "\n";  // This will print the total number of prime number till n
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;     // Initialisation of N
    cin >> N; // Taking N as input from user

    Check_Prime(N); // Called the function Check_Prime and passed the argument N

    return 0;
}

/* 
    Sample cases : You can give value of N as input till 18,446,744,073,709,551,615
/*

Test Cases :
1.

Input : 10
Output : 
2
3
5
7
Total Prime Number till N are : 4

2.

Input : 100
Output : 
2 
3 
5 
7 
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97
Total Prime Number till N are : 25


*/

/*

Time Complexity As we are using two nested loop the time complexity of this problem is O(N^2)

*/
