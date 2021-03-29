/*
	
	Problem Description :
		You are climbing a staircase. It takes n steps to reach the top.

		Each time you can either climb 1 or 2 steps. 
		In how many distinct ways can you climb to the top?
	Algorithm :
		Solving Using Dynamic Programming Approach.
		Sub-problem Formula of each trail : steps[i] = steps[i - 1] + steps[i - 2]
		Extra Storage Size : N + 1 array
*/


#include <iostream>
using namespace std;

long long ClimbStairs(int N) 
{
	/*
	 * Declare an array to store the steps at each stair
	 * Complexity = Theta(1)
	*/
	long long steps[N + 1];

	/*
	 * Base Case : at the first stair (steps[0]) the number of ways to get there is 1
	 * Base Case : at the second stair (steps[1]) the number of ways to get there is 2
	 * Complexity = Theta(1)
	*/
	steps[0] = 1;
	steps[1] = 2;

	/*
	 * Calculate the steps at the (i - 1)th stair according to this formula :
	 * steps[i] = steps[i - 1] + steps[i - 2]
	 * Complexity = Theta(n)
	*/
	for(int i = 2; i < N; i++)			
	    steps[i] = steps[i - 1] + steps[i - 2];

	/*
	 * Return the steps at the final stair.
	 * Complexity = Theta(1)
	*/
	return steps[N - 1];
}

int main() 
{

	int n;
	cout << "Enter the number of stairs to calculate the number of ways to get to it's top :\t";
	cin >> n;

	if(n > 0)
	 	cout << "The number of distinct ways can you climb to the top :\t" << ClimbStairs(n) << endl; 
	else
		cout << "The number of stairs must be greater than 0." <<endl;


  return 0;
}

/*
	Time Complexity 
		Theta(N), Where N is the input number (the number of stairs).
*/

/*
	Space Complexity 
		O(N), Where N is the input number (the number of stairs).
*/

/*
	Test Cases

		1. 	Input : 5
			Output : 8

		2. 	Input : 1
			Output : 1

		3. 	Input : 10
			Output : 89

		4. 	Input : 1000
			Output : 9079565065540428013	

*/
