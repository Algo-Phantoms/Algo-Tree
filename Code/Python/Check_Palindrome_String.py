'''
Check the given string is palindrome or not
'''

def Check_Palindrome_String(str):
      #pointer placed at the start
      left = 0
      #Sign to check palindrome
      flag = 0
      #pointer placed at the end
      right = len(str)-1
      while left<=right:
               #inorder to ignore the elements that are not alphanumeric
               if str[left].isalnum(): 
                     pass
               else:
                     left+=1
               #inorder to ignore the elements that are not alphanumeric
               if str[right].isalnum():
                     pass
               else:
                     right-=1
               if str[left]!=str[right]:
                   break
               else:
                   left+=1
                   right-=1
      if left>right:
         flag+=1
      if flag==0:
         print("Not a Palindrome string")
      else: 
         print("Palindrome String")
str = input("Enter a String:")
str1 = str.lower() #coverting each string in lowercase
Check_Palindrome_String(str1) #function calling


'''
        Test Case:

     1).Input: Madam
        Output: Palindrome String

     2).Input: Was,it a rat i saw?
        Output: Palindrome String


        Time Complexity: O(N)
        Space Complexity: O(N)
        
''' 

