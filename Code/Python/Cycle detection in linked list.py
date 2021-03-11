#Program to Detect loop in Linked List;
#Algorithm is Floyd-Warshall Algorithm

# #The Algorithm just uses two pointer approach

# In this Algorithm we just initailize two pointer named as slow_pointer and fast_pointer and assign head of the linked list for traversing in the list then we assign slow to its next and fast to fast.next.next and we just check wheather slow and fast pointer meet at some point if yes their is cycle and if they end up with None thier is no cycle.

# Step 1: Initialize slow_pointer and fast_pointer to head.next
# Step 2: if slow_pointer, fast_pointer and fast_pointer.next is not none then we enter into loop and assign slow_pointer=slow_pointer.next and fast_pointer=fast_pointer.next.next
#Step 3:In every case of loop we just check wheather fast_pointer and slow_pointer meet if yes we break the statement and loop and return true statement about detect loop



#creating node class 
class Node:
    #creating constructor to create new node and assign data with new data and next with None
    def __init__(self,data):
        self.data=data
        self.next=None
        
#creating Linkedlist class for our main functions
class LinkedList:
    #constructor to assign new head of linked list
    def __init__(self):
        self.head=None
    
    #push function for adding new node in the list
    def push(self,new_data):
        new_node=Node(new_data)
        new_node.next=self.head
        self.head=new_node
    
    #printLinkedList for printing linked list if it not form loop
    def printLinkedList(self):
        temp=self.head
        while(temp is not None):
            print(temp.data)
            temp=temp.next
    
    #loop detection fucntion return true if detected 
    def Detectloop(self):
        slow_pointer=self.head
        fast_pointer=self.head
        while(slow_pointer and fast_pointer and fast_pointer.next):
            slow_pointer=slow_pointer.next
            fast_pointer=fast_pointer.next.next
            if(slow_pointer == fast_pointer):
                return True

#driver's Code
createLinkedList=LinkedList()
createLinkedList.push(2)
createLinkedList.push(3)
createLinkedList.push(5)
createLinkedList.push(1)

createLinkedList.head.next.next.next=createLinkedList.head
if(createLinkedList.Detectloop()==True):
    print("Loop detect")
else:
    print("Loop not detected")
    createLinkedList.printLinkedList()
    

#test case 1:
# createLinkedList.push(12)
# createLinkedList.push(32)
# createLinkedList.push(5)
# createLinkedList.push(10)
# output:
# Loop not detected
# 10
# 5
# 32
# 12

# test case 2:
# createLinkedList.push(2)
# createLinkedList.push(3)
# createLinkedList.push(5)
# createLinkedList.push(1)

# createLinkedList.head.next.next.next=createLinkedList.head
# output:
#     Loop detect

    
#time Complexity:O(n)
#space complexity:O(1)
