'''
Sidharth Sethi
sidharth.sherry@gmail.com

Working -
First Loop just ilterates through all the elements of the list
The second loop compares the value and if the value is less than the previous one
The Swap takes place and the smaller value is inserted before the larger value
'''

#function for insertion  
def insertion_sort(arr):  
    for i in range(1, len(arr)):  
        value = arr[i]  
        j = i - 1  
        while j >= 0 and value < arr[j]:  
            arr[j + 1] = arr[j]  
            j -= 1  
        arr[j + 1] = value  
    return arr  

array = []  
n = int(input("Enter number of elements of list"))

for i in range(0,n):
    element = int(input())
    array.append(element)

print("The unsorted list is:", array)  
  
print("The sorted list1 is:", insertion_sort(array))  

'''
Time Complexity is O(n2) due to 2 loops 
Space Complexity is O(1)

Test 1
The unsorted list is: [4, 5, 6, 7, 8, 9, 5, 2, 1, 8]
The sorted list1 is: [1, 2, 4, 5, 5, 6, 7, 8, 8, 9]

Test 2
The unsorted list is: [4, 5, 6, 6, 5, 0, 8, 7]
The sorted list1 is: [0, 4, 5, 5, 6, 6, 7, 8]
'''