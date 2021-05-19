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
    
