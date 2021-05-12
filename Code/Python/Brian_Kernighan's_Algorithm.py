""" 
Brian Kernighan's Algorithm
Given a number "num", you to give the number of setbits in the number.
The setbit is "1" in the binary form of given number.
For example: number of set bits in 5 is 2 since its binary
representation is '101' where count of 1 is 2.
 """
def countBits(num):
    # variable for number of setbits
    cnt = 0
    
    # number of times this loop run, will give the number of setbits
    while(num):
        num = num&(num-1) #n&(n-1) will unset the rightmost bit
        cnt += 1
    return cnt


# taking input number from user
num = int(input())

# calling the function count to count the setbits
print(countBits(num))


"""
Test Cases
1.
Input - 12
Output - 2

2.
Input - 101
Output - 4

Time complexity: O(logn) where n is the input number whose set bit is to be count
Space complexity: O(1), since no extra space is used

"""