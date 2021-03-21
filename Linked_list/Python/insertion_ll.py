#Ques: Insertion sort in linked list
#Language: Python
#input: Enter no. of nodes you want:    (provide number of node)
#                                       (enter each data in newline)
#output:                                (sorted array)


class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

def insertion_sort(href):
  sorted_list = None
  cur_list = href
  while (cur_list != None):
    next = cur_list.next
    sorted_list = sort(sorted_list, cur_list)
    cur_list = next
  href = sorted_list
  return href

def sort(href, node):
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

def push(href, data):
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
   # print("\nLinked List after insertion sorting: ")
    printlist(ll)