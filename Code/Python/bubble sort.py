#created bubble sort function with array parameter
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
                		
  
