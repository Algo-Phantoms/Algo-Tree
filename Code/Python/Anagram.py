"""
Problem Statement: Python program to check given two strings are Anagram of each other or not .
    
    An anagram of a string is an  another string that contains the same characters but the order of characters can be different.
For example ,listen and silent are anagrams of each oter because all the characters in the string "listen" are present in string "silent".
So, listen and silent are anagrams of each other. 
     At First convert both strings to list of characters and sort them using sort() methid and check if both two list strings are equal print 
    strings are anagrams of each other ,else print strings are not anagrams of eachother. 
 """
def anagram(string1,string2):
     list_string1=list(string1)
     list_string1.sort()
     list_string2=list(string2)
     list_string2.sort()
     if(list_string1==list_string2):
         print("Given strings are anagrams of eachother")
     else:
         print("Given strings are not anagrams of eachother")
string1=input("enter string1:")
string2=input("enter string2:")
anagram(string1,string2)

"""
Test cases:
  Input:
  Enter string1: silent
  Enter string2: listen
  Output: Given strings are anagrams of eachother 
Because here after sorting string1 and string2 ,list_string1=['e','i','l','n','s','t'] and list_string2=['e','i','l','n','s','t']. As list_string1 = list_string2 the given 
strings are anagrams of each other.
 
 Input:
 enter string1: hello
 enter string2: world
 Output: Given strings are not anagrams of eachother.
Because here after sorting string1 and string2 ,list_string1=['e','h','l','l','o'] and list_string2=['d','l','o','r','w']. As list_string1 is not equal to list_string2 the given 
strings are  not anagrams of each other.

Time Complexity: O(nlogn) .Because time complexity for sort() function is O(nlogn) where n is the size of input that is the length of string.
Space complexity: O(length(string1+string2))

"""
