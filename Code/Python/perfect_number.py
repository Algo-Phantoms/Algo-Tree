'''

A program to check whether the given number is a perfect number or not.

Perfect number is a positive whole number that is equal to the sum of its proper divisors.
OR It is equal to its aliquot sum which is the sum of divisors excuding the number.

The first perfect number is 6 as the sum of its proper positive divisors, 1,2 and 3 is 6.
Other perfect numbers are 28, 496, 8128,etc.

'''

#Function to check perfect number
def check_perfect_number(number):
    
    
    #initialising the sum with 1 because 1 is the factor of every number
    sum_of_divisor=1
    
    
    #checking till the half of the number, 
    #because further the multiples will be greater then the number
    for i in range(2,int(number/2)+1):
        
        #divisibilty check
        if(number%i==0):
            sum_of_divisor+=i
            
    
    return number==sum_of_divisor




#main
num=int(input("Enter any number: "))


#function call
print(check_perfect_number(num))


'''

Time complexity: O(n)


Test cases:
1. Enter any number:6
   True
   (The factors are 1,2,3 excluding the number
   =>1+2+3=6)

2. Enter any number: 15
   False
   (The factors are 1,3,5 excluding the number
   =>1+3+5=9!=15)

'''
