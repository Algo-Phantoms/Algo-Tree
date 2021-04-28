"""
Climbing stairs problem using Dynamic Programming
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?

Approach- The number of ways you can reach the nth stair would be the sum of the number of ways to reach (n-1)th and (n-2)th stair

We will take an array t of size n+1 and store the number of ways to reach ith stair in the ith index.
"""

def CountWays(n):
    t = [0]*(n+1)
    t[0] = t[1] = 1    #there can be only one way to reach the 0th and 1st stair

    for i in range(2, len(t)):
        j = 1
        while j <= 2 and j <= i:
            t[i] = t[i] + t[i-j]
            j += 1

    return t[n]

n = int(input("Enter the number of stairs- "))
print("The number of ways to climb n stairs = {}".format(CountWays(n)))


"""
Sample input output-

Example 1:
Enter the number of stairs- 10
The number of ways to climb n stairs = 89

Example 2:
Enter the number of stairs- 10
The number of ways to climb n stairs = 89

Time Complexity = O(n) 
Space complexity = O(n)
where n is number of stairs
"""
