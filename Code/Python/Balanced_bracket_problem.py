# In this problem we are given a string expression as input 
# and we have to find whether the sequence of brackets in the expression
# is correct or not. 
# For Ex: ({}[])----> This Sequence is balanced.
#         [([)]}-----> This sequence is not balanced.


#This function will check if the brackets are balanced or not
def balancedBrackets(strn):
    stack = []
    
    for i in strn:
        # all opening brackets are appended in the stack
        if i in ["{", "[", "("]:
            stack.append(i)

        else:
            #if the bracket is opening then stack cannot be
            # empty is the brackets are balance
            if not stack:
                return False
            #Here c is the last appended opening bracket
            c=stack.pop()
            #if the last appended opening bracket is not a pair
            #of the current closing bracket(i) then the brackets ar not 
            #balanced.
            if c == '{':
                if i != "}":
                    return False
            if c == '(':
                if i != ")":
                    return False
            if c == '[':
                if i != "]":
                    return False
    # If after tranversing the loop the stack is empty
    # then the brackets are balanced
    if stack:
        return False
    return True   


if __name__== "__main__":
    t=int(input("Enter No of Test Cases\n"))
    while t:
        t=t-1
        str=input("Enter the expression\n")
        if balancedBrackets(str):
            print("Balanced")
        else:
            print("Not Balanced")

# TEST CASES
#  1) INPUT:
#            Enter No of Test Cases
#            1
#            Enter the expression
#            {[()]} 
#     OUTPUT:
#             Balanced
#  2) INPUT:
#            Enter No of Test Cases
#            1
#            Enter the expression
#            {{({[}])}] 
#     OUTPUT:
#             Not Balanced  
