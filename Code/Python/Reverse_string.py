#using function


def reverseString(s):
    
    output = ''  
    for i in range(len(s)):         """constantly adding character to string, creating a copy each time"""
        output = s[i] + output
    return output

s = input()
ans = reverseString(s)
print(ans)       

#Time Complexity = O(n*n)
#Space Complexity = O(n)
      

"""using slice syntax"""

s = input()
ans = s[::-1]
print(ans) 

#Time Complexity = O(n)
#Space Complexity = O(n)

#test cases
"""
INPUT 1:
s = 'algotree'

OUTPUT:
eertogla

INPUT2:
s = 'restaurant'

OUTPUT:
tnaruatser

"""

 
