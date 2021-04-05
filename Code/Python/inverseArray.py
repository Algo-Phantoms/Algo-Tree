'''INVERSE OF AN ARRAY
If the array elements are swapped with their correseponding
indices,we get the inverse of an array

For Exaample:
Let arr be an array such as:
 arr=[2,4,1,0,3]
 In this array,at index[0]-2,index[1]-4,index[2]-1 and so on.

 Now,to find inverse of array ,swap the index and the value 
 of array
 After swaping ,arr=[3,2,0,4,1]

 Note:The elements must be unique and less than the length of array

Question-->
Input:
1)First line contains the number of test cases
2)Size of array
3)Array elements

Output-->
1)Contains t lines of output,inverse of each array

Sample Input:
2
5
2 4 1 0 3
4
1 3 0 2

Sample Output:
3 2 0 4 1
2 0 3 1

Time complexity: O(n)
'''
def inputElements(n):
    arr=[]
    for i in range(n):
         ele=int(input())
         arr.append(ele)
    print(arr)
    return arr
def inverseArray(lst):
    lst1=[]
    for i in range(0,len(lst)):
        k=lst[i]
        lst1.insert(k,i)
        print(lst1[k])
    return lst1
#main code
t=int(input()) 
for i in range(0,t):
    l=int(input())
    arr=inputElements(l)
    arr2=inverseArray(arr)
    print(arr2)



