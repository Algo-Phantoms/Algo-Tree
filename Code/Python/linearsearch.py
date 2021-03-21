'''
 
Linear search, also known as sequential search, is a search algorithm which examines each element in the order it is presented to find the specified data.
 
'''
 
def linearSearch(item,l):
    found = False
    position = 0
    while position < len(l) and not found:
        if l[position] == item:
            found = True
        position = position + 1
    return found
    
l = list(map(int,input().strip().split()))
item = int(input())

itemFound = linearSearch(item,l)
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
 
Space Complexity : O(n)

'''
