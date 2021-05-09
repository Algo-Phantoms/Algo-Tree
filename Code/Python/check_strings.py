#Ques: Find whether second string is present in first string or not.
#Language: Python3

'''
Given two string we need to check if second string is subsequence in first string without changing sequence of characters in any string.
In this approach recursively we traverse both strings from one side to other side (say from rightmost character to leftmost). If we find a matching character, we move ahead in both strings. Otherwise we move ahead only in b. 

input: Enter first string in which you want to check presence of another string as subsequence:         ----->a
       Second string which is to be checked:                        ------>b

output: 
    Yes! it is true that b is subsequence of a. / Nope! not possible.
'''


def find_sub(a,b,n,m):
    if n==0:
        return True
    if m==0:
        return False
    if a[n-1]==b[m-1]:
        return find_sub(a,b,n-1,m-1)

    return find_sub(a,b,n,m-1)


if __name__=="__main__":
    a=input('Enter first string in which you want to check presence of another string as subsequence:')
    b=input('Second string which is to be checked: ')
    if find_sub(a,b,0,0):
        print("Yes! it is true that b is subsequence of a.")
    else:
        print("Nope! not possible.")

"""
Time complexity: O(n)   ----->where n is the length of second string(b)

input: Enter first string in which you want to check presence of another string as subsequence: YADXCP
       Second string which is to be checked: AXP

output:Yes! it is true that b is subsequence of a.

input: Enter first string in which you want to check presence of another string as subsequence: YADXCP
       Second string which is to be checked: AXY 

output:Nope! not possible.

"""