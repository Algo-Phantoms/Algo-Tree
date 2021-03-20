#Problem-Statement: Given two heads of singly linked-lists headA and headB, 
#return the node at which the two linked lists intersect.

#	 A :    3->7->2
#	               \
#		        5->6->4
#		       /
# 	 B : 1->9->0->8

# The node intersect at node with value 5. 
# Note: Do not alter the original structure of linked list after function returns.

# Node class 
class Node:  
    # Function to initialise the node object 
    def __init__(self, data): 
        self.val = data  # Assign data 
        self.next = None  # Initialize next as null 
  
  
# Linked List class contains a Node object 
class LinkedList:  
    # Function to initialize head 
    def __init__(self): 
        self.head = None
        

# 1. Brute force approach: 
# For each node in linkedlist A, traverse over other linkedlist B, 
# and check whether the node is present in B.
# Time complexity: O(m*n) ~ O(n^2), Space complexity: O(1)
# Caution: We are comparing nodes here, not value present in each node. Value can repeat.

def getIntersectNode(headA, headB):
	ptr1 = headA
	while ptr1:
		ptr2 = headB
		while ptr2:
			if ptr1 == ptr2:
				return ptr1
			ptr2 = ptr2.next
		ptr1 = ptr1.next
	return None # if two linked list do not intersect
	
# 2. Using two pointers
# The two linkedlist might not have same length,
# Therefore, we must jump few steps ahead in longer list, so that length with smaller linkedlist 
# becomes equal and start comparing simultaneously to reach a common at common Node.
# Algorithm : With 4 loops, one after the other, each doing the following:
# the length of list A.
# the length of list B.
# Set the start pointer for the longer list.
# Step the pointers through the list together.

def twoPointerIntersect(headA, headB):
    ptr1 = headA
    ptr2 = headB
    n1=n2=0
    while ptr1:
        n1 +=1
        ptr1 = ptr1.next
    
    while ptr2:
        n2 += 1
        ptr2 = ptr2.next
    
    diff = abs(n2-n1)
    c = 0
    ptr1 = headA
    ptr2 = headB
    if n2 < n1:
        while ptr1:
            if c==diff:
                break
            ptr1 = ptr1.next
            c+=1
        while ptr1 and ptr2:
            if ptr1==ptr2:
                return ptr1
            ptr1 = ptr1.next
            ptr2 = ptr2.next
        return None           
        
    else:
        while ptr2:
            if c==diff:
                break
            ptr2 = ptr2.next
            c+=1
        while ptr1 and ptr2:
            if ptr1==ptr2:
                return ptr1
            ptr1 = ptr1.next
            ptr2 = ptr2.next
        return None
 

if __name__ == '__main__':
# uncomment below lines of code to manually enter input of user's choice.
#	print(" Enter length of the first linked list ")
#	m = int(input())
#	print(" Enter the length of only uncommon nodes in second linked list ")
#	n = int(input())
#	intersect_node = headA = headB = prev = None
#	flag = 1
#	listA = LinkedList()
#	listB = LinkedList()
#	print("Enter data nodes in Linkedlist 1")
#	for i in range(m):
#		print("Enter data for Node"+str(i+1))
#		data = input()
#		if headA is None:
#			headA = Node(data)
#			listA.head = headA
#			prev = headA
#		else:
#			prev.next = Node(data)
#			prev = prev.next
#			if flag:
#				print("Is this node point of intersection 1 or 0")
#				if int(input()) == 1:
#					intersect_node = prev
#					flag = 0

#	print("Enter data of uncommon nodes in Linkedlist 2")
#	for i in range(n):
#		print("Enter data for Node"+str(i+1))
#		data = input()
#		if headB is None:
#			headB = Node(data)
#			listB.head = headB
#			prev = headB
#		else:
#			prev.next = Node(data)
#			prev = prev.next
#	prev.next = intersect_node

	listA = LinkedList()
	listA.head = Node(3)
	node2a = Node(7)
	node3a = Node(2)
	node4a = Node(5)
	node5a = Node(6)
	node6a = Node(4)
	listA.head.next = node2a
	node2a.next = node3a
	node3a.next = node4a
	node4a.next = node5a
	node5a.next = node6a

	listB = LinkedList()
	listB.head = Node(1)
	node2b = Node(9)
	node3b = Node(0)
	node4b = Node(8)
	listB.head.next = node2b
	node2b.next = node3b
	node3b.next = node4b
	node4b.next = node4a

	intersect1 = getIntersectNode(listA.head,listB.head)
	print("The intersection node of two linked list is "+str(intersect1.val))
	
	intersect2 = twoPointerIntersect(listA.head,listB.head)
	print("The intersection node of two linked list is "+str(intersect2.val))
	
# TestCase:
# Input:
# 1st: 3->7->2->5->6->4
# 2nd: 1->9->0->8->5->->6->4

# Output:
# The intersection node of two linked list is 5

	
