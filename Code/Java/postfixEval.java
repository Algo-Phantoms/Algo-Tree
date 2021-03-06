/*
A postfix expression is a collection of operators and operands in which the operator is placed after the operands.
That means, in a postfix expression the operator follows the operands.

Postfix expression:
5 3 + 8 2 - *
Postfix evaluation:
48

*/

import java.util.*;
public class postfixEval {
   // Function to evaluate a given postfix expression
    public static int evaluatePostfix(String exp)
    {
        // create an empty stack
        Stack<Integer> stack = new Stack<>();
 
        // traverse the given expression
        for (char c: exp.toCharArray())
        {
            // if the current character is an operand, push it into the stack
            if (Character.isDigit(c)) {
                stack.push(c - '0');
            }
            // if the current character is an operator
            else {
                // remove the top two elements from the stack
                int x = stack.pop();
                int y = stack.pop();
 
                // evaluate the expression `x op y`, and push the
                // result back to the stack
                if (c == '+') {
                    stack.push(y + x);
                }
                else if (c == '-') {
                    stack.push(y - x);
                }
                else if (c == '×') {
                    stack.push(y * x);
                }
                else if (c == '/') {
                    stack.push(y / x);
                }
            }
        }
 
        // At this point, the stack is left with only one element, i.e.,
        // expression result
        return stack.pop();
    }
 
    public static void main(String[] args)
    {
        String exp = "138*+";
        System.out.println(evaluatePostfix(exp));
    }
}

/*
Test Cases:
    Input: 138*+
    Output: 25

    Input: 545*+5/ 
    Output: 1

    Time Complexity: O(n)
    Space Complexity: O(n)
*/
