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
    print("Enter elements: ")
    for i in range(n):
        element = int(input())
        arr.append(element)

    k = int(input("Enter the number k: "))
    print("K'th smallest element is",
          kthSmallest(arr, n, k))

'''
Time Complexity: O(N Log N)
Space Complexity: O(N)

Example 1:
Input:
Enter number of elements: 
6
Enter elements: 
7 10 4 3 20 15

Enter the number k: 
3

Output:
K'th smallest element is:
7

Example 2:
Input:
Enter number of elements: 
7
Enter elements: 
8 1 0 9 5 11 4

Enter the number k: 
4

Output:
K'th smallest element is:
5
'''
