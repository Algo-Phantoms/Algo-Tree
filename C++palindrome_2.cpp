//c++ program to check whether a string is a palindrome or not

/*Find the length of the string say l. Now, find the mid as mid = l / 2.
Push all the elements till mid into the stack i.e. str[0…mid-1].
If the length of the string is odd then neglect the middle character.
Till the end of the string, keep popping elements from the stack and compare
it with the current character i.e. string[i].
If there is mismatch then the string is not a palindrome. 
If all the elements match then the string is a palindrome.*/

#include<iostream>
#include <malloc.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
using namespace std;
 
char* stack; 
int top = -1; 
  
// push function 
void push(char el) 
{ 
    stack[++top] = el; 
} 
  
// pop function 
char pop() 
{ 
    return stack[top--]; 
} 
  
// Function that returns 1 
// if str is a palindrome 
int isPalindrome(char str[]) 
{ 
    int length = strlen(str); 
  
    // Allocating the memory for the stack 
    stack = (char*)malloc(length * sizeof(char)); 
  
    // Finding the mid 
    int i, mid = length / 2; 
  
    for (i = 0; i < mid; i++) { 
        push(str[i]); 
    } 
  
    // Checking if the length of the string 
    // is odd, if odd then neglect the 
    // middle character 
    if (length % 2 != 0) { 
        i++; 
    } 
  
    // While not the end of the string 
    while (str[i] != '\0') { 
        char el = pop(); 
  
        // If the characters differ then the 
        // given string is not a palindrome 
        if (el!= str[i]) 
            return 0; 
        i++; 
    } 
  
    return 1; 
} 
  
// Driver code 
int main() 
{ 
    char str[100];
	cout<<"Enter a string of your choice: "<<endl;
	cin>>str;
    if (isPalindrome(str)) { 
        cout<<"Yes"<<endl; 
    } 
    else { 
        cout<<"No"<<endl; 
    } 
  
    return 0; 
} 
/*test cases-
 1.input-"madam"
   output-Yes
 2.input-"level"
   output-Yes
 3.input-"table"
   output-No */
    
