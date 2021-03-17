"""

Brian Kernighan’s Algorithm 
    Python code to count number of set bits of a number 
       In this algorithm we use the bit manipulation property.This property states that if we subtract 1 from a number ,then all the bits
       after and including the rightmost set bit get flipped.

       for example : n  = 15  1111
                     n-1= 14  1110 

       To clear the rightmost set-bit we take logical and of n with n-1. 
       Repeat this procedure until n is not equal to 0.
       The number of iterations required to make n as 0 is the count of number of set bits in number n

"""

#function to count number of set bits of number 'n'
def count__bits(n):
    count = 0
    while n:        #loop till n not equal to 0 
        n &= n - 1    #taking logical AND of n and n-1
        count += 1
    return count    #return number of set bits
 
 
n = int(input())  #take input number from user
print(count__bits(n)) #print the number of set bits in number 'n' by calling function count__bits(n)

"""
Time Complexity = O(logn)
Space Complexity = O(1)

Testcases :

input1   2    
output1  1

intput2  5
output2  2

input3   15
output3  4

"""
