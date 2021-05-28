''' 
-  In this program we have to tell whether a given number
   is trimorphic or not.
-  A trimorphic number is a number whose cube's last digit 
   is equal to the last digit of the number itself.
-   For Ex:  
           If number=10
               cube=1000
            Since last digit to 1000 and 10 both are 0. 
            Therefore, 10 is a Trimorphic number.
'''

num=int(input())
flag=0
cube_power=num*num*num
while num!=0:
    if num%10!=cube_power%10:
        flag=1
        break
    num//=10
    cube_power//=10
if flag==0:
    print("The given number is Trimorphic")
else:
   print("The given is not number is Trimorphic")

'''    TEST CASES
    
    1)Input: 
            Enter the Number
            24
    2)Output:
            The given number is Trimorphic
    
     1)Input: 
            Enter the Number
            2
    2)Output:
            The given number is not Trimorphic

    Time Complexity:O(1)
    Space Complexity:O(1)
'''