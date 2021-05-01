'''
PROBLEM STATEMENT:
Given an integer array, arr of size n, Find out all the possible distinct triplets that sum up to 0, i.e., 
if a triplet consists of a, b, c which belongs to arr and if a + b + c = 0, then print a, b, c.
'''


# A function to find triplets whose sum is equal to 0
def ThreeSum(arr, n):
	arr.sort()	#Sorting array
	for i in range(n-2):
		if i != 0 and arr[i-1] == arr[i] :
			continue
		# Initializing the two pointers, left and right
		left = i + 1	
		right = n - 1
		while left < right :
			lis = [arr[i], arr[left], arr[right]]	#Creating a list of three elements
			sumval = sum(lis)	#sumval is initialized with the sum of the elements of list
			if sumval == 0 :
				print(lis)	#Printing the list of triplets whose sum = 0
				while left < n-1 and arr[left] == arr[left+1] :
					left += 1
				while right > 0 and arr[right-1] == arr[right] :
					right -= 1
				left += 1
				right -= 1
			elif sumval > 0 :	#if sumval > 0, decrementing right by 1
				right -= 1
			else :				#if sumval < 0, incrementing left by 1
				left += 1


# Driver Code

# User inputs the the size of array 
n = int(input("Enter the size of an array: ")) 
arr = []
print("Enter ", n ," elements:")

# User inputs array elemnents
for i in range(n):
    arr.append(int(input()))

# A function call to Three Sum
print("The triplets which sum upto 0 are:") 
ThreeSum(arr, n)


'''
TEST CASES:
1.
Input: 
6
[-1, 0, 1, 2, -1, -4]
Output:
[-1, -1, 2]
[-1, 0, 1]

2.
Input:
8
[4, 0, 1, 3, -1, -3, -4, 2]
Output:
[-4, 0, 4]
[-4, 1, 3]
[-3, -1, 4]
[-3, 0, 3]
[-3, 1, 2]
[-1, 0, 1]

TIME COMPLEXITY: O(n^2), Due to two nested loops
SPACE COMPLEXITY: O(n), Because an additional list is created to store the triplets
where 'n' denotes the size of the array which user inputs
'''
