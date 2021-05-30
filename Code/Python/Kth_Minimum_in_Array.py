import heapq
from heapq import heappop
 
 
# Function to find the k'th smallest element in a list using min-heap
def kthSmallest(arr, kth):
 
    # transform the input list into a min-heap
    heapq.heapify(arr)
 
    # pop from min-heap exactly `k-1` times
    while kth > 1:
        heappop(arr)
        kth = kth - 1
 
    # return the root of min-heap
    return arr[0]
 
# Driver code
if __name__ == '__main__':
 
    arr = []
    n = int(input("Enter number of elements: "))
    print("Enter elements: ")
    for i in range(n):
        element = int(input())
        arr.append(element)

    k = int(input("Enter the number k: "))
    print("K'th smallest element is",
          kthSmallest(arr, k))


'''
Time Complexity: O(N + klog(N)) (where N is number of elements in array and K is the position)
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
