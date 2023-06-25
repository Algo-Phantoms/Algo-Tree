# In this problem we have to find whether the given number is a palindrome number or not.
# A palindrome number is a number whose digits remain the same when the number is reversed
# For Ex:
#         INPUT:
#                232
#         OUTPUT:
#                The given number is a palindrome.

#Input

n = int(input("Enter the number\n"))
t = n
rev_no = 0
x = 0

#through the following loop we will find the reverse of the given number

while n != 0:
      c = n%10
      rev_no = (rev_no*10) + (n%10)
      n = n//10
     
#if the given number is equal to its reverse then the given number is a palindrome   

if t == rev_no:
      print("The given number is a palindrome.")
else:
      print("The given number is not a palindrome.")

#         TEST CASES
#      
#     1)INPUT:
#              4325
#       OUTPUT:
#               The given number is not a palindrome.
#
#     2)INPUT:
#              4334
#       OUTPUT:
#               The given number is a palindrome.
    


'''Solution No. 2 Using String ''' 
n = int(input())
n_str = str(n)  #convert it into string in order to do slicing
n_str = int(n_str[::-1]) #reversed the order by slicing

if n_str == n:
      print("The given number is a Palindrome number.")
else:
      print("The given number is not a Palindrome number.")


#TEST CASES : 

'''1. Enter the number : 1252153374328989
The given number is not a Palindrome number.'''

'''2.Enter the number : 23455432
The given number is a Palindrome number.'''


