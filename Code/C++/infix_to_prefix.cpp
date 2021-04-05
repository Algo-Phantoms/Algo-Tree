  
/*
Given an infix expression, the aim is to convert it into prefix expression.
In order to do this, we first reverse the expression, and find it's postfix expression.
(Postfix expression can be found with the help of an operator stack, and precedence of operators)
The reverse of this resulting expression gives us the final infix expression.
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int precedence(char ch) {
    /* gives the precedence of operators */
    switch(ch) {
        case '+':
        case '-': return 1;
        case '/': 
        case '*': return 2;
        case '^': return 3;
        case ')': return 4;
    }
    return -1;
}

stack <char> infToPost(string infixExp) {
    /* To reverse a given infix expression and convert to postfix expression */
    int index = 0;
    int contains = 0; 
    /* using a variable to see if the operator stack contains a '(' at any time */
    int len = infixExp.length();
    stack <char> operatorStack;
    stack <char> postfixExp;

    /* converting the reverse of given expression into postfix */
    for ( index = len - 1; index >= 0; index --) { 
        char ch = infixExp[index];
        if ( isspace(ch)) {
            continue;
        }
        if ( isalnum(ch) ) { 
            /* if its an operand */
                postfixExp.push(ch);
                postfixExp.push(' ');
        }
        else { 
            /* if its an operator */
            if (ch == ')' ) {
                operatorStack.push(ch);
                contains += 1;
            }
            else if (operatorStack.empty()) {
                operatorStack.push(ch);
            }
            else if ( ch == '(') { 
                /* if the current character is '(', we empty the stack until we encounter ')' */
                while ( operatorStack.top() != ')'){
                    postfixExp.push(operatorStack.top());
                    operatorStack.pop();
                    postfixExp.push(' ');
                }
                operatorStack.pop();
                contains -= 1;
            }
            else if ( (precedence( operatorStack.top()) <= precedence(ch)) || contains  ) { 
                /* comparing the preceedence */
                operatorStack.push(ch);
            }
            else {
                while (precedence( operatorStack.top()) > precedence(ch)) { 
                    /* comparing the preceedence */
                    postfixExp.push(operatorStack.top());
                    operatorStack.pop();
                    postfixExp.push(' ');
                    if (operatorStack.empty()) {
                        break;
                    }
                }
                operatorStack.push(ch);
            }    
        }
    }
    while ( !operatorStack.empty()) {
        postfixExp.push(operatorStack.top());
        operatorStack.pop();
        postfixExp.push(' ');
    }
    return postfixExp;
}

void displayInReverse(stack <char> rev) {
    /* to display the stack in reverse order */
    while (!rev.empty()) {
        cout << rev.top();
        rev.pop();
    }
    cout << endl;
}

void infToPre(string infixExp) {
    /* converts a given infix expression to infix expression */
    stack <char> postfixExp = infToPost(infixExp);
    displayInReverse(postfixExp); /* reversing finally to get prefix of the given expression */
}

int main() {
    string infixExp;
    cout << "Enter the Infix expression:\n";
    getline(cin, infixExp);
    cout << "The Prefix expression is:" << endl;
    infToPre(infixExp);
    return 0;
}


/*
Sample Input: (A + B) * (C + D)
Sample Output:  * + A B + C D

Sample Input2: a * b + c * d
Sample Output2:  + * a b * c d
*/
