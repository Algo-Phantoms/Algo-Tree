def median_same_size( arg1, arg2 , n):
    """
    A Simple Merge based O(n) Python 3 solution 
    to find median of two sorted lists
    This function returns median of ar1[] and ar2[].
    """
    
    i,j,m1,m2,count = 0,0,-1,-1,0#initial variables
    arg1.sort()
    arg2.sort()
    while count < n + 1:
        count += 1         
        if i == n:
            m1 = m2
            m2 = arg2[0]
            break
        elif j == n:
            m1 = m2
            m2 = arg1[0]
            break
        if arg1[i] <= arg2[j]:
            m1 = m2 
            m2 = arg1[i]
            i += 1
        else:
            m1 = m2 
            m2 = arg2[j]
            j += 1
    return (m1 + m2)/2


# Driver code
if __name__=="__main__":
    L1 = [10, 120, 105, 206, 308]
    L2 = [20, 103, 107, 300, 405]
    n1 = len(L1)
    n2 = len(L2)
    if n1 == n2:
        print("Median is ", median_same_size(L1, L2, n1))
    else:
        print("Doesn't work for arrays of unequal size")
 

