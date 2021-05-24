# In this problem we are provided with four numbers A,B,C and N. A,B and C are the 
# first three numbers of a series called as geek-onacci series. In this series the  
# nth number is the sum (n-1)th, (n-2)th and (n-3)th number. Our task is to find the
# nth number.


#This function will find the value of the nth term using recursion 
def geek_onacci(a,b,c,n):
    
    #base case
    #Since the 4th term will be the sum of first three terms
    if n==4:
        return (a+b+c)
        
    else:
        #recursive call
        return geek_onacci(b,c,a+b+c,n-1)
        
#main function

#taking input a,b,c and n         
a=int(input())
b=int(input())
c=int(input())
n=int(input())

#Calling the function geek_onacci
print(geek_onacci(a,b,c,n))


#        TEST CASES
#
#     1)INPUT: 
#              1 5 7 4
       
#       OUTPUT:
#               13
#     2)INPUT: 
#              2 8 9 6
       
#       OUTPUT:
#               64
# 
#          Time Complexity: O(n)
#          Space Complexity: O(n)

