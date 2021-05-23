# Python3 program to find k'th smallest element
 
# Function to return k'th smallest element in a given array
def kthSmallest(arr, n, k):
 
    # Sort the given array
    arr.sort()
 
    # Return k'th element in the
    return arr[k-1]
 
# Driver code
if __name__=='__main__':
    arr = []
    n = int(input("Enter number of elements: "))
    for i in range(n):
        element = int(input("Enter element: "))
        arr.append(element)

    k = int(input("Enter the number k: "))
    print("K'th smallest element is",
          kthSmallest(arr, n, k))
 