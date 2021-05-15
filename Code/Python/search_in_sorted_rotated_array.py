# Given an integer array sorted in ascending order but rotated about some pivot
# Task is to find the index of a given element "target" in the array

# The idea is to find the pivot, then divide the array in two sub-arrays(both of which will be sorted)
# and perform binary search on them.

# Binary search function searches and returns the index of the target element in O(log n)
def binarySearch(nums, l, r, target):
    if l > r:
        return -1

    mid = (int)((l + r) / 2)

    if nums[mid] == target:
        return mid

    if nums[mid] > target:
        return binarySearch(nums, l, mid - 1, target)

    return binarySearch(nums, mid + 1, r, target)

# Find pivot returns the index of the pivot element
# Pivot can be indentified by the fact that it is the only element for which
# next element to it is smaller than it
def findPivot(nums, l, r) -> int:
    if l > r:
        return -1

    mid = (int)((l + r) / 2)

    if mid + 1 <= r and nums[mid] > nums[mid + 1]:
        return mid

    if mid - 1 >= l and nums[mid] < nums[mid - 1]:
        return mid - 1

# If mid is not the pivot element, it can be found in either direction
# of the current element as per condition
    if nums[l] >= nums[mid]:
        return findPivot(nums, l, mid - 1)

    return findPivot(nums, mid + 1, r)

def search(nums, target) -> int:
    n = len(nums)
# find the pivot
    pivot = findPivot(nums, 0, n - 1)

# if pivot is not found, it means the array is not rotated
    if pivot == -1:
        return binarySearch(nums, 0, n - 1, target)
        
# If a pivot is found, then either the target can be found either at the pivot 
# or in the 2 sorted subarrays around the pivot
    if nums[pivot] == target:
        return pivot

    if nums[0] <= target:
        return binarySearch(nums, 0, pivot - 1, target)

    return binarySearch(nums, pivot + 1, n - 1, target)

def main():
    nums = list(map(int, input().split()))
    target = int(input())
    ans = search(nums, target)
    print(ans)

if __name__ == "__main__":
    main()


# Test Case 1:
# nums= [5, 6, 7, 8, 9, 10, 1, 2, 3, 4]
# target = 3
# output = 8

# Test Case 2:
# nums= [2, 3, 5, 7, 8]
# target = 6
# output = -1

# Time Complexity: O(log n), both Find pivot and Binary search functions run in O(log n)
# Space Complexity: O(1), no extra space is required
