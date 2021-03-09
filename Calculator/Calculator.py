print("1.Add")
print("2.Substract")
print("3.Multiply")
print("4.Divide")
print("4.Modulus")
op=int(input("Enter Operation(1-5): "))
if op==1:
    a=int(input("Enter A:"))
    b=int(input("Enter B:"))
    c=a+b
    print("Sum = ",c)
elif op==2:
    a=int(input("Enter A:"))
    b=int(input("Enter B:"))
    c=a-b
    print("Difference = ",c)
elif  op==3:
    a=int(input("Enter A:"))
    b=int(input("Enter B:"))
    c=a*b
    print("Product = ",c)
elif op==4:
    a=int(input("Enter A:"))
    b=int(input("Enter B:"))
    c=a/b
    print("Quotient = ",c)
elif op==5:
    a=int(input("Enter A:"))
    b=int(input("Enter B:"))
    c=a%b
    print("Modulus = ",c)
else:
    print("Invalid Operation")
