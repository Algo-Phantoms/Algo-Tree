'''Counting number of digits in a factorial using Kamnestsky's Formula:
Reason to use: Result of a factorial can be very large to store where long long integers may also be insufficient.(But python containers are capable of hanadling it.)
    Thus, Kamnestsky's formula allows to handle inputs > 10^6
    with a time complexity of O(1)
    
Method :For inputs < 10^6 logarithmic property can be used:
        log( n! ) = log(1*2*3....... * n) 
                  = log(1) + log(2) + ........ +log(n)
        
Method :Use of inbulit function called factorial in math module:
        math.factorial(x) ,then computing its length:
        x=math.factorial(n)
        print(len(str(abs(x))))
    '''

#Using python math module to calculate logs.
import math

#Calcutlates and returns no. of digits in factorial 
def digitsInFactorial(n):
    
        #allow non-negative integers
    if (n<0):
        return 0
    if (n<=1):
        return 1
        # Kamnestsky's Formula:
    x = ((n * math.log10(n / math.e) +
            math.log10(2 * math.pi * n) /2.0))
              
    return math.floor(x) + 1
#asking for user input    
n = int(input("Enter an Integer: "))

#function call to factorial
print("Number of digits in {}! factorial is : {} " .format(n,digitsInFactorial(n)))

'''
Test Cases:
1.input:5!
output:3

2.input:10000000000!
output:95657055187 

3.input:255!
output:505


Complexities:
Time Complexity:O(1)
Space Complexity:O(1)
'''

