//Conversion from infix expression to postfix expression (Application of Stack)

#include<bits/stdc++.h> 
using namespace std; 
  
// Function to check if the given character is operand 
int isOperand(char token)
{
	return (token>='a' && token<='z')||(token>='A' && token<='Z');
}

// Function to check precedence of operator
int precedence(char op)
{
	if (op=='+' || op=='-')
	return 1;
	else if (op=='*' || op=='/')
	return 2;
	else if (op=='^')
	return 3;
	return -1;
}
  
//Driver program to test above functions
int main() 
{ 
    int k=0, brac=0;
    string infix;
    cin >> infix;
    stack<char> stk;
    for(int i = 0; i < infix.length(); i++) 
    {          
        // If operand affects string 
        if (isOperand(infix[i])){
			infix[k++] = infix[i];
		}
  
        // If ‘(‘, push to stack. 
        else if(infix[i] == '('){
            stk.push('('); 
            brac++;
        }
        // If ‘)’, pop until an ‘(‘ is encountered. 
        else if(infix[i] == ')') 
        { 
            while(!stk.empty() && stk.top() != '(') 
            { 
                char c = stk.top(); 
                stk.pop(); 
                infix[k++] = c; 
            } 
            if(stk.top() == '(') 
            { 
                char c = stk.top(); 
                stk.pop(); 
                brac++;
            }
        } 
          
        //Else check precedence of operator 
        else{ 
            while(!stk.empty() && precedence(infix[i]) <= precedence(stk.top())) 
            { 
                char c = stk.top();
                stk.pop();
                infix[k++] = c;
            } 
            stk.push(infix[i]);
        }
    } 

    // Pop all the remaining elements from the stack 
    while(!stk.empty()) 
    { 
        char c = stk.top(); 
        stk.pop();
        infix[k++] = c; 
    } 
      
	for (int i = 0; i < infix.length() - brac; i++){
		cout << infix[i];
    }
    return 0; 
} 


/*
Sample Input:   a+b*c-d^e/(f+g)*h
Std Output:  abc*+de^fg+/h*-

Sample Input:  a+b*c-d^e*(z^x/y+n)/(f+g)*h
Std Output: abc*+de^zx^y/n+*fg+/h*-
*/
