"""

  Problem Statement: Python program to check given two strings are Anagram of each other or not .
    
    An anagram of a string is an  another string that contains the same characters but the order of characters can be different.
For example ,listen and silent are anagrams of each oter because all the characters in the string "listen" are present in string "silent".
So, listen and silent are anagrams of each other.
 
"""

# Solution:
def anagram(string1,string2):

#convert string1 to list of characters 
     list_string1=list(string1)

#sort list of characters 
     list_string1.sort()

#convert string2 to a list of characters

     list_string2=list(string2)

#sort list of characters

     list_string2.sort()

     if(list_string1==list_string2):
         print("Given strings are anagrams of eachother")
     else:
         print("Given strings are not anagrams of eachother")

#Take two strings as input from the user 

string1=input("enter string1:")
string2=input("enter string2:")
anagram(string1,string2)


"""

Time Complexity: O(nlogn)
Space complexity: O(length(string1+string2))

Explanation:
  Input:
  Enter string1: silent
  Enter string2: listen
  
  Output: Given strings are anagrams of eachother

 Input:
 enter string1: hello
 enter string2: world
 Output: Given strings are not anagrams of eachother.

"""

    
  
    