"""Problem Description:
Implementation of stack using Linked List.

A stack can be easily implemented through linked list.
In this implementation,
the top pointer of the stack is “head” of the linked list where pushing and popping items take place.
First node have null in link field and second node link have first node address in link field.
It continues so on and last node address in “top” pointer.

The main advantage of using linked list over an arrays in stack implementation is-
it can shrink or grow as much as needed unlike fixed size of array

The main Stack Operations are:

->push() : Insert the element into linked list nothing but which is the top node of Stack.
->pop() : Return top element from the Stack and move the top pointer to the second node of linked list or Stack.
->peek()/top(): Return the top element.
->display(): Print all element of Stack.

[Reference for Description]->(https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/)
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.ref = None


class Stack:
    def __init__(self):
        self.__head = None
        self.__size = 0

    def push(self, data):
        # adds an element at the beginning
        self.__size += 1
        new_node = Node(data)
        new_node.ref = self.__head
        self.__head = new_node

    def pop(self):
        # deletes element from beginning
        if self.isEmpty():
            print("Stack is empty.")
            return
        self.__size -= 1
        print(self.__head.data)
        self.__head = self.__head.ref

    def top(self):
        # prints the topmost element, i.e, head in the case of LL
        if self.isEmpty():
            print("Stack is empty.")
            return
        print(self.__head.data)

    def isEmpty(self):
        return(self.__size == 0)

    def display(self):
        # displays the stack from top to bottom
        n = self.__head
        if n is None:
            print("Empty!")
            return
        while n is not None:
            print(n.data)
            n = n.ref


if __name__ == "__main__":
    s2 = Stack()
    print("Enter values to push in the stack: ")
    value = [ele for ele in input().split()]
    for i in range(len(value)):
        s2.push(value[i])
    print("The stack is:")
    s2.display()
    print('\nThe first element which is removed is: ')
    s2.pop()
    print('\nThe topmost element of the stack is:')
    s2.top()
    print("\nThe stack is:")
    s2.display()


"""Time-Complexity of the program:
push(): O(1)
pop(): O(1)
top(): O(1)
display(): O(N)
"""

"""Test-Cases:

>>>
Enter values to push in the stack:
10 15 23 42
The stack is:
42
23
15
10

The first element which is removed is:
42

The topmost element of the stack is:
23

The stack is:
23
15
10

>>>
Enter values to push in the stack:
Anamika
The stack is:
Anamika

The first element which is removed is:
Anamika

The topmost element of the stack is:
Stack is empty.

The stack is:
Empty!

>>>
Enter values to push in the stack:
Anamika 1 QWERTY 22 key 87
The stack is:
87
key
22
QWERTY
1
Anamika

The first element which is removed is:
87

The topmost element of the stack is:
key

The stack is:
key
22
QWERTY
1
Anamika
"""
