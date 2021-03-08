# Created bubble sort function with array parameter
# Description : It works by repeatedly swapping the adjacent elements if they are in wrong order.One by One element are placed at rigth position
def bubbleSort(arr): 
	n=len(arr) 
	# Traverse through array elements 
    	for i in range(n-1): 
       		# last i elements are sorted 
        	for j in range(0, n-i-1): 
            	# traverse the array from 0 to n-i-1 
            	# Swap if the element found is greater than the next element 
            		if arr[j] > arr[j+1]: 
                		arr[j], arr[j+1] = arr[j+1], arr[j] 
                		
  
# Time complexity 
# Worst case : O(n*n) when array is sorted in reverse order	
# Best case  : O(n)   when array is already sorted order
# Space complexity : O(1)
# Test cases : 
# Input:  5 4 6 7 3 2 1
# Output: 1 2 3 4 5 6 7
# Input:  23 11 65 100 40 200
# Output: 11 23 40 65 100 200
