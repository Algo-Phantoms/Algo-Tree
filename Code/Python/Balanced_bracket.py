'''

A sequence of brackets is balanced if it satisfies the following two conditions:
    1. The total number of opening brackets should be equal to the total number of closing brackets.
    2. A closing bracket should be of the same type as the latest open bracket.
Approach:
  Traverse through the sequence of brackets.
  If an opening bracket is found then push it into a stack.
  If a closing bracket is found,
                                If the stack is empty, the sequence is unbalanced.
                                Else,
                                    If the bracket type at the top of the stack is same as the current bracket, pop() the the stack.
                                    Else, the sequence is unbalanced.
  After the complete traversal if the stack is empty, the sequence is balanced, otherwise, it is an UnBalanced sequence of brackets.

The following code checks if a sequence of brackets taken as input is balanced.
'''
    # The following method takes a sequence of brackets 's' as an input parameter
    # The method returns 'Balanced' if 's' is a balanced sequence, otherwise 'Unbalanced' is returned
def check(s):
    open_brackets = ["[","{","("]
    close_brackets = ["]","}",")"]
    stack = []
    for i in s:
        if i in open_brackets:
            stack.append(i)
        elif i in close_brackets:
            pos = close_brackets.index(i)
            if ((len(stack) > 0) and (open_brackets[pos] == stack[len(stack)-1])):
                stack.pop()
            else:
                return "Unbalanced"
    if len(stack) == 0:
        return "Balanced"
    else:
        return "Unbalanced"

    # Driver Code: Takes user input and prints the output
sequence=input()
print(check(sequence))


'''
Sample Test Cases :
    Input 1:
    (()))
    Output 1:
    Unbalanced

    Input 2:
    {}{}
    Output 2:
    Balanced

    Input 3:
    ({)}
    Output 3:
    UnBalanced
'''
    # Time Complexity: O(N)
    # Space Complexity: O(N) (for auxillary stack used)
