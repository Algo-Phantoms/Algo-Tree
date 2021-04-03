/*
PROBLEM STATEMENT:
Given a string, print its reverse.
*/

#include<bits/stdc++.h>
using namespace std;

//Driver function
int main(){
	string str;
	getline(cin, str);	//Taking input using getline() to include whitespaces
	reverse(str.begin(), str.end());	//In-built function to reverse a string
	cout<<str;	//Printing reversed string
	return 0;
}

/*
TEST CASES:
1.
Input: Hello World
Output: dlroW olleH

2.
Input: What is your    name???
Output: ???eman    ruoy si tahW

TIME COMPLEXITY: O(n), time complexity of reverse function is O(n), where 'n' denotes the length of the string.
SPACE COMPLEXITY: O(1), no extra space used
*/
