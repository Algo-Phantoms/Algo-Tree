#Python code to Reverse Linked List

# Each element in the Linked List is a Node
# Node consist of two things 1:Data 2:address to next node

#We are using iterative process to reverse a linked list

class Node: #created a class name Node

    #creating a constructor to initialise data and next(pointing to next node)
    #self is keyword in python that has all instance of the class
    def __init__(self,data):
    
        self.data=data #1st field:Data field
        self.next=None #2nd field:Address field
    

class LinkedList: #creating a class where all the required function of linked list will be initialized
    #creating a constructor to initialise head
    def __init__(self):
    
        self.head=None
    
    #function to reverse a linked List
    def reverse(self):
    #we will assign two pointer prev and current
    #prev will point to the current's prev value
    #current will point to current value
        prev=None 
        current=self.head
        while(current is not None):
            next=current.next  #we will assign next pointer to get value of current's next value
            current.next=prev
            prev=current
            current=next
        
        self.head=prev
    #push function to insert new date
    def push(self,new_data):
        new_node=Node(new_data)
        new_node.next=self.head
        self.head=new_node
    
    #print function to print the linked list
    def printLinkedList(self):
        temp=self.head
        while(temp is not None):
            print(temp.data)
            temp=temp.next
            
            
#main code or Driver's Code
create_linkedlist=LinkedList()
item=1
while(item<=5):
    x=int(input("Enter item "+str(item)+" "))
    create_linkedlist.push(x)
    item=item+1
    
print("Given Linked List:")
create_linkedlist.printLinkedList()
create_linkedlist.reverse()
print("Reverse Linked List:")
create_linkedlist.printLinkedList()


#test-case 1: 1 2 3 4 5
#output:Given Linked List:
# 5
# 4
# 3
# 2
# 1
# Reverse Linked List:
# 1
# 2
# 3
# 4
# 5


#test case 2:
# Enter item 1 54
# Enter item 2 22
# Enter item 3 33
# Enter item 4 89
# Enter item 5 100
# Given Linked List:
# 100
# 89
# 33
# 22
# 54
# Reverse Linked List:
# 54
# 22
# 33
# 89
# 100

#time-complexity:O(n)
#space-complexity:O(n)
