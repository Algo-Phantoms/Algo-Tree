"""
Circular Queue
Problem Statement:
Circular Queue is a linear data structure which follows FIFO principle
The difference is that the last position is connected back to the first position to make a circle.
Perform insertion, deletion and traversal operations on Circular Queue.
"""


class CircularQueue:
  
    # Defining and initializing the class
    def __init__(self, quesize):
        # initializing start and end of queue with -1
        self.quehead = -1
        # initializing queue with zero value
        self.queue = [0 for k in range(quesize)]
        self.quetail = -1
        # size of queue as quesize
        self.size = quesize


    def traverse(self):
        # checking if the queue is Underflow
        if(self.quehead == -1):
            print ("Underflow")

        #else printing the elements of queue
        else:
            print("Elements in Queue: ")
            for k in range(self.quehead, self.quetail + 1):
                print(self.queue[k], end = " ")

    def enqueue(self, val):
        # checking if the queue is Overflow
        if (self.quetail + 1 == self.quehead):
            print("Overflow")

        # checking if the queue is Underflow
        elif (self.quehead == -1):
            self.quetail = self.quehead = 0
            self.queue[self.quetail] = val
            
        # else incrementing and adding the next element in queue
        else:
            self.quetail += 1
            self.queue[self.quetail] = val


    def dequeue(self):
        # checking if the queue is empty
        if (self.quehead == -1):
            print ("Underflow")

        # checking if the queue have one element
        elif (self.quetail == self.quehead):
            print(self.queue[self.quehead])
            self.quehead = self.quetail = -1

        # deleting for the rest of condition
        else:
            print(self.queue[self.quehead])
            self.quehead += 1


# input the size of the queue
size = int(input("Enter the size of queue: "))
# input the number of elements to be deleted
delete = int(input("Enter the number of elements to be deleted: "))
# creating object pf queue to access the elements and perform operations
queobj = CircularQueue(int(size))
# taking the input the elements from user
for i in range(0, size):
    key = int(input())
    queobj.enqueue(key) # adding them in queue
# printing the elements inside the queue
queobj.traverse()
print("\nDeleted values: ")
# deleting the elements of queue
for k in range(0, delete):
    queobj.dequeue()
# printing the elements inside the queue now
queobj.traverse()


"""
Test case 1 
input -
Enter the size of queue: 5
Enter the number of elements to be deleted: 2
1
2
3
4
5
output -
Elements in Queue: 
1 2 3 4 5 
Deleted values: 
1
2
Elements in Queue: 
3 4 5 

Test case 2
input -
Enter the size of queue: 10
Enter the number of elements to be deleted: 4
33
44
22
55
99
11
22
77
45
63
output -
Elements in Queue: 
33 44 22 55 99 11 22 77 45 63 
Deleted values: 
33
44
22
55
Elements in Queue: 
99 11 22 77 45 63 

Time Complexity: O(size) 
                since 'size' number of elements are inserted in Circular Queue
Space Complexity: O(size)
                 since creating a list and explicitly allocating memory
"""
