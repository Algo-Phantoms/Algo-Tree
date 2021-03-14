'''
Problem Statement : Given an array of integers find the longest increasing subsequence in the array.
Example : Suppose we have an array 1,5,2,3,4,6 the longest increasing subsequence 1,2,3,4,6 of length 5.
Solution : We can use dynamic programming. we can take n lists where list[i] represents the 
longest increasing subsequence that ends with array[i].
Using list[0] to list[i-1] and arr[i] we can get the longest possible increasing subsequence.
Note that LIS denote Longest Increasing Subsequence and if two sequences have highest length print any one.
'''


def lis(arr):
	size = len(arr) #size of the array
	dp = [[] for i in range(size)] #initializing size empty lists. 
	dp[0] = [arr[0]]
	for i in range(1,size):
		curr_ind = -1   #Represents the maximum length array which forms an LIS with arr[i].
		for j in range(i):
			if arr[j]<arr[i]:
				if curr_ind == -1:  #If no list found before, this will be the maximum
					curr_ind = j  
				elif len(dp[j]) > len(dp[curr_ind]): #Else compare with the 
													 #maximum found till j-1.
						curr_ind = j

		dp[i] = dp[curr_ind].copy()  #dp[i] becomes sequence of max_length 
									 #found(where max element < arr[i]) + arr[i]
		dp[i].append(arr[i]) 

	#Find the maximum length sequence among all.
	ans_ind = 0  
	for i in range(1,size):
		if len(dp[ans_ind]) < len(dp[i]):
			ans_ind = i

	print("Length of the longest increasing subsequence is "+str(len(dp[ans_ind])))
	print("And the sequence is : ")
	for ele in dp[ans_ind]: #print the sequence.
		print(ele,end = " ")

print("Enter the numbers in the array")
arr = list(map(int,input().split())) #list to store the array.
lis(arr) #calling the lis function

'''
Time complexity : We ran two for loops so the time complexity becomes O(size^2)
Space complexity : We use size number of lists where list size in worst case 
can be size. So space complexity becomes O(size^2).

Sample Input 1: 
Enter the numbers in the array
1 5 2 3 4 6
Sample Output 1:
Length of the longest increasing subsequence is 5
And the sequence is :
1 2 3 4 6
Sample Input 2: 
Enter the numbers in the array
10 2 9 3 5 4 6 8
Sample Output 2:
Length of the longest increasing subsequence is 5
And the sequence is :
2 3 5 6 8
Sample Input 3: 
Enter the numbers in the array
3 2 6 4 5 1
Sample Output 3:
Length of the longest increasing subsequence is 3
And the sequence is :
3 4 5
Explanation: Both 2 4 5 and 3 4 5 have length 3. So anyone can be considered.
'''