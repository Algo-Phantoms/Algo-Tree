def calculateLBS(A):
 
    
    I = [0] * len(A)
 

    D = [0] * len(A)
 
    n = len(A) - 1
 
    I[0] = 1
    for i in range(1, n + 1):
        for j in range(i):
            if A[j] < A[i] and I[j] > I[i]:
                I[i] = I[j]
        I[i] = I[i] + 1
 
    D[n] = 1
    for i in reversed(range(n)):
        for j in range(n, i, -1):
            if A[j] < A[i] and D[j] > D[i]:
                D[i] = D[j]
        D[i] = D[i] + 1
 

    lbs = 1
    for i in range(n + 1):
        lbs = max(lbs, I[i] + D[i] - 1)
 
    return lbs
 
 
if __name__ == '__main__':
 
    A = [4, 2, 4, 9, 7, 6, 14, 3, 3]
 
    print("The length of the longest bitonic subsequence is", calculateLBS(A))