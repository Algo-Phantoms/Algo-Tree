"""
Ques: Check weather provided linked list is palindrome or not
Language: Python3

class "node" is user defined datatype to create node such that it should have two section one for integer data and second for storing #address of next node, and class "linked_list" which has several defined function i.e, insert_node for linking nodes , viewll is for #printing linked list data and finally isPalindrome which takes head address of linked list to cheack weather is palindrom or not

input: Enter number of node you need:                  //user will be asked for no. of nodes, and after providing number of nodes user #                                                           should provide that many integers in new line everytime

output:                           //then in output user can view space seperated integers which he entered and in next line he/#                                              she can find weather this linked list is palindrome
"""
class node:
    def __init__(self,data):
        self.data=data
        self.next=None

class linked_list:
    def __init__(self):
        self.head=None
    def insert_node(self,value):
        newnode=node(value)
        if self.head==None:
            self.head=newnode
        else:
            temp=self.head
            while temp.next!=None:
                temp=temp.next
            temp.next=newnode
        return self.head


    def viewll(self):
        temp=self.head
        while temp!=None:
            print(temp.data,end=" ")
            temp=temp.next

    def isPalindrom(self,head):                         #in this function we are storing half part of linked list in reverse oredr and #                                                     then we are comparing it with remaining half part
        
        if not head and not head.next:
            return True
        rev = None
        l1 = head
        l2 = head

        while l1 and l1.next:
            l1 = l1.next.next
            l2 = l2.next
        temp=None
        while l2:
            temp=l2
            l2=l2.next
            temp.next=rev
            rev=temp

        while l2 :
            if l2.data != rev.data:
                return False
            rev = rev.next
            l2 = l2.next

        return True



if __name__=="__main__":
    n = int(input("Enter number of node you need:"))
    Node = linked_list()
    while n>0:
        x = int(input())
        ll=Node.insert_node(x)
        n-=1
    Node.viewll()
    print('\n')
    print(Node.isPalindrom(ll))

#time complexity: O(n)
#space : O(1)

"""
e.g:
Input: Enter number of node you need:5
       1
       2
       1
       2
       1
Output: 1 2 1 2 1
       True
e.g.
Input: Enter number of node you need:1
       9
Output: 9
       True
"""
