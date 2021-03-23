#Ques: Factorial of large numbers like 100,1000.
#Language: Python


def product(l,r):       #this is the main function which finds the factorial of given integers , it finds product in cretain range using recursive approach and everytime it divide the integer in two halves, which makes it more efficient
    if (l+1)<r:
        mid=(l+r)//2
        return product(l,mid)*product(mid+1,r)
    if l==r:
        return l
    return l*r

def factorial(n):  
    if n<2:         #as 1!=1 and 0!=1 so it returns 1 when integer is less than 2
        return 1
    return product(1,n)         #otherwise calls product function to do whole process

if __name__=="__main__":
    n=int(input('Enter an integer to find its factorial:'))
    print(factorial(n))


#input:   Enter an integer to find its factorial:50
#output:  30414093201713378043612608166064768844377641568960512000000000000

