def factorial(num):
    if((num == 0) or (num == 1)):
        return 1
    else:
        return num * factorial(num - 1)


number = int(input(" Please enter any Number to find factorial : "))

fact = factorial(number)
print("The factorial of %d  = %d" %(number, fact))
