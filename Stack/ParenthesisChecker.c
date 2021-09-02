/*
 * C Program to Check if Expression is correctly Parenthesized  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int top = -1;
char stack[100];
 
// function :
void push(char);
void pop();
void find_top();
 
void main()
{
	int i;
	char a[100];
	printf("enter the  expression\n");
	scanf("%s", &a);
	for (i = 0; a[i] != '\0';i++)
	{
		if (a[i] == '(')
		{
			push(a[i]);
		}
		else if (a[i] == ')')
		{
			pop();
		}
	}
	find_top();
}
 
// to push elements in stack
void push(char a)
{
	stack[top] = a;
	top++;
}
 
// to pop elements from stack
void pop()
{
	if (top == -1)
	{
		printf("expression is invalid\n");
		exit(0);
	}	
	else
	{		
		top--;
	}
}
 
// to find top element of stack
void find_top()
{
	if (top == -1)
		printf("\nexpression is valid\n");
	else
		printf("\nexpression is invalid\n");
}