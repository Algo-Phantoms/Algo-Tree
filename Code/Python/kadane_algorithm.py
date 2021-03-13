#kadane's algorithm 
#Given any array of integers, the algorithm to find the maximum subarray sum is called Kadane’s Algorithm.
#Problem statement: Given Array Of N integers a1, a2, a3, ….. aN, find the maximum sum of sub-array of a given array.

#The basic idea of kadane's algorithm is to look for positive contigious sub-array, here current_sum keeps track of it.
#In each loop we compare the current_sum with best_sum (i.e Maximum Sum) and update if current becomes larger than best_sum.

def kadane(array, size):
	current_sum = 0
	best_sum = 0
	for i in range(size):
		current_sum += array[i]
		if best_sum < current_sum:
			best_sum = current_sum
		if current_sum < 0:
			current_sum = 0
	return best_sum

#To handle all negative integer array, to cover all edge cases.

def kadaneAll(array,size):     
    current_sum = array[0]
    best_sum = array[0] #instead of initializing it with 0, we initialize with first element, to handle negatives.
     
    for i in range(1,size):
    	# optimizing in single line
        current_sum = max(array[i], current_sum + array[i])
        best_sum = max(best_sum,current_sum)
         
    return best_sum



if __name__ == '__main__':
	# Uncomment below lines to test on manual input
	# array = []
	# print("Enter size of the input array")
	# n = int(input())
	# print("Enter integers in the array")
	# for i in range(n):
	# 	array.append(int(input()))
	# print("Maximum sum subarray is: ",kadane(array,n))

	#sample test 1
	arr1 = [1,6,7,-2,11,-9,0]
	print("Maximum sum subarray is: ",kadane(arr1,len(arr1)))
	# sample test 2: to test when array contains all negative integers
	arr2 = [-2, -3, -4, -1, -2, -1, -5, -3]
	print("Maximum sum subarray is: ",kadaneAll(arr2,len(arr2)))
	# print(kadane(a,len(a)))

	#Output
	#Maximum sum subarray is:  23
	#Maximum sum subarray is:  -1
	
#Time complexity: O(n) and Space Complexity: O(1)


