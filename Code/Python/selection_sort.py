'''
 PROBLEM STATEMENT:
 Implementation of Selection Sort for an array in Python
'''

A = [64, 25, 12, 22, 11]
  
# Traverse through all array elements
for i in range(len(A)):
    # Find the minimum element in the remaining unsorted array
    min_index = i
    for j in range(i+1, len(A)):
        if A[min_index] > A[j]:
            min_index = j      
    # Swap the found minimum element with the first element        
    A[i], A[min_index] = A[min_index], A[i]
  
# Driver code to test above
print ("Sorted array-")
for i in range(len(A)):
    print(A[i], end = ' ')

# Output
'''
Sorted array-
11 12 22 25 64
'''

'''
Time Complexity: O(n^2) as there are two nested loops.

Auxiliary Space: O(1)
The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
'''
