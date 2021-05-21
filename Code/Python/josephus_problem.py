# Josephus Problem Statement:
# We are given n people, standing in a circle.
# In each step, k-1 people are skipped and the kth person is executed(killed)
# The process stops when only one person remains. It is required to find the position of last person.

# strategy:
# josephus(n,k) can be calculated if we know the solution of josephus(n-1,k)
# Therefore, this will be solved using recursion.


def josephus(n, k):
    # only one person will be left, which is the answer
    if n == 1:
        return 1
    else:

        # The recursive call
        # josephus(n-1,k) considers the
        # original position k%n + 1 as position 1
        # therefore the returned position
        # is adjusted.

        return (josephus(n - 1, k) + k - 1) % n + 1


n = int(input())
k = int(input())
print(josephus(n, k))



# Test case 1:
#    Input:
#    6 3
#    Output:
#    1

# Test case 2:
#    Input:
#    15 4
#    Output:
#    13

# Time Complexity: O(n)
# Space Complexity: O(n)





