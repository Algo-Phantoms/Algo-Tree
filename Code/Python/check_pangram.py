'''

Program to check if a given string is pangram or not

A pangram is a sentence containing every letter in the English Alphabet.

'''

#importing the string module
from string import *

#Function to check the string
def pangram(string):
    
    
    for alpha in ascii_lowercase:
        
        #checking for all the alphabets in the input string
        #converting all the letters in lowercase
        
        if alpha not in string.lower():   
            return False
    
    
    return True


#main
string = input("Enter any string: ")


#Function call
if(pangram(string) == True):
    
    print("\n The given string is a pangram")
          
else:
    print("\n The given string is not a pangram")


    
''' 
Test cases: 

1) Input: The Quick Brown Fox Jumps Over The Lazy Dog
   Output: The given string is a pangram

2) Input: 2brown5! #(including special characters and digits)
   Output: The given string is not a pangram


Time complexity: O(n)
Space Complexity : O(1)
'''
