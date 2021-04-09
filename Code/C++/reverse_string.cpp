/*
PROBLEM STATEMENT:
Given a string, The task is to print its reverse. The approach is to traverse half of the string and swapping each character with a subsequent character present 
in the other half of the string. For example, if the given string is "computer" then, we'll traverse the string till 'p' and swapping will be performed in the following way:
c with r
o with e
m with t
p with u
At the end, we'll get "retupmoc", which is the required answer.
We can also reverse a string using a predefined function of STL in CPP i.e., std::reverse()
SYNTAX: reverse(str.begin(), str.end());
*/

#include<bits/stdc++.h>
using namespace std;

//A function to reverse a string and print it
void revstr(string str){
	//size() is used to find the length of the string
	int len = str.size();
	//Traversing half of the string
	for(int i = 0; i < len/2; i++){
		//swapping 
		swap(str[i], str[len - 1 - i]);
	}
	//Printing reversed string
	cout<<str;
}

int main(){
	string str;
	//Taking input using getline() to include whitespaces
	getline(cin, str);
	//A function call to reverse a string
	revstr(str);
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

TIME COMPLEXITY: O(n), due to one for loop used for traversing the string, where 'n' denotes the length of the string.
SPACE COMPLEXITY: O(1), no extra space used
*/
