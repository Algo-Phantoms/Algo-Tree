"""
Sorting an array of 0, 1 and 2 without using any existing sorting algorithm.
Let the array be a of size n.
The idea is to have 4 indices- 0, low, high, n-1. All the zeroes will be between 0 and low,
all the ones between low and high and all the twos between high and n-1.

Initially, low=0 and high=n-1.
We'll traverse the array from left to right.
If the element is 0, we will swap it with the element at a[low], increment low and go the next element.
If the element is 1, we will go the next element.
If the element is 2, we will swap it with the element at a[high] and decrement high.

"""

a=list(map(int, input("Enter the array elements seperated by space- ").split()))

low=i=0    #i will be used to traverse the array
high=len(a)-1

while i<=high:
    if a[i] is 0:
        a[i],a[low]=a[low],a[i]
        low+=1
        i+=1
    elif a[i] is 2:
        a[i],a[high]=a[high],a[i]
        high-=1
    else:
        i+=1

print("The sorted array is- ", end=" ")
print(a)

"""
Sample input and output

Example 1-
Enter the array elements seperated by space- 1 0 1 2 0 2 1 0
The sorted array is-  [0, 0, 0, 1, 1, 1, 2, 2]

Example 2-
Enter the array elements seperated by space- 2 2 1 0 1 2 0 0 0
The sorted array is-  [0, 0, 0, 0, 1, 1, 2, 2, 2]

Time complexity = O(n)
Space complexity = O(1)

"""
