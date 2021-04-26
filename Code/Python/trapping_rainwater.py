"""
Problem Description:
Given an integer array A of non-negative integers representing an elevation map
where the width of each bar is 1, compute maximum water it is able to trap after raining.
"""

# Function to calculate the maximum water that can be trapped .
def max_water(arr, n):

    temp = 0
    # iterate the array
    for i in range(1, n - 1):

        # Find the element with maximum height on right of element i
        max_right = arr[i]

        for j in range(i+1, n):
            max_right = max(max_right, arr[j])

        # Find the element with maximum height on the left of element i
        max_left = arr[i]
        for j in range(i):
            max_left = max(max_left, arr[j])

        # Updating the temp value
        temp = temp + (min(max_right, max_left) - arr[i])

    return temp


if __name__ == "__main__":
    arr = []
    print("Enter number of elements")
    # number of elements as input
    n = int(input())
    
    print("Enter the elements")
    # iterating till the range
    for i in range(0, n):
        p = int(input())
        arr.append(p)
    print(max_water(arr, n))

"""
Test case 1:
    input:
    n=5
    arr=[2,0,2,3,4]
    output:
    2

Test case 2:
    input:
    n=7
    arr=[5,1,2,3,2,6,1]
    output:
    12

Time Complexity: O(n)

Space Complexity: O(1)
"""
