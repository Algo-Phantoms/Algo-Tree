    '''
    Peak Element in an Array in Python
    
    An array element is a peak if it is NOT smaller than its neighbours. For corner elements, we need to consider only one neighbour. 
    There might be multiple peak elements in an array, and the solution should report any peak element.
    
    Implementation: 
    
    Divide and Conquer can be used to find a peak in O(Logn) time. The idea is based on the technique of Binary Search to check if the middle element is the peak element or not. 
    If the middle element is not the peak element, then check if the element on the right side is greater than the middle element then there is always a peak element on the 
    right side. If the element on the left side is greater than the middle element then there is always a peak element on the left side. Form a recursion and the peak element 
    can be found in log n time. 
    

    Algorithm: 

    -Create two variables, l and r, initilize l = 0 and r = n-1
    -Iterate the steps below till l <= r, lowerbound is less than the upperbound
    -Check if the mid value or index mid = (l+r)/2, is the peak element or not, if yes then print the element and terminate.
    -Else if the element on the left side of the middle element is greater then check for peak element on the left side, i.e. update r = mid – 1
    -Else if the element on the right side of the middle element is greater then check for peak element on the right side, i.e. update l = mid + 1
    
    
    '''
  
    # A python3 program to find a peak 
    # element element using divide and conquer
 
    # A binary search based function 
    # that returns index of a peak element
def findPeakUtil(arr, low, high, n):
     
    # Find index of middle element
    # (low + high)/2 
     mid = low + (high - low)/2
     mid = int(mid)
     
    # Compare middle element with its 
    # neighbours (if neighbours exist)
    if ((mid == 0 or arr[mid - 1] <= arr[mid]) and
        (mid == n - 1 or arr[mid + 1] <= arr[mid])):
        return mid
 
 
    # If middle element is not peak and 
    # its left neighbour is greater 
    # than it, then left half must 
    # have a peak element
    elif (mid > 0 and arr[mid - 1] > arr[mid]):
        return findPeakUtil(arr, low, (mid - 1), n)
 
    # If middle element is not peak and
    # its right neighbour is greater
    # than it, then right half must 
    # have a peak element
    else:
        return findPeakUtil(arr, (mid + 1), high, n)
 
 
    # A wrapper over recursive 
    # function findPeakUtil()
def findPeak(arr, n):
 
    return findPeakUtil(arr, 0, n - 1, n)
 
 
    # Driver code
if __name__=='__main__':
  
  arr = list(map(int, input().strip().split()))
  n=len(arr)
  index=findPeak(arr,n)
  print("Peak Element is ", arr[index])
  
  
    '''
    
    Testcases:-
    
    1.
    Input:
    5 10 20 15
    
    Output:
    Peak element is 20
    
    2.
    Input:
    8 9 10 2 5 6
    
    Output:
    Peak element is 10
    
    Complexity:-
    Time Complexity: O(Logn). # In each step our search becomes half. So it can be compared to Binary search, So the time complexity is O(log n)
    Space complexity: O(1).  # No extra space is required, so the space complexity is constant.
    '''
  
  
