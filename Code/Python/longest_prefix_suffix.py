''' 

Prefix refers to a word at the beginning of another word, and suffix refers to a word added at the end of a word. Longest Prefix Suffix problem refers to finding the length of the longest prefix which is also suffix, of a string s, provided the prefix and suffix should not overlap. 

'''

#Longest prefix suffix function
def longest_prefix_suffix(s):
    length=len(s)
    #Iterate i through half the length of string s
    for i in range(length//2,0,-1): 
        #Prefix is from 0th index to ith index
        prefix=s[0:i]   
        #Suffix is the remaining part of string. That is, length minus prefix
        suffix=s[length-i:length] 
        #If prefix and suffix are equal, return length of string. Else, return 0
        if(prefix==suffix): 
            return i;
    return 0;

#Obtaining input from user
s=input()

#Calling the function
l=longest_prefix_suffix(s)

#Displaying output
print(l)

'''
 
Test Case :
 
Input : rrrrr
 
Output  : 2 

Input : hellohe
 
Output  : 2
 
Time Complexity: O(n)
 
Space Complexity : O(1)

'''
