'''
Reversing linkedlist in groups of size k
Approach:
1. We count the length of the linkedlist.
2. We consider a group of size k -> We need to reverse K-1 edges in each group and
     when the count of the nodes < k, the rest of the linkedlist remains as it is. We use some pointers for this purpose:
     cur= first node of size k group
     nex = second node of size k group
     pre= node previous then current node
'''

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class LinkedList:
        def __init__(self):
                self.head=None
        def addNode(self, data):
                new_node=ListNode(data)
                new_node.next=self.head
                self.head=new_node
        def printList(self):
                tmp=self.head
                while tmp:
                        print(tmp.val, end=" ")
                        tmp=tmp.next
                print()
        # reversing the linkedlist in groups of size k             
        def reverseList(self, A, k):
                dummy=ListNode(0)
                # dummy node points to the head of the linked list
                dummy.next=A
                pre=nex=cur=dummy

                # for calculating the length of the linkedlist
                count=0
                while cur.next!=None:
                    cur=cur.next 
                    count+=1
                
                while count>=k:
                    cur=pre.next # first node of size k group
                    nex=cur.next # nex is second node of size k group
                    for i in range(0,k-1):
                        # for reversing the links
                        cur.next=nex.next
                        nex.next=pre.next
                        pre.next=nex
                        nex=cur.next
                        
                    count-=k
                    pre=cur # pre is made to last node of size k group
                    
                return dummy.next

for _ in range(int(input())):
        l=LinkedList()
        n=int(input())
        nodes=list(map(int, input().split()))
        for i in nodes[::-1]:
                l.addNode(i)
        k=int(input())
        new_head=LinkedList()
        new_head=l.reverseList(l.head,k)
        l.head=new_head
        l.printList()

'''
Test cases:

Input 1:
1
8
1 2 3 4 5 6 7 8
3
Output:
3 2 1 6 5 4 7 8

Input 2:
1
8
1 2 3 4 5 6 7 8
4
Output:
4 3 2 1 8 7 6 5

Time complexity: O(N/K)*K  = O(N)
( N/K is the number of groups of size K and for every group we do K-1 iterations)
Space complexity: O(1), for storing pointers.
'''
