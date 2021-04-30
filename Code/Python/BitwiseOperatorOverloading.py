
'''
Operator Overloading means giving extended meaning beyond their predefined operational meaning. 
For example operator + is used to add two integers as well as join two strings and merge two lists. 
It is achievable because ‘+’ operator is overloaded by int class and str class. 
One might have noticed that the same built-in operator or function shows different behavior for
objects of different classes, this is called Operator Overloading.
'''


# Python program for Bitwise operator overloading
 
 
class Solve():
    def __init__(self, value):
        self.value = value
 
    def __and__(self, obj):
        print("And operator overloaded")
        if isinstance(obj, Solve):
            return self.value & obj.value
        else:
            raise ValueError("Must be an object of class Solve")
 
    def __or__(self, obj):
        print("Or operator overloaded")
        if isinstance(obj, Solve):
            return self.value | obj.value
        else:
            raise ValueError("Must be an object of class Solve")
 
    def __xor__(self, obj):
        print("Xor operator overloaded")
        if isinstance(obj, Solve):
            return self.value ^ obj.value
        else:
            raise ValueError("Must be an object of class Solve")
 
    def __lshift__(self, obj):
        print("lshift operator overloaded")
        if isinstance(obj, Solve):
            return self.value << obj.value
        else:
            raise ValueError("Must be an object of class Solve")
 
    def __rshift__(self, obj):
        print("rshift operator overloaded")
        if isinstance(obj, Solve):
            return self.value & obj.value
        else:
            raise ValueError("Must be an object of class Solve")
 
    def __invert__(self):
        print("Invert operator overloaded")
        return ~self.value
 
 
# Driver's code
if __name__ == "__main__":
    num1 = int(input())
    num2 = int(input())
    a = Solve(num1)
    b = Solve(num2)
    print(a & b)
    print(a | b)
    print(a ^ b)
    print(a << b)
    print(a >> b)
    print(~a)



'''
Test Case 1:
Input:
    num1=10
    num2=12

Output:
    And operator overloaded
    8
    Or operator overloaded
    14
    Xor operator overloaded
    8
    lshift operator overloaded
    40960
    rshift operator overloaded
    8
    Invert operator overloaded
    -11

Time Complexity = O(1)
Space Complexity = O(1)
'''

    