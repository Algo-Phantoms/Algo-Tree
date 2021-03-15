/*
problem statement :
Given a number n, display the Fibonacci sequence of first n numbers

The Fibonacci sequence is a series where the next term is the sum of pervious two terms. The first two terms of the Fibonacci sequence is 0 followed by 1.
The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21....

Approach : The sequence F(n) of Fibonacci numbers is defined by the recurrence relation

F(n) = F(n - 1) + F(n - 2)
with seed values ,

F(0) = 0 and F(1) = 1.

for the n = 4 , the recursive tree would be ,

               fib(4)
            /        \
         fib(3)      fib(2)
        /    \       /    \
  fib(2)   fib(1)  fib(1) fib(0)
  /     \
fib(1) fib(0)

*/

// code part (Method 1 : using recursion)


#include<bits/stdc++.h>
using namespace std;

//Fibonacci Series using Recursion

int fib(int n)
{
	// base case : if n == 0 ,then return 0 and if n == 1 , then return 1
	if(n <= 1)
	{
		return n;
	}

	// recursive call
	return fib(n - 1) + fib(n - 2);

}
int main()
{
	int n;

	cout << "Enter the number of elements:";

	cin >> n;

// printing the fibonacci sequence

	for(int i = 0 ; i < n; i++)
	{
		cout << fib(i) << " ";

	}

	cout << endl;

	return 0;
}

// code part (Method 2 : using dynamic programming)

#include<bits/stdc++.h>
using namespace std;

// Fibonacci series using dynamic progarmming

void fib(int n) {

// let's make an array to store our computed results
	int dp[n];


	dp[0] = 0;

	dp[1] = 1;

// calculating the remaining values

	for (int i = 2; i < n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

// displaying the fibonacci series

	for (int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
	}
}

int main()
{
	int n;

	cout << "Enter the number of elements:";

	cin >> n;

    fib(n);

	return 0;
}


/*
(For method 1)

// Time Complexity : T(n) = T(n-1) + T(n-2) which is exponential.
// Space complexity : O(n) , if we consider stack space in recursive calls


*/

/*

(For method 2)

// Time Complexity : O(n)
// Space Complexity : O(1)

*/
/*
Sample test cases


Enter the number of elements: 7
0 1 1 2 3 5 8

Enter the number of elements: 10
0 1 1 2 3 5 8 13 21 34


*/