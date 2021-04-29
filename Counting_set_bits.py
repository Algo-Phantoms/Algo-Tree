# In this problem we have to count all the set
# from 0 to the given number n.
#For Ex: if n=3
#        0 ---> 0000
#        1 ---> 0001
#        2 ---> 0010
#        3 ---> 0011
#   So, total number of set bits are 4.

def Counting_set_bits(n):

    #this is the base case
    if n == 0 or n == 1:
        return n

    i=0
    while 2**i<=n:
        i=i+1
    # i is the last power of 2 before n
    i=i-1

    #set_i gives number of set bits before 2**i
    set_i = (2**(i-1))*i

    #msb gives the set bits at most significant bits of numbers from 2**i to n
    msb = (n-(2**i)+1)

    #The recursive call counts the set bit of number from 2**i to n 
    # after removing the msb of each
    # for ex: 8(1000) becomes 0(000) after removing msb
    return set_i + msb + Counting_set_bits(n-(2**i))

if __name__ == '__main__':
    n=int(input("Enter the number\n"))
    print("Total number of set bits are:",Counting_set_bits(n))


#      TEST CASES
# 
#    1) INPUT:  
#              Enter the number
#              8
#      OUTPUT:
#              13

#    2) INPUT:  
#              Enter the number
#              13
#      OUTPUT:
#             25 
