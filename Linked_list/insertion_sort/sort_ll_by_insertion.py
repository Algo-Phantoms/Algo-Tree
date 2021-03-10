#Ques: Apply insertion sorting algorithm to sort a linked-list
#Insertion-sort-Each time we will compare value store at current node with the value next to it if it is greater than next one then swap them,keep on doing utill to reach NULL


class Node:   #creating nodes here
  def __init__(self, data):
    self.data = data
    self.next = None

def insertion_sort(href):
  sorted_list = None
  cur_list = href   #first node is always sorted so we will start from second node
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
    print(temp.data)
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
    ll = insertion_sort()
    print("\nLinked List after insertion sorting: ")
    printlist(ll)
