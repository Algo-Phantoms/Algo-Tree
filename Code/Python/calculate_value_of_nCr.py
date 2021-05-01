#This is the program to calcuate the nCr.
#In this method used for finding nCr ,while calculating nCr   n(n-1)(n-2)---(n-r+1)/r(r-1)---1
#we divide both numerator and denominator by gcd() numbers as to make calculation simple 
#and to ensue the result may not go out of range

def gcd(num1 , num2) :
    '''This function is for calculating greatest common divisor'''
    if num2 == 0:
        return num1
    return gcd(num2 , num1%num2)

def nCr(n , r) :
    '''This function takes in input n and r, calculate nCr'''
    r = min(r , n-r)
    '''if r is equal to zero then nC0 is always equal to 1'''
    if r == 0 : 
        return 1
        '''if r is equal to 1 then nC1 is always equal to n'''
    if r == 1 :
        return n
    n_limit = n - r + 1
    numerator = 1     
    denominator = 1
    '''while loop will perform the calculation for nCr n(n-1)(n-2)---(n-r+1)/r(r-1)(r-2)--1'''
    while n >= n_limit and r >= 1 :   
        numerator *= n
        denominator *= r
        divisor = gcd(numerator , denominator)
        numerator /= divisor
        denominator /= divisor
        n = n - 1
        r = r - 1
    return int(numerator/denominator)

n = input("Enter the value of n in nCr ")
r = input("Enter the value of r in nCr ")
n = int(n)
r = int(r)
print(nCr(n , r))
'''
Test Case: 1
Input :
Enter the value of n in nCr 20
Enter the value of r in nCr 10

Output:
184756

Test Case: 2
Enter the value of n in nCr 25
Enter the value of n in nCr 12
3268760
    
Time complexity : O(rlog(n))
where r and n have their usual meaning as in nCr
Space complexity: O(1)
'''
