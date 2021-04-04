'''
PROBLEM STATEMENT:
Given an array, arr of size n. The task is to print all those elements which are repeated in the array, i.e.,
print the duplicates present in the array.
For example, an array of [2, 3, 2, 4, 3] contains duplicates of 2 and 3. So, the output will be 2 3.
'''


# Function to print duplicates in an array
def Duplicate(arr, n):
	# A dictionary created to store the frequency of each element in arr
	freq = {}
	for num in arr:
		# If an element of arr is already present in the dictionary, then increment its value by 1
		if freq.get(num):
			freq[num] += 1
		# Otherwise, make its value = 1
		else:
			freq[num] = 1
	# Printing those elemnents whose value > 1
	for key in freq:
		if(freq[key] > 1):
			print(key, end = " ")


# Driver Code

# User inputs the the size of array 
n = int(input("Enter the size of an array: ")) 
arr = []
print("Enter ", n ," elements:")

# User inputs array elemnents
for i in range(n):
    arr.append(int(input()))

# A function call to find duplicates
print("The duplicates in the array are:") 
Duplicate(arr, n)


'''
TEST CASES:
1.
Input:
8 
[2, 4, 6, 1 ,2 ,6 ,8 ,4]
Output:
2 4 6

2.
Input:
5
[1, 1, 1, 1, 1]
Output:
1

TIME COMPLEXITY: O(n), due to a single traversal of the given array, where 'n' denotes the array size
SPACE COMPLEXITY: O(n), due to dictionary created, where 'n' denotes the size of the dictionary 
'''