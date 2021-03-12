/* 
Given a string,print reverse of the string using stack

Approach:-

	In stack,we know LIFO principle works.
	
	First,i create an empty stack,then i push each character of string in stack
	then,from for loop i popped out every single character.

*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;
void reverse(string &s)
{
	int i;
	stack<int> str;
	for(char ch:s)
	{
        str.push(ch);
    }
    for(i=0;i<s.size();i++)
    {
        s[i]=str.top();
        str.pop();
    } 
}
int main()
{
	cout<<"Program to reverse a string."<<endl;
	string s;
	cout<<"Enter a string you want to reverse:";
	cin>>s;
	reverse(s);
	cout<<s;
	return 0;
}

/*
	Test Case :
	
	1.
	  Input : Rahul
	  Output : luhaR
	
	2.
	  Input : Sajal
	  Output : lajaS
	
	Time Complexity : O(n), where n is the length of the input string.
	Space Complexity : O(n) for stack.
*/
