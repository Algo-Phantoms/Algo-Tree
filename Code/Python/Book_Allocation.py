'''
PROBLEM STATEMENT:
Given an array of integers of size n, where n denotes number of books and each element of an array denotes the number of pages in the ith book, also given another integer 
denoting number of students. The task is to allocate books to the given number of students so that maximum number of pages allocated to a student is minimum. A book will be 
allocated to exactly one student and each student has to be allocated atleast one book. Allotment should be in contiguous order, for example, a student cannot be allocated 
book 1 and book 3, skipping book 2. Calculate and return that minimum possible number. Return -1 if a valid assignment is not possible.
'''


# Function to check whether it is possible to allocate books using the current minimum value
def IsPossible(lis, n, stud, minval): 

    students = 1
    sumval = 0
  
    # Iterating over the books
    for i in range(n): 
  
        # If the number of pages in a book is greater than the minimum value, then the minimum value chosen cannot be used to alloacte books 
        if (lis[i] > minval): 
            return False
  
        # Counting number of students required for allocating minval pages
        if (sumval + lis[i] > minval): 
  
            #incrementing students by 1 
            students += 1
  
            # Updating current value of sum
            sumval = lis[i] 
  
            # If more number of students are required than the given number of students, then also it is not possible to allocate books
            if (students > stud): 
                return False
  
        else: 
            sumval += lis[i] 
  
    return True
  
    
# Function to find the maximum number of pages allocated to a student is minimum
def MinPages(lis, n, stud): 
  
    sum = 0
  
    # If number of students are more than number of books, we'll return -1 because all the students won't get a book
    if (n < stud): 
        return -1
  
    #Finding the sum of all the pages 
    for i in range(n): 
        sum += lis[i] 
  
    low, high = 0, sum
    ans = 10**9;
    
    while (low <= high):
        mid = (low + high) // 2

        if (IsPossible(lis, n, stud, mid)): 
  
            # If possible, them comparing the mid value with the answer that we have so far
            ans = min(ans, mid)   
            # Because the number of pages are given in ascending order and we are looking for the minimum value possible, so for the next possible answer, we will reduce our search by decreasing high to mid-1
            high = mid - 1
  
        else: 
            # If it is not possible to allocate books using mid value as the minimum value, then we will look for the minimum element in the other half that is low will be increased to mid + 1
            low = mid + 1
  
    #Returning the final answer
    return ans


# Driver Code
n = int(input("Enter the size of an array: ")) 
lis = []
print("Enter ", n ," elements:")
# User inputs number of pages in each book in ascending order
for i in range(n):
    num = int(input())
    lis.append(num)
stud = int(input("Enter the number of students: "))
  
# A function call to MinPages
print("Minimum number of pages are: ",  MinPages(lis, n, stud)) 


'''
TEST CASES:

1.
Input: 
Enter the size of an array: 4
Enter 4 elements:
12
34
67
90
Enter the number of students: 2

Output:
Minimum number of pages are: 113

Explanation:
There are 2 students. Books can be allocated in the following way: 
1) [12] and [34, 67, 90]
student 1 gets 12 pages
student 2 gets 34 + 67 + 90 = 191 pages
Maximum of the two = 191
2) [12, 34] and [67, 90]
student 1 gets 12 + 34 = 36 pages
student 2 gets 67 + 90 = 157 pages 
Maximum of the two = 157 pages
3) [12, 34, 67] and [90]
student 1 gets 12 + 34 + 67 = 113 pages
student 2 gets 90 pages
Maximum of the two = 113 pages

Out of the 3 cases, Option 3 has the minimum pages = 113.

2.
Input: 
Enter the size of an array: 5
Enter 5 elements:
34
56
67
78
89
Enter the number of students: 6

Output:
Minimum number of pages are: -1

Explanation:
Because number of students are more than number of books. Therefore, there is no valid
assignment possible.

TIME COMPLEXITY: O(N*LOG(Sum of pages))
SPACE COMPLEXITY: O(1)
'''
