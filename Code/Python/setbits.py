""" Problem statement: Given a number "num", you to give the number of setbits in the number.
                       The setbit is "1" in the binary form of given number. """
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
Test Case 1: input - 12
            output - 2
Test Case 2: input - 101
            output - 4
"""

"""
Time complexity: O(logn) - n = input number
Space complexity: O(1)

"""
