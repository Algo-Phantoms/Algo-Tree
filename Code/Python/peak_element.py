'''
Peak Element using Binary Search
Problem Statement: Given an array of size n, find the peak element.
                   Peak element is the element which is greater than its neighbours.
                   There may exist more than one peak element, so print any one.
'''

def binary_search(in_arr, start, end):
 
    # find the middle element useing "start + (end - start) / 2"
    mid =  start + (end - start) // 2
 
    # check if the middle element is greater than its neighbors
    # by applying the condition for binary search
    if ((mid == 0 or in_arr[mid - 1] <= in_arr[mid]) and
            (mid == len(in_arr) - 1 or in_arr[mid + 1] <= in_arr[mid])):
        # if true then return the index of that element
        return mid
 
    # If the left neighbor of "mid" is greater than the middle element,
    # find the peak in the left sublist using recursion
    if mid - 1 >= 0 and in_arr[mid - 1] > in_arr[mid]:
        return binary_search(in_arr, start, mid - 1)
 
    # If the right neighbor of "mid" is greater than the middle element,
    # find the peak in the right sublist using recursion
    
    return binary_search(in_arr, mid + 1, end)
 
 
if __name__ == '__main__':
    # input the size of array
    n = int(input()) 
    arr = []
    # enter the elements of the array
    for i in range(0, n):
        arr.append(int(input()))
    # calling the function to find the index of peak element
    pos = binary_search(arr, 0, n - 1)
    # printing the element
    print("The peak element is", arr[pos])
    

'''
Test Case 1:
Input -
5
1
3
2
5
1
Output -
The peak element is 3

Test Case 2:
Input -
7
1
2
3
4
3
2
1
Output -
The peak element is 4

Time Complexity: O(logn), since we used binary search
Space Complexity: O(1), no extra space is used
'''
