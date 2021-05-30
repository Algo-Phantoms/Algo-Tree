'''
Factorial function instruct to multiply all whole number from input number down to 1.
The formula for n factorial can be defined as n! = n×(n−1)!
Factorial zero is defined as equal to 1
'''

    #This is a recursive function to find the factorial of an integer
def factorial(num):
    if num == 0:
        return 1
    else:
        temp = factorial(num-1)
        return num * temp
    
num = int(input("Input: "))

print('Output:',factorial(num))

'''
    Test cases:
    Input: 7
    Output: 5040
    
    Input: 0
    Output: 1

    Time complexity: O(n)
    Space Complexity: O(1)

'''    
	
