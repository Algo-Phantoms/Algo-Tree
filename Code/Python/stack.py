"""
Problem Statement :
Implementation of Stack in Python

Stack: A stack is a linear data-structure.
It stores elements by following the LIFO/FILO order.
-> FILO: First In Last Out
-> LIFO: Last In First Out

Advantages of using Stacks:
-> Helps you to manage the data in a Last In First Out(LIFO) method which is not possible with Linked list and array.
-> When a function is called the local variables are stored in a stack, and it is automatically destroyed once returned.
-> A stack is used when a variable is not used outside that function.
-> It allows you to control how memory is allocated and deallocated.
-> Stack automatically cleans up the object.
-> It does not get easily corrupted

Main Stack Operations :
-> Push: Adds an item in the stack.
-> Pop: Removes an item from the stack.
-> Peek/Top: Returns top element of stack.
-> isEmpty: Returns true if stack is empty, else false.
"""


class Stack:
    def __init__(self):
        self.__stack = []
        self.__size = 0

    def push(self, data):
        """
        function to push element in the stack
        time-complexity: O(1)
        space-complexity: O(1)
        """
        self.__stack.append(data)
        self.__size += 1

    def pop(self):
        """
        fucntion to pop element from stack
        time-complexity: O(1)
        space-complexity: O(1)
        """
        if self.isEmpty():
            print("Stack is empty.")
            return
        value = (self.__stack.pop())
        self.__size -= 1
        return value

    def peek(self):
        """
        return the topmost element of the stack
        time-complexity: O(1)
        space-complexity: O(1)
        """
        return(self.__stack[-1])  # stack follows LIFO order

    def size(self):
        """
    returns the current size of the stack
        time-complexity: O(1)
        space-complexity: O(1)
        """
        return self.__size

    def isEmpty(self):
        """
        time-complexity: O(1)
        space-complexity: O(1)
        """
        return self.__size == 0

    def display(self):
        """
        prints the stack from top to bottom
        time-complexity: O(n) ; n is the size of the stack
        space-complexity: O(1)
        """
        if self.isEmpty():
            print("Nothing to display, the stack is empty.")
            return
        print("Stack from top to bottom:")
        for i in self.__stack[::-1]:
            print(i)


"""Test Case"""
if __name__ == "__main__":
    s1 = Stack()

    s1.display()

    s1.push(10)
    s1.push(12)
    s1.push(20)
    s1.display()

    print(s1.pop())

    print(s1.peek())

    s1.display()

    print(s1.isEmpty())

    while not s1:
        s1.pop()
    print()
    s1.display()
    print(s1.isEmpty())

"""
Expected Output:

Nothing to display, the stack is empty.

Stack from top to bottom:
20
12
10

20

12

Stack from top to bottom:
12
10

False


Stack from top to bottom:
12
10
False
"""
