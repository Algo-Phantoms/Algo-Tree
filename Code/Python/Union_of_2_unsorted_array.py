'''
Union of Two Unsorted Array In python
Algorithm:
1. Initialize empty Union array which will be our answer
2. Sort the given 2 array
3. Copy one array to empty union array
4. for every element in array2 search element in array1: if not found, append element to union array
5. Print union array
'''
# Union function
def printUnion(arr1,arr2,m,n):
    union=[]
    arr1.sort()
    arr2.sort()
    union=arr1
    for i in range (n):
        if(binarysearch(arr1,0,m-1,arr2[i]) == -1):
            union.append(arr2[i])
    
    print(union)


#Binary Search
def binarysearch(arr,l,r,x):
    if(r>=l):
        mid=int(l+(r-l)/2)
        if(arr[mid]==x):
            return mid
            
        if(arr[mid]>x):
            return binarysearch(arr,l,mid-1,x)
            
        return binarysearch(arr,mid+1,r,x)
            
    return -1        
    
    
# Taking input 
arr1 = [1,5,2,7,9,10,56,27]; 
arr2 = [2,7,10,65,89];
m=len(arr1)
n=len(arr2)
print("Union:")
printUnion(arr1,arr2,m,n)

'''
Test Case1:
    Input:
        arr1 = [7, 1, 5, 2, 3, 6, 8,19]; 
        arr2 = [3, 8, 6, 20, 7, 6];
    Output:
        Union:
        [1, 2, 3, 5, 6, 7, 8, 19, 20]

Test Case2:
    Input:
       arr1 = [1,5,2,7,9,10,56,27]; 
       arr2 = [2,7,10,65,89];
    Output:
        Union:
        [1, 2, 5, 7, 9, 10, 27, 56, 65, 89]

Time-Complexity:O(mlogm + nlogn)
Space-Complexity:O(m+n)
'''    
