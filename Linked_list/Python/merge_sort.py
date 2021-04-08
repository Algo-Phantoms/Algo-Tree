#Ques: Apply merge-sort in Linked-list
#Language: Python3

#Basically we are dividing the linked list from the middle until we are left with only one node as single node is always sorted and then we will merge two part of linked list in sorted order

#input:                     --->in first line we are taking number of nodes 
#                                                   ----->then in each n new lines we are taking data for nodes
#
#output:                                       ----->first line would have data of linked list in given order
#                                                                   ----->last line would give us sorted linked list values

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class Linked_list:
    def __init__(self):
        self.head = None

    def insert_node(self,data):
        node=Node(data)
        if self.head==None:
            self.head=node
        else:
            temp=self.head
            while temp.next!=None:
                temp=temp.next
            temp.next=node
        return self.head

    def merge_linked_list(self, a, b):
        result = None
        if a == None:
            return b
        if b == None:
            return a

        if a.data <= b.data:
            result = a
            result.next = self.merge_linked_list(a.next, b)
        else:
            result = b
            result.next = self.merge_linked_list(a, b.next)
        return result

    def mergeSort(self, h):
        if h == None or h.next == None:
            return h
        mid = self.getMiddle(h)
        nexttomid = mid.next
        mid.next = None
        left = self.mergeSort(h)
        right = self.mergeSort(nexttomid)
        res = self.merge_linked_list(left, right)
        return res

    def getMiddle(self, head):
        if (head == None):
            return head

        f = head
        f1 = head

        while (f1.next != None and f1.next.next != None):
            f = f.next
            f1 = f1.next.next
        return f


def print_ll(head):
    if head is None:
        print(' ')
        return
    curr_node = head
    while curr_node:
        print(curr_node.data, end=" ")
        curr_node = curr_node.next
    print(' ')

if __name__=="__main__":
    n=int(input('Enter number of node in first ll:'))
    ll1=Linked_list()
    new=Node(0)
    for i in range(n):
        d=int(input())
        root=ll1.insert_node(d)
    print('linked list:',end=" ")
    print_ll(root)

    root=ll1.mergeSort(root)
    print("After merge-sort: ",end="")
    print_ll(root)

#Time complexity:   O(n*logn)
#Space complexity: O(n*logn)

#e.g-1)
#Enter number of node in first ll:5
#11
#2
#12
#4
#15
#First ll: 11 2 12 4 15
#After merge-sort: 2 4 11 12 15

#e.g-2)
#Enter number of node in first ll:4
#12
#1
#155
#5
#First ll: 12 1 155 5
#After merge-sort: 1 5 12 155



