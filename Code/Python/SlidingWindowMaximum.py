'''
 - Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.
'''

# Python program 
  
# Method to find the maximum for each and every contiguous subarray of s of size k 

def printMax(Arr, n, k): 

    max = 0
    
    for i in range(n - k + 1): 
        max = Arr[i] 
        for j in range(1, k): 
            if Arr[i+j] > max: 
                max = Arr[i + j] 
        print(str(max) + " ", end = "") 
  
# Driver method 
if __name__=="__main__": 
    Arr = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13] 
    n = len(Arr) 
    k = 4
    printMax(Arr, n, k) 

# Output : 10 10 10 15 15 90 90


'''
Test Case 1:
Input :
Arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}
k = 3 
Output :
3 3 4 5 5 5 6

Test Case 2:
Input :
Arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}
k = 4 
Output :
10 10 10 15 15 90 90

Time Complexity = O(n*k)
Space Complexity = O(1)
'''