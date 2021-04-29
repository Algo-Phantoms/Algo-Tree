'''
Description : 
        Geek created a random series and given a name geek-onacci series. Given four 
        integers x, y, z, N. x, y, z represents the first three numbers of geek-onacci series. 
        Find the Nth number of the series. The nth number of geek-onacci series is a sum of the 
        last three numbers (summation of N-1th, N-2th, and N-3th geek-onacci numbers).
'''

# Python Code ->

def find(A, B, C, N) :
   
    # geekonacci series is stored
    arr = [0] * N
 
    # Storing the first three terms of the series
    arr[0] = A
    arr[1] = B
    arr[2] = C
 
    # Iterate over the range [3, N]
    for i in range(3, N):
 
        # Update the value of arr[i] as the sum of previous 3 terms in the series
        arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3])
     
    # Return the last element of arr[] as the N-th term
    return arr[N - 1]

 
# Driver Code
A = 1
B = 3
C = 2
N = 4
 
print(find(A, B, C, N))

# Output -> 6


'''
Time complexity : O(log n)
Space complexity : O(1)

Test Case 1 :
Input :
 A = 1
 B = 3
 C = 2
 N = 5 
Output :
 11

Test Case 2 :
Input : 
 A = 1
 B = 3
 C = 2
 N = 6 
 Output :
 19
'''
 