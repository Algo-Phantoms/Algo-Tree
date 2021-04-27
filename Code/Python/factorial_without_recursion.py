'''
PROBLEM STATEMENT:
Given a number, the task is to print its factorial.
A factorial of a number 'n' is the product of numbers from 1 to n.
'''

# A function to calculate factorial of a number and to print it
def Factorial(n):
    fact = 1
    while n > 0:
        fact = fact*n
        n -= 1
    print(fact)

# Driver Code
n = int(input("Enter a number: "))
print("Factorial of", n, "is:", end=" ")
# A function call to print factorial
Factorial(n)

'''
TEST CASES:
1.
Input:
Enter a number: 5
Output:
Factorial of 5 is: 120

2.
Input:
Enter a number: 8
Output:
Factorial of 8 is: 40320

TIME COMPLEXITY: O(n), for traversing the numbers from 1 to n
where, 'n' denotes the number entered by the user.
SPACE COMPLEXITY: O(1), no extra space used.
'''
