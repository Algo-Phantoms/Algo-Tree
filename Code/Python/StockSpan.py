'''

Problem: User would be given with the prices of stock.User needs to output the span of each stock price for n day,where 
span refers to as  maximum number of consecutive days  for which the price of the stock on the current day is less than or equal to the price on the given day.

Solution:
The problem could be done in O(n) time complexity using stack.The span of stock at day 1 would always be 1 as there are no previous day before it.
Index of the first day is pushed inside the stack,if price at the current day is less than the price of stack that is stored at stack top 
then span of the current day would be currentday-stack_top,after which we would push current day index in the stack.
If price at current day is greater than price at the index stored by stack top then we would simply pop from the stack,
untill stack become empty or price at stack_top is greater than cureent day price.
If stack become empty then span at that day would be current_day+1

'''
stock = []
n = int(input("Enter total number of days : "))
for i in range(0, n):
	t = int(input())

	stock.append(t)
answer=[]
for i in range(0,n):
    answer.append(0)

answer[0]=1
stackhelp=[]
stackhelp.append(0)
for i in range(1,n):
    if(len(stackhelp)>0 and stock[i]<stock[stackhelp[-1]]):
        answer[i]=i-stackhelp[-1]
    else:
        while(len(stackhelp)>0 and stock[i]>=stock[stackhelp[-1]]):
            stackhelp.pop()
        if(len(stackhelp)<=0):
            answer[i]=i+1;
        else:
            answer[i]=i-stackhelp[-1]
    stackhelp.append(i)
print("Resultant span of each stock is : ")
for i in range(0, n):
		print (answer[i], end =" ")

'''
Time Complexity : O(N)
Space Complexity: O(N)

Test Cases:

Input 1:
5
30 35 40 38 35

Output 1:
1 2 3 1 1


Input 2:
7
1 2 3 8 5 6 7

Output 2:
1 2 3 4 1 2 3

'''