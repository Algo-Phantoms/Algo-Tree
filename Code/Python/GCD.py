"""

GCD(GREATEST COMMON DIVISOR)

APPROACH:

     The solution is to use Euclidean algorithm which is the main algorithm used for the calculation of GCD of two numbers. 
     The idea is, GCD of two numbers doesn’t change if smaller number is subtracted from a bigger number. This step is repeated 
     until second number becomes zero . When second number becomes 0 , the first number is the GCD of the two given numbers as 
     every number divides 0.

"""

#recursive function that returns GCD of 2 numbers
def gcd (a, b):  
    if (b == 0):  #every number divides 0 so return a
        return a   
    else:  
        return gcd (b, a % b)  

#input 1st number
a =int (input ("Enter the first number: "))  
#input 2nd number 
b =int (input ("Enter the second number: ")) 

#call to GCD(A,B)  
gcd_ans = gcd(a, b)
#prints the GCD of two numbers given by the user
print("GCD of two number is: ", gcd_ans)


"""
TESTCASES : 

TESTCASE-1: 
       INPUT  : 2
                4
       OUTPUT : GCD of two number is:  2
TESTCASE-2:
       INPUT  : 2
                5
       OUTPUT : GCD of two number is:  1
TESTCASE-3:
       INPUT  : 0
                4
       OUTPUT : GCD of two number is:  4       


TIME COMPLEXITY = O(log(max(a,b))) 
SPACE COMPLEXITY= O(1)
"""