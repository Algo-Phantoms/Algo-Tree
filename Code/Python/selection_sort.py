'''
   PROBLEM STATEMENT:
   Implementation of Selection Sort for an array in Python
'''

def selectionSort(array):
    size = len(array)

    for step in range(size):
        curr_index = step

        for i in range(step + 1, size):
            if array[i] < array[curr_index]:
                curr_index = i

        array[step], array[curr_index] = array[curr_index], array[step]

arr = [-8, 24, 3, 0, 16]
selectionSort(arr)
print('Sorted Array in Ascending Order : ')
print(arr)


'''
  Sorted Array in Ascending Order : 
  [-8, 0, 3, 16, 24]
'''

'''
  Time Complexity: O(n^2) as there are two nested loops.

  Auxiliary Space: O(1)
  The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
'''
