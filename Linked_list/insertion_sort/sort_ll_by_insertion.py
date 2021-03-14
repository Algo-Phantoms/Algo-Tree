#Ques: Apply insertion sorting algorithm to sort a linked-list
#Insertion-sort = Each time we will compare value store at current node with the value next to it, if it is greater than next one then swap them,keep on doing utill to reach NULL
#input: Enter no. of node u want:(n)     ------>here user will provide an integer which will be no. of node in linked list
#                                    ------->from next line user will provide n integers each time in new line 


#output : .........             --->sorted n space seperated integers using insertion sort in linked list

class Node:   #creating class Nodes here
  def __init__(self, data):
    self.data = data
    self.next = None

def insertion_sort(href):   #this is the function which will sort the linked list and takes address of head node as parameter
  sorted_list = None      #this will we use as temporary l-list
  cur_list = href   #first node is always sorted hence we will start from second node
  while (cur_list != None):
    next = cur_list.next
    sorted_list = sort(sorted_list, cur_list)     #using "sort" function to sort linked list from last sorted node to current node 
    cur_list = next
  href = sorted_list      
  return href

def sort(href, node):       #this function takes address of latest sorted node as "href" and address of current node upto which linked list is to be sorted as "node"
  current = None
  if (href == None or href.data >= node.data):
    node.next = href
    href = node
  else:
    current = href
    while (current.next != None and current.next.data < node.data):
      current = current.next
    node.next = current.next
    current.next = node
  return href

def printlist(head):
  temp = head
  while(temp != None):
    print(temp.data,end=" ")
    temp = temp.next

def push(href, data):         #this function inserts new node in linked list at its end everytime we call
  node = Node(0)
  node.data = data
  node.next = href
  href = node
  return href

# Driver program to test above functions
if __name__=='__main__':
    ll = None
    n=int(input('Enter no. of nodes you want: '))
    for i in range(n):
        x=int(input())
        ll=push(ll,x)       
    #printlist(ll)
    ll = insertion_sort(ll)
    print("\nLinked List after insertion sorting: ",end=" ")
    printlist(ll)
