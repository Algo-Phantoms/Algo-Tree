"""
Converting a binary string to its equivalant decimal number.
This program does not take negative and floating point numbers into account and will run only for positive integers.
The approach is to multiply each bit by 2 raised to the power of the position of the bit from the right.
The sum will be the final answer.
"""

#This function checks whether the given string is a valid binary number or not. 
def isBinary(s):    
    for c in s:
        if c not in ("1","0"):
            return 0
    return 1


print("Enter the binary number: ", end = " ")
binary = input()    #taking the string as input from the user

while isBinary(binary) == 0:    #the program will keep asking the user for input until the string is a valid binary number
    print("Please enter a valid string: ", end = " ")
    binary = input()

decimal = 0    #initialising the decimal number

for i in range (len(binary)):    
    if binary[i] is '1':    #if the bit is 1, only then it will count
        decimal += 2**(len(binary)-i-1)    #since we consider the rightmost position as 0, therefore to calculate a position, we need to write len(binary)-i-1

print("The decimal value of {} is {}".format(binary, decimal))


"""
Sample input and output:

#example 1:
Enter the binary number:  11001
The decimal value of 11001 is 25

#example 2:
Enter the binary number:  10101001
The decimal value of 10101001 is 169

#example 3:
Enter the binary number:  12230
Please enter a valid string:  110111
The decimal value of 110111 is 55

The time complexity of the algorithm is O(n) where n is the length of the string.

"""
