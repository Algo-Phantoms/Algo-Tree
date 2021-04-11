"""
Sieve of Eratosthens works by striking out all the multiples of prime numbers. The remaining list of numbers is the list of prime numbers
Suppose we want to find out all the primes less than n. We will take an array A of size n and initially, all elements will be 1. As we iterate, we'll mark the multiples of prime numbers as 0. On completion, the indices having a true value will be the prime numbers.
"""

n=int(input("Enter a number-"))
A=[1]*n

i=2
while i**2<n:
    if A[i] is 1:
        for j in range(i*i, n, i):    #striking out the multiples 
            A[j]=0
    i+=1

print("Prime numbers less than {} are".format(n), end=" ")
for i in range(2, len(A)):
    if A[i] is 1:
        print(i, end=" ")


"""
Sample inputs and outputs

Example 1:
Enter a number-50
Prime numbers less than 50 are 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

Example 2:
Enter a number-35
Prime numbers less than 35 are 2 3 5 7 11 13 17 19 23 29 31

Time Complexity=O(n*log(logn))
Space Complexity=O(n)
"""
