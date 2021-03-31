''' 
Precedence for reference 1 being the highest
1 - Paranthesis () 
2 - Exponents (right to left)
3 - Multiplication and Division (left to right)
4 - Addition and Subtraction (left to right)

exponent associativity is right to left
2^2^3 = 2^(2^3) = 2^8 [CORRECT]
2^2^3 != 4^3 [INCORRECT]

Algorithm
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty           or the stack contains a ‘(‘ ), push it. 
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence(except for '^') than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.
'''

# set of all operators
Operators = set(['+', '-', '*', '/', '^', '(', ')']) 

# dictionary having priorities 3 being the highest
Priority = {'+':1, '-':1, '*':2, '/':2, '^':3} 

def has_higher_precedence(top, ch) :

    weight1 = Priority[top]
    weight2 = Priority[ch]
    
    if(weight1 >= weight2) :
        # as ^ operator has right to left associativity
        # we need to check if top is ^ operator
        # if ^ operator is found we cannot pop ^ as later on 
        # if ^ is found that should be given higher precedence 
        if(weight1 == weight2 and top == '^') :
            return False

        return True

    else :
        return False
 
def infix_to_postfix(expression):

    stack = [] # initially empty stack
    postfix = '' 

    for ch in expression:

        # if ch is an operand then directly  put it in postfix expression
        if ch not in Operators: 
            postfix += ch

        # opening bracket should be put in stack directly
        elif ch == '(':  
            stack.append('(')

        # closing backet
        elif ch == ')':

            # add all items of stack to postfix while stack is not empty
            # until opening bracket is found at top i.e. last index
            while stack and stack[-1] != '(':
                postfix += stack.pop()

            # pop opening bracket from the stack
            stack.pop()

        else:

            # if ch operator has lower or equal priority than top element 
            # pop the ones with higher or equal priority  
            # and put it in postfix
            while stack and stack[-1] != '(' and has_higher_precedence(stack[-1], ch) :
                postfix += stack.pop()

            # add ch operator to stack
            stack.append(ch)

    # empty all the operators from stack at the end
    while stack:
        postfix += stack.pop()

    return postfix


#driver code
expression = input('Enter infix expression: ')
print('Postfix expression is: ', infix_to_postfix(expression))
print(' ')

''' 
Test Case
Input - A+B*C-D/E*H
Output - ABC*+DE/H*-

Input - (A+B)*C^D^E/(F-G)*H
Output - AB+CDE^^*FG-/H* 
         
n = number of characters of string including operands and operators
Time Complexity: O(n)
since the time for push and pop operations are considered constant

Space Complexity: O(n)
'''
