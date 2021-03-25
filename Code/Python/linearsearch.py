'''
 
Linear search, also known as sequential search, is a search algorithm which examines each element in the order it is presented to find the specified data.
 
'''
#Linear Search Function
def linearSearch(item,l):
    found = False
    position = 0
   #Traversing through array and checking if element is present 
    while position < len(l) and not found:
        if l[position] == item:
            found = True
        position = position + 1
    return found

#Obtaining the list  from input
l = list(map(int,input().strip().split()))
item = int(input())

#Calling the linear search fuction 
itemFound = linearSearch(item,l)

#Displaying the output
if itemFound:
    print ('True')
else:
    print ('False')
 
'''
 
Test Case :
 
Input : 100 56 789 456 321
        789
 
Output  : True 

Input : 1000 2000 3000 5000
        4000
 
Output  : False
 
Time Complexity: O(n)
 
Space Complexity : O(1)

'''
