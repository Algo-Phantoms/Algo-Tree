# Find array union of two arrays

def union_of_arrays(arr1, arr2):
    # let's sort both arrays
    arr1.sort()
    arr2.sort()

    
    dt = 0
    ft  = 0
    union = []

    while dt < len(arr1) and ft < len(arr2):
        if arr1[dt] < arr2[ft]:
            dt += 1
        elif arr1[dt] > arr2[ft]:
            ft += 1
        else:
            union.append(arr1[dt])  
            dt += 1
            ft += 1

    return union


if __name__ == "__main__":
    arr1 = list(map(int,input("Enter the Number in list 1:\n").split()))
    arr2 = list(map(int,input("Enter the Number in list 2:\n").split()))
    print(union_of_arrays(arr1, arr2))

'''
Time Complexity : O((n+m)log(n+m))
Space Complexity : O(n+m)

INPUT:
    Enter the list 1: 
    1 2 3 2 0
	Enter the list 2: 
    5 1 2 7 3 2

OUTPUT  
    [1, 2, 2, 3]

'''