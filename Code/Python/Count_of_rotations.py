#In this problem we have to state the count of rotations a sorted array has 
#gone through.
# For Ex:
#        4 5 6 1 2 3 4 
#       The above array has gone through 3 rotations  


n=int(input("Enter the length of the array:\n"))
arr=[]

#taking input
for i in range(0,n):
    print("Element",i+1)
    ele = int(input())
    arr.append(ele)

c=0
mini=1000000

#This loop will find out the index of the minimum element
for ele in arr:
    if ele<mini:
        mini=ele
        min_in=c
    c=c+1

#The index of minimum elemt will give us the number of rotations
print("Number of rotataions = ",min_in)

#        TEST CASES
#
#  1)INPUT:
#          Enter the length of the array:
#          5
#          10 20 30 1 2
#   OUTPUT:
#          Number of rotataions = 3
#   
# 2)INPUT:
#          Enter the length of the array:
#          5
#          1 2 3 4 5
#   OUTPUT:
#          Number of rotataions = 0
#
#  Time Complexity: O(n)
#  Space Complexity: O(n)   Here n is the length of the array


