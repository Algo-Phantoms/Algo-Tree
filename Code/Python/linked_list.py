'''
Problem Statement :

Linked List : A linked list is a data structure used for storing collections of data. 
A linked list has the following properties.

• Successive elements are connected by pointers

• The last element points to NULL

• Can grow or shrink in size during execution of a program

• Can be made just as long as required (until systems memory exhausts)

• Does not waste memory space (but takes some extra memory for pointers). It allocates memory as list grows.

Main Linked Lists Operations :
• Insert: inserts an element into the list

• Delete: removes and returns the specified position element from the list

Auxiliary Linked Lists Operations :
• Delete List: removes all elements of the list (disposes the list)

• Count: returns the number of elements in the list

• Find nth Node from the end of the list

'''

# Node structure having 2 fields : data and next(points next node in the list)
class Node:
	def __init__(self, data=None):
		self.data = data
		self.next = None


class LinkedList:
	def __init__(self, *args):
		self.head = Node()
		for value in args:
			self.insert(value)

	# this method have time complexity : O(n)
	def insert(self, data):
		''' this method takes an argument append at the end of list '''
		try:
			temp = self.head
			new = Node(data)
			while temp.next != None:
				temp = temp.next
			temp.next = new
			return
		except Exception as e:
			raise e

	# this method have time complexity : O(n)
	def display(self):
		''' this method print all available data present in the list 
			and also return the data in list format '''
		try:
			elements = []
			temp = self.head
			while temp.next != None:
				temp = temp.next
				elements.append(temp.data)
			print(elements)
			return elements
		except Exception as e:
			raise e

	# this method have time complexity : O(n)
	def delete(self, position):
		''' this method takes an index position (start from 0) and remove that index element and return that value '''
		try:
			position = int(position)
			if position<0 or position>=self.count():
				raise 'Error : Invalid index Position !!!'
			else:
				cur = self.head
				index = 0
				while True:
					previous_node = cur
					cur = cur.next
					if index == position:
						previous_node.next = cur.next
						return cur.data
					index += 1
		except Exception as e:
			raise e

	# this method have time complexity : O(1)
	def delete_all(self):
		''' this method removes all elements present in the list '''
		self.head = Node()

	# this method have time complexity : O(n)
	def count(self):
		''' this method returns the length of the list '''
		temp = self.head
		total_items = 0
		while temp.next != None:
			total_items += 1
			temp = temp.next
		return total_items

	def get_Nth_last(self, position):
		''' this method returns the value of specified position from the last '''
		try:
			position = int(position)
			if position<0:
				raise 'Error : Invalid index Position !!!'
			total = self.count()
			ans = self.__get(total-position)
			return ans
		except Exception as e:
			raise e

	# this is a special method of the class...
	def __get(self, position):
		if position<0:
			raise 'Error : Invalid index Position !!!'
		cur = self.head
		index = 0
		while True:
			cur = cur.next
			if index == position:
				return cur.data
			index += 1



'''
# Test Case :

ls = LinkedList('sujoy','aot','mechanical engineering')
ls.insert(10)
ls.insert(20)
ls.insert(30)
ls.insert(40)
ls.display()
print(ls.delete(0))
print(ls.count())
ls.display()
print(ls.get_Nth_last(5))



# OUTPUT :

['sujoy', 'aot', 'mechanical engineering', 10, 20, 30, 40]
sujoy
6
['aot', 'mechanical engineering', 10, 20, 30, 40]
mechanical engineering 

'''
