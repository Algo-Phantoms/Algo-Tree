"""
Problem Statement: Implementation of Queue using Stack.

Solution:
This problem can be apptoached in two different ways:
-> Method 1: Making enQueue operation costly
->Method 2: Making deQueue operation costly

This code is an implementation of the second method.
Method 2 is definitely better than method 1.
Method 1 moves all the elements twice in enQueue operation,
while method 2 (in deQueue operation) moves the elements once
and moves elements only if stack2 empty.
So, the amortized complexity of the dequeue operation becomes O(1) .

Procedure:
In this method, in en-queue operation, the new element is entered at the top of stack1.
In de-queue operation, if stack2 is empty then all the elements are moved to stack2,
and finally top of stack2 is returned.
"""

class queue:
    def __init__(self):
        self.__s1 = []
        self.__s2 = []
        self.__size = 0

    def enqueue(self, data):
        self.__size += 1
        self.__s1.append(data)  # O(1)

    def dequeue(self):
        if self.isEmpty():
            return -1
        while len(self.__s1) != 1:
            self.__s2.append(self.__s1.pop())
        data = self.__s1.pop()
        while len(self.__s2) != 0:
            self.__s1.append(self.__s2.pop())
        self.__size -= 1
        return data

    def front(self):
        if self.isEmpty():  # O(N)
            return -1
        return self.__s1[0]

    def size(self):
        return self.__size

    def isEmpty(self):
        return self.__size == 0

    def display(self):
        for i in range(len(self.__s1)):
            print(self.__s1[i], "--->", end='')
        print()
        return


if __name__ == "__main__":
    
    q = queue()
    q.enqueue(1)
    q.enqueue(10)
    q.enqueue(15)
    q.enqueue(100)

    q.display()

    print(q.size())

    print(q.dequeue())

    q.display()

    print(q.front())

    print(q.size())

"""
Expected output:
1 --->10 --->15 --->100 --->
4
1
10 --->15 --->100 --->
10
3
"""


"""
Complexity Analysis:

Time Complexity:
   Push operation: O(1)
   Pop operation: O(N) (worst-case)

Auxiliary Space: O(N)

"""
