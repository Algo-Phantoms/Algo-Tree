# In this problem we are given a string expression
# with string elements as "{","}","[","]","(" and ")".
# We have to tell whether the brackets are balanced or not.
# For Ex:
#           {([])} ----> this expression has balanced brackets.
#            {][])  -----> this sequence does not have balanced brackets.


# In this problem we are given a string expression
# with string elements as "{","}","[","]","(" and ")".
# We have to tell whether the brackets are balanced or not.
# For Ex:
#           {([])} ----> this expression has balanced brackets.
#            {][])  -----> this sequence does not have balanced brackets.


s=input("Enter the expression\n")

#this stack will contain all the opening brackets
stack=[]

#this flag will tell if the brackets are balanced or not
flag=0

for i in s:
    if((i == "(") or (i == "[") or (i == "{")):
        stack.append(i)
    else:
        #if stack is empty brackets are 
        #not balanced
        if not stack:
            flag=1
            break
        
        #e will contain the last opening bracket
        e=stack.pop()
        
        #if opening and closing brackets are not same 
        #the brackets are not balanced
        if(e == '{' and i != "}"):
            flag=1
            break
        if(e == '(' and i != ")"):
            flag=1
            break
        if(e == '[' and i != "]"):
            flag=1
            break

#if stack is not empty after 
#transversing whole loop then
#brackets are not balanced
if(flag==0):
    if stack:
        flag=1

if(flag==1):
    print("Brackets are not balanced")
else:
    print("Brackets are balanced")

#      TEST CASES

#    1)Input:
#            Enter the expression
#            {([])}
#     Output:
#             Brackets are balanced
#       
#
#    2)Input:
#            Enter the expression
#            {([]
#     Output:
#             Brackets are not balanced

#     Time complexity: O(n)    
#     Space complexity: O(n) , Here n is the length of the expression
#     
