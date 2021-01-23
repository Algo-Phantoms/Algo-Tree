#include<iostream>
using namespace std;

int fib(int n){
	if(n==0 || n==1)
		return n;
	int ans = fib(n-1)+fib(n-2);
	return ans;
}

int main() {

	int n;
	cin >> n;
	cout<<fib(n);
	return 0;
}

/* Test case -

Input - 7
Output - 13

*/