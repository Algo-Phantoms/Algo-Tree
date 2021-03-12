"""Python program to find number of operations 
# to make an array palindrome """
  

def minOps(arr):
    """Returns minimum number of count operations 
required to make arr[] palindrome """
    ans = 0 # Initialize result
    n = len(arr) 
    i,j = 0,n-1
    while i<=j: 
        if arr[i] == arr[j]: 
            i += 1
            j -= 1
        elif arr[i] > arr[j]: 
            j -= 1
            arr[j] += arr[j+1]  
            ans += 1
        else: 
            i += 1
            arr[i] += arr[i-1] 
            ans += 1
  
    return ans 
  
  
# Driver program
if __name__=="__main__":
    arr = [10, 40, 8, 9, 1] 

    print("Minimum operations is " + str(minOps(arr))) 
