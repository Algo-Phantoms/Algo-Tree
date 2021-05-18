'''
PROBLEM STATEMENT:
Given an array, arr of size n with elements ranging from 1 to n. In the given array, one number(from 1 to n) is missing and one is repeating.
For example: for n = 6, given array is 1 6 3 5 1 2, in this array 4 is missing and 1 is repeating.
The task is to find these repeatng and missing numbers in the array.

APPROACH:
The approach is to simply use the mathematical formulas for summation of n numbers:
sum of n elements, sumn = n*(n+1)/2
and sum of squares of n elements, sumsqn = n*(n+1)*(2*n+1)/6
Now, let us assume x is the repeating number and y is the missing number
total denotes the sum of all the numbers present in the array, and totalsq denotes the sum of squares of numbers present in the array.
Therefore, we get
sumn = total - x + y, i.e.,
=> x - y = total - sumn ----- (1)
Also, 
sumsqn = totalsq - x^2 + y^2
=> sumsqn = totalsq - ((x + y)*(x - y))	
=> sumsqn = totalsq - ((x + y)*(total - sumn))		{using (1)}
=> x + y = (sumsqn - totalsq)/(sumn - total) ----- (2)
Now, we have two equations and two variables, therfore these equations can easily be solved. The values of x and y are:
x = (((sumsqn - totalsq)/(sumn - total)) + total - sumn)/2
y = x - total + sumn
'''

#Function to find repeating and missing number in an array
def RepMissNum(arr, n):
	# sum of n numbers
	sumn = n*(n+1)/2
	# sum of numbers present in the array
	total = sum(arr)
	# sum of squares of n numbers
	sumsqn = n*(n+1)*(2*n+1)/6
	totalsq = 0
	# finding sum of squares of numbers present in the array
	for i in range(n):
		totalsq += arr[i]**2
	# Using formulas mentioned above to find the repeating and missing numbers
	rep = int((((sumsqn - totalsq)/(sumn - total)) + total - sumn)/2)
	miss = int(rep - total + sumn)
	print("Repeating number is: ", rep)
	print("Missing number is: ", miss)

# Driver Code
# User inputs the the size of array 
n = int(input("Enter the size of an array: ")) 
arr = []
print("Enter ", n ," elements:")

# User inputs array elemnents
for i in range(n):
    arr.append(int(input()))

# A function call to find repeating and missing number
RepMissNum(arr, n)


'''
TEST CASES:
1.
Input:
5
[4, 3, 1, 2, 1]
Output:
Repeating number is: 1
Missing number is: 5

2.
Input:
8
[6, 2, 7, 4, 5, 1, 6, 8]
Output:
Repeating number is: 6
Missing number is: 3

TIME COMPLEXITY: O(n), due to a single for loop used to calculate sum of squares of numbers in the array, where 'n' denotes size of array
SPACE COMPLEXITY: O(1), no extra space used.
'''
