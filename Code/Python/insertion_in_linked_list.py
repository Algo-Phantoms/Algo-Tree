'''
Problem Statement :
Insertion in a Linked List : A linked list is a data structure used for storing collections of data. 
Inserting element in the linked list involves reassigning the pointers from the existing nodes to the newly inserted node.
We have different methods to insert data into a linked list.
* Inserting at the Beginning of the Linked List:
This method takes an argument append at the beginning of the linked list.
* Inserting at the End of the Linked List:
This method takes an argument append at the end of the linked list.
*Inserting in between two Data Nodes:
   * Insertion of elements after a given node:
   This method takes an argument add it after the given element of the linked list.
   * Insertion of elements before a given node
   This method takes an argument add it before the given element of the linked list.
'''

# Node structure having 2 fields : data and next(points next node in the list)
class Node:
	def __init__(self, data=None):
		self.data = data
		self.ref = None


class LinkedList:
	def __init__(self):
		self.__head=None
		self.__size=0

	# this method has time complexity : O(1)
	def add_at_begin(self,data):
		''' this method takes an argument append at the beginning of the linked list '''
		new_node=Node(data)
		new_node.ref=self.__head
		self.__head=new_node
		self.__size+=1

	# this method has time complexity : O(n)
	def add_at_end(self,data):
		''' this method takes an argument append at the end of the linked list '''
		if self.isEmpty():
			print("The given element was not found, since the list is empty.")
		else:
			n=self.__head
			while n.ref is not None:
				n=n.ref
			new_node=Node(data)
			n.ref=new_node
			self.__size+=1

	# this method has time complexity : O(n)
	def add_after_node(self,data,x):
		''' this method takes an argument add it after the given element of the linked list '''
		if self.isEmpty():
			print("Can't add after specified node",x,"Since, the LL is empty.")
			return
		n=self.__head
		while n is not None:
			if n.data==x:
				break
			n=n.ref
		if n is None:
			print("Given node",x,"not found in LL.")
			return
		elif n.ref==None: #add after the last node
			new_node=Node(data)
			n.ref=new_node			
		else:
			new_node=Node(data)
			new_node.ref=n.ref
			n.ref=new_node
		self.__size+=1

	# this method has time complexity : O(n)
	def add_before_node(self,data,x):
		''' this method takes an argument add it before the given element of the linked list '''
		if self.isEmpty():
			print("LL is empty, so can't perform the add_before_node method.")
		elif self.__head.data==x: #adding before first node
			new_node=Node(data)
			new_node.ref=self.__head
			self.__head=new_node
			self.__size+=1
		else:
			n=self.__head
			while n.ref is not None: #if n.ref is None, it means that we have to insert before the last node
				if n.ref.data==x:
					break
				n=n.ref
			if n.ref is None:
				print("Given node",x,"was not found in the LL")
				return
			else:
				new_node=Node(data)
				new_node.ref=n.ref
				n.ref=new_node
		self.__size+=1

	# this method has time complexity : O(n)
	def display(self):
		''' this method prints all the available data present in the list 
			and returns the data in linked-list like format '''
		if self.isEmpty():
			print("LL is empty.")
		else:
			n=self.__head
			while n is not None:
				print(n.data,'--->',end=' ')
				n=n.ref
		print()
		self.size_of_LL()

	# this method has time complexity : O(1)
	def isEmpty(self):
		''' this method returns True if the linked-kist is empty '''
		return(self.__head==None)

	# this method has time complexity : O(n)
	def size_of_LL(self):
		''' this method returns the length of the list '''
		print("Size of the LL:",self.__size)
	


'''
# Test Case :
LL1=LinkedList()
LL1.add_at_begin(15)
LL1.add_at_begin(35)
LL1.add_after_node(1500,15)
LL1.add_after_node(3500,35)
LL1.add_after_node(3500,385)
LL1.add_at_end(456)
LL1.add_before_node(7800,15)
LL1.add_before_node(7811,35)
LL1.add_before_node(7822,456)
LL1.add_before_node(92793,6387)
LL1.display()
LL1.size_of_LL()
LL1.display()
# OUTPUT :
Given node 385 not found in LL.
Given node 6387 was not found in the LL
7811 ---> 35 ---> 3500 ---> 7800 ---> 15 ---> 1500 ---> 7822 ---> 456 --->
Size of the LL: 9
Size of the LL: 9
7811 ---> 35 ---> 3500 ---> 7800 ---> 15 ---> 1500 ---> 7822 ---> 456 --->
Size of the LL: 9
'''