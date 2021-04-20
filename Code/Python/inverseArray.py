'''INVERSE OF AN ARRAY
Problem statement:   If the array elements are swapped with their correseponding
                     indices,we get the inverse of an array
NOTE: The elements must be unique and less than the length of array.
'''

#inserts the elements in an array of size n
def inputElements(n):
    arr=[]
    for i in range(n):
        #enter element to insert in array
         element=int(input())
         arr.append(element)
    print("original array:",arr)
    return arr
  
#function to find inverse of array
def inverseArray(lst):
    inverted_array=[]
    for i in range(0,len(lst)):
        k=lst[i]
        inverted_array.insert(k,i)
    return inverted_array

#main code
# enter length of array
array_length=int(input())
arr=inputElements(array_length)
arr2=inverseArray(arr)
print("Inverse of array :",arr2)

'''
TestCases :
Input :
5
2
4
1
0
3

Output:
original array: [2,4,1,0,3]
Inverse of array: [3,2,0,4,1]

Input :
4
1
3
0
2

Output :
Original array:[1,3,0,2]
Inverse of array:[2,0,3,1]

Time Complexity: O(n)  for traversing array of characters where size is n
Space Complexity:O(n),where n is size of array

'''
