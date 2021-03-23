"""

A binary search or half-interval search algorithm finds the position of a target value within a sorted array.
The binary search algorithm can be classified as a dichotomies divide-and-conquer search algorithm and executes in logarithmic time.

Algorithm

Compare x with the middle element.
If x matches with the middle element, we return the mid index.
Else if x is greater than the mid element, then x can only lie in the right (greater) half subarray after the mid element.
Then we apply the algorithm again for the right half.
Else if x is smaller, the target x must lie in the left (lower) half. So we apply the algorithm for the left half.

"""


def binary_search(item_list,item):      #function to perform binary search
	first = 0
	last = len(item_list)-1
	found = False
	while( first<=last and not found):      
		mid = (first + last)//2
		if item_list[mid] == item :     #means Item is present at mid
			found = True
		else:
			if item < item_list[mid]:  #If Item smaller, ignore right half
				last = mid - 1
			else:
				first = mid + 1	    #If Item is greater, ignore left half
	return found                        #It will return If found is true or false

a=[]                                         #initialising the array
x=int(input("Enter x : "))                     # no. of items in array
print(x)
for i in range(0,x):
    a.append(int(input("Enter next no : ")))
    print("array :",a)                              #printing array

b=int(input("Enter Number to be Search : "))             #input for the Item need to search
print(b)

print(binary_search(a, b))     #calling function binary search

"""
INPUT AND OUTPUT
Enter x5
5
Enter next no:1
array : [1]
Enter next no:2
array : [1, 2]
Enter next no:3
array : [1, 2, 3]
Enter next no:4
array : [1, 2, 3, 4]
Enter next no:5
array : [1, 2, 3, 4, 5]
Enter Number to be Search3
3
True

Enter x4
4
Enter next no:3
array : [3]
Enter next no:6
array : [3, 6]
Enter next no:8
array : [3, 6, 8]
Enter next no:9
array : [3, 6, 8, 9]
Enter Number to be Search2
2
False

Time And Space Complexity
Time Copmlexity:-O(logn)
Space Complexity:-O(1)
"""
