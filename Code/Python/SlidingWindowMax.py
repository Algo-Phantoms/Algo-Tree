'''
Description:
Given an array of N elements and a value K (K <= N) , calculate maximum summation 
of K consecutive elements in the array.
'''
# Python Code:

# number of entries in array
n=int(input())
# number of consecutive elements
k=int(input())

# Whole array input
lst = list(map(int,input().strip().split()))[:n]

sum=0
if(n==k):
    for i in range(0,n):
        sum+= lst[i]
        
    print (sum)
    
if(n>k):                    # calculate sum of first window of size K
    mxsum=0
    wnsum=0
    for i in range(0,k):
        mxsum+= lst[i]
        
    wnsum=mxsum             # calculate sum of remaining windows
    for i in range(k,n):
        wnsum+=(lst[i]-lst[i-k])
        if(wnsum>mxsum):
            mxsum=wnsum
            
    print (mxsum)


'''
Test Cases Standard I/O

1. if N == K

N= 5 
K= 5
lst= { 1 2 3 4 5 }

Output : 15

2. if N > K

N= 5
K= 3
lst= { 5 2 -1 0 3 }

Output : 6


Time Complexity : O(N)  # here N= number of entries in the array
Space Complexity : O(1)
'''


