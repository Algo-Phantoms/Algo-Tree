'''
The Postfix notation is used to represent algebraic expressions.
Using stack, we can easily evaluate postfix expression there will be only two scenarios. We have to scan string from left to right. If we encounter operator while we are scanning the string then we will pop two elements from the stack and perform the operation of current operator and we will push back the result into the stack. And if we encounter operand just push that operand into the stack.
Steps for evaluating postfix expression.

1. Accept postfix expression string in post variable.
2.
For i in post:
    If i is an operand:
        Push i in stack.
    Else:
        Pop two elements from stack e.g. X and Y
        Perform operation with current operator on both the parents i.e X i Y
        Push the result back into the stack.
End for loop.
3. Finally pop out the result from the stack.


'''
# Python program to evaluate value of a postfix expression

class evaluate_postfix:
    def __init__(self):
        self.items=[]
        self.size=-1
    def isEmpty(self):
        return self.items==[]
    def push(self,item):
        self.items.append(item)
        self.size+=1
    def pop(self):
        if self.isEmpty():
            return 0
        else:
            self.size-=1
            return self.items.pop()
    def seek(self):
        if self.isEmpty():
            return False
        else:
            return self.items[self.size]
    def evalute(self,expr):
        for i in expr:
            if i in '0123456789':
                self.push(i)
            else:
                op1=self.pop()
                op2=self.pop()
                result=self.cal(op2,op1,i)
                self.push(result)
        return self.pop()
    def cal(self,op2,op1,i):
        if i == '*':
            return int(op2)*int(op1)
        elif i == '/':
            return int(op2)/int(op1)
        elif i == '+':
            return int(op2)+int(op1)
        elif i == '-':
            return int(op2)-int(op1)
s=evaluate_postfix()
expr=input('enter the postfix expression : ')
value=s.evalute(expr)
print('The result of postfix expression',expr,'is',value)

'''
Testcases:
Input: enter the prefix expression : 231*+9-
Output: The result of postfix expression 231*+9- is -4


Input: enter the prefix expression : ++596^-64
Output: The result of postfix expression ++596^-64 is 20
Time complexity: O(n) where n is number of characters in input expression.
Space Complexity: O(n) We used the stack space for n characters.

'''