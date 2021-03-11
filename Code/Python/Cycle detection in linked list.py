#Program to Detect loop in Linked List;
#Algorithm is Floyd-Warshall Algorithm

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
    
    
#time Complexity:O(n)
#space complexity:O(1)

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