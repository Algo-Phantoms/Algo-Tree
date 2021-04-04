import math


# Function that returns a sorted list of prime factors of n
def unique_prime_factors(n):
    """
    This function uses a slightly altered version of
    the seive of eratosthenes to find unique prime factors
    of a given number n, instead of creating a boolean array
    that stores whether a number is prime, we create an
    integer list that stores the smallest prime factors of
    all integers upto n
    :param n:
    :return unqiue_factors:
    """
    # smallest prime factor list, initialised with a range such that for all indexes spf[i] is initially i
    # This can also be done by taking an empty list and appending numbers 0 - n into it
    # spf[i] = i is true for prime numbers and can be used to check if composite numbers have been "marked"
    spf = list(range(0, n + 1))

    # Since n cannot have any prime factors larger than it's square root, we run the first loop upto there
    for i in range(2, int(math.sqrt(n))+1):
        # if spf[i] = i, none of the numbers before i have not marked it, hence it is prime
        if spf[i] == i:

            # since i is prime, we need to mark it's multiples, i.e change their spf
            for j in range(2 * i, n + 1, i):

                # We know that j is composite since it's a multiple of i
                # If spf of j is not equal to j, this means a smaller prime
                # has also marked j, i.e j is a multiple of some smaller
                # prime number, so i is not j's smallest prime factor, hence we don't mark it
                if spf[j] == j:
                    spf[j] = i

    # List of prime factors of n, initialised by it's smallest prime factor
    unique_factors = [spf[n]]
    while n > 1:

        # In every iteration, we divide n by it's smallest prime factor, until n becomes 1
        # Whenever we encounter a new value for spf, we append it to the list as it is a new prime factor of n
        if unique_factors[len(unique_factors) - 1] != spf[n]:
            unique_factors.append(spf[n])
        n = n // spf[n]

        # Because we are always dividing n by it's smallest prime factor, the list remains sorted
    return unique_factors


l = list(map(int, input().split()))
for i in l:
    print(unique_prime_factors(i))

"""
Test Case #1:
    Input: 
        6 24 120 720 5040 40320 362880
    Output:
        [2, 3]
        [2, 3]
        [2, 3, 5]
        [2, 3, 5]
        [2, 3, 5, 7]
        [2, 3, 5, 7]
        [2, 3, 5, 7]
        
Test Case #2:
    Input: 
        1969 1938 2356 4797
    Output:
        [11, 179]
        [2, 3, 17, 19]
        [2, 19, 31]
        [3, 13, 41]
"""

