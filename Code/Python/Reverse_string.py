#using function


def reverseString(s):
    
    output = ''
    for i in range(len(s)):
        output = s[i] + output
    return output

s = input()
ans = reverseString(s)
print(ans)       

      

"""using slice syntax"""

s = input()
ans = s[::-1]
print(ans) 


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

 
