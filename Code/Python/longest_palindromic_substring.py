'''
    Problem statement: Given a string s,
    find the longest substring which is a palindrome.

    Approach used:
        Naive way:
        We can do brute force to check whether
        each substring is palindrome or not.
        Dynamic Programming Approach:
        This problem can be done by recursion, with overlapping subproblems.
        So, a top down or a bottom up approach can be used.
        Here, we will use the tabulation method(bottom up DP).

        Steps using an example:
        1. Initialize a matrix of n * n. t[i][j]=1, means it is a palindrome,
           whereas t[i][j]=0, means it's not a palindrome.
        2. Fill the table for length=1 substrings,
          substring of length 1 is a palindrome.
            c  b  b  d
         c [[1, 0, 0, 0],
         b [0, 1, 0, 0],
         b [0, 0, 1, 0],
         d [0, 0, 0, 1]]

        3. Fill the table for length=2 substrings,
           run a loop to check if s[i]==s[j+1]
              c  b  b  d
          c [[1, 0, 0, 0],
          b [0, 1, 1, 0],
          b [0, 0, 1, 0],
          d [0, 0, 0, 1]]
        4. Now the table is filled for the values
           from length=3 substring and so on.
           If t[i+1][j-1] is 1 and s[i]==s[j], then t[i][j]=1.
            c  b  b  d
          c [[1, 0, 0, 0],
          b [0, 1, 1, 0],
          b [0, 0, 1, 0],
          d [0, 0, 0, 1]]
          This example only has 2 length substring length.
        5. Make a count of the maximum length of palindromic substring found
           and it's start index throughout the filling of the table.
'''

for _ in range(int(input())):
    s = input()
    n = len(s)
    # making a n * n matrix
    t = [[0 for i in range(n)] for j in range(n)]

    # in worst case, length of longest palindrome would be 1
    ans = 1
    # start of the palindrome
    start = 0

    # initializing the diagonal
    # substrings of length 1
    for i in range(n):
        t[i][i] = 1

    # for substrings of length 2
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            t[i][i + 1] = 1
            if ans < 2:
                ans = 2
                start = i
        else:
            t[i][i + 1] = 0

    # for substrings of length >= 3
    for k in range(3, n + 1):
        # starting index of the substring
        i = 0
        while i < n - k + 1:
            # ending index of the substring
            j = i + k - 1
            # checking if the substring t[i][j] is a palindrome
            # by the condition of t[i][j]=1
            # and the ending characters s[i]==s[j]
            if t[i + 1][j - 1] != 0 and s[i] == s[j]:
                t[i][j] = 1
                # condition for getting the start index of the
                # longest palindromic substring and it's length
                if k > ans:
                    ans = k
                    start = i
            i += 1
    # printing the longest palindromic substring
    print(s[start:start + ans])

'''
Test Case 1:
1
aabbaaaa
Output:
aabbaa
Test Case 2:
2
abcd
zjjfjjwax
Output:
a
jjfjj
Time Complexity: O(n^2), where n is the length of the string
Space Complexity: O(n^2), where n*n is the size of the matrix
'''
