/*
Factorial of a positive integer is the product of all integers smaller than or equal to n.
For e.g: n!=1*2*3....*(n-1)*n
Factorial of 0 is 1 i.e 0!=1
*/

#include<iostream>
using namespace std;

long long int factorial(int n){
 	if(n==0)
 		return 1;
 	else if(n==1)
 		return 1;
 	else
	{
		long long int ans = n*factorial(n-1);
	 	return ans;
	}
 }

int main() {
 	int n;
 	cin >> n;
 	cout<<factorial(n);
 	return 0;
 }

/* 
	Constraint: 0<=n<=20

	Test case : 1
	Input : 6
	Output : 720

	
	Test case : 2
	Input : 1
	Output : 1
	
	Test case : 3
	Input : 0
	Output : 1

*/

/*	
	Recurrence Relation:
	Base Case:  T(n)=1          , n=0
				T(n)=T(n-1) + 1 , n>0

	Time complexity(T(n)) : O(n)
	Space Complexity : O(n)

 */
