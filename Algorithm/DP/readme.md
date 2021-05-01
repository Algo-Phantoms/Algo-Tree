# Dynamic Programming

**“Those who cannot remember the past are condemned to repeat it ⏳⌛.”**

Dynamic Programing is all about remembering answers to the subproblems you’ve already solved and not solving it again.

## Where do we need Dynamic Programming?

- If you are given a problem, which can be broken down into smaller sub-problems.
- These smaller sub-problems can still be broken into smaller ones - and if you manage to find out that there are some overlappping sub-problems.
- Then you’ve encountered a DP problem.

**The core idea of Dynamic Programming is to avoid repeated work by remembering partial results.**

## Dynamic Programming and Recursion:

**Dynamic programming is basically, recursion plus memoization....**

- Recursion allows you to express the value of a function in terms of other values of that function.
- If you implement your function in a way that the recursive calls are done in advance, and stored for easy access, it will make your program faster.
- This is what we call Memoization - it is memorizing the results of some specific states, which can then be later accessed to solve other sub-problems.

The intuition behind dynamic programming is that we trade space for time, i.e. to say that instead of calculating all the states taking a lot of time but no space, we take up space to store the results of all the subproblems to save time later.

## Optimization Problems

Dynamic Programming is typically applied to optimization problems. In such problems there can be many possible solutions. Each solution has a value, and we wish to find a solution with the optimal (minimum or maximum) value. We call such a solution an optimal solution to the
problem. If same suproblems are called again and again, that problem has **Overlapping Subprolems property**. Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can
be avoided by constructinng a temporary array dp[] and memoizing the computed values in this array.

## Dynamic Programming Solution

1. **Top Down DP**- In Top Down, you start building the big solution right away by explaining how you build it from smaller solutions.
2. **Bottom Up DP**- In Bottom Up, you start with the small solutions and then use these small solutions to build up larger solutions.

## Questions :

- Knapsack ----> [C++](/Code/C++/knapsack.cpp)

- Kadane's Algorithm ----> [C++](/Code/C++/kadane_algo.cpp)

- Longest Common Subsequence ----> [C++](/Code/C++/longest_common_subsequence.cpp)

- Longest Common Substring ----> [C++](/Code/C++/longest_common_substring.cpp)

- Shortest Common Supersequence ---->[C++](/Code/C++/print_shortest_supersequence.cpp)

- Minimum Number of Deletions To Make a String Palindrome ---->[C++](/Code/C++/min_deletions_to_make_string_palindrome.cpp)

- Climbing Stairs ----> [C++](/Code/C++/Climbing_Stairs.cpp)

- Word Wrap Problem ----> [C++](/Code/C++/word_wrap.cpp)

