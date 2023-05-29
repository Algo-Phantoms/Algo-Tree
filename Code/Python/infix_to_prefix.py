"""
Converting an infix expression to prefix with the help of stack.
Algorithm description-
Let us assume that S1 is our infix expression and S2 is our prefix expression.
1. Reverse S1 and convert every '(' to ')' and every ')' to '(', then enclose S1 into parenthesis
2. Scan S1 from left to right. If you encounter-
    i)An operand- Add it to S2
    ii)An operator- repeatedly pop from stack every operator that has the equal or higher precedence than the operator, and then add the operator to stack
    iii)A right parenthesis- pop from stack until you encounter a left paranthesis, remove the left parenthesis from the stack
    iv)A left parenthesis- push it on the stack
3. Reverse S2

The precedence of operators from highest to lowest is-
/ *
+ -

"""

S1=list(input("Enter the infix expression- "))    #we will convert S1 into a list for ease of traversal and reversal

#Step 1
S1.reverse()
for i in range(len(S1)):
    if S1[i] is '(':
        S1[i]=')'
    if S1[i] is ')':
        S1[i]='('
S1.insert(0,'(')
S1.insert(len(S1),')')

#Step 2
stack=[]
S2=[]

for c in S1:
    if c is '(':
        stack.append(c)
    elif c is ')':
        x=stack.pop()
        while x is not '(':
            S2.append(x)
            x=stack.pop()
    elif c is '+' or c is '-':
        x=stack.pop()
        while x in ['+', '-', '/', '*']:
            S2.append(x)
            x=stack.pop()
        else:
            stack.append(x)
        stack.append(c)
    elif c is '/' or c is '*':
        x=stack.pop()
        while x in ['/', '*']:
            S2.append(x)
            x=stack.pop()
        else:
            stack.append(x)
        stack.append(c)
    else:
        S2.append(c)

#Step 3
S2.reverse()

print("Prefix expression is {}".format("".join(S2)))

"""
Sample input and output

Example 1-
Enter the infix expression- a-b*(d+c/e)+f
Prefix expression is -a*bd/cef

Example 2-
Enter the infix expression- w+x*(y-(u+v)*z)
Prefix expression is +w*xyuvz

Time Complexity = O(n)
Space Complexity = O(n)

"""
