#Ques: Find the middle data of the linked list
#Language: Python3

#First approach which comes in our mind is by using number of nodes and then get the mid node by dividing length of linked list by 2 but #we have more optimize approach for finding middle element of linkrd list, i.e
#by using two pointers of "Node" (datatype of our linked list) datatype which are temp and temp1 in our case and first temporary #variable stores address of head node and second one stores the address of next to next node and you will find that when temp1 reaches #NULL node that is last node then temp reaches the middle one

#input: Enter number of nodes in ll:(n)                    ---->user will provide an integer which is number of nodes
#                                                         --->in each n new lines user will provide data to be store in linked list



#output:                                    --->in first line arrow seperated list of integers will be printed 
#  Middle value of the linked list is __                                    --->next line will give us middle value of linked list

class Node:                         #datatype for linked list
    def __init__(self,data):
        self.data=data
        self.next=None

class Linked_list:
    def __init__(self):
        self.head=None

    def insert(self,data):
        x=Node(data)
        if self.head==None:
            self.head=x
        else:
            temp = self.head
            while temp.next!=None:
                temp=temp.next
            temp.next=x

        return self.head

    def print_ll(self):
        temp=self.head
        while temp!=None:
            print(temp.data,end="->")
            temp=temp.next
        print("NULL")

    def length_ll(self):
        temp=self.head
        l=0
        while temp!=None:
            l+=1
            temp=temp.next
        return l

    def find_middle(self):
        temp=self.head
        temp1=temp
        while temp1!=None and temp1.next!=None:

            temp=temp.next
            temp1=temp1.next.next

        return temp.data



if __name__=="__main__":
    n=int(input('Enter nuber of nodes in ll: '))
    ll=Linked_list()
    for i in range(n):
        d=int(input())
        root=ll.insert(d)
    ll.print_ll()

    print("Middle value of the linked list is " + str(ll.find_middle()))


"""
Time complexity: O(n)              --->n is number of nodes in linked list 
Space complexity: O(1)

e.g-1
input: Enter nuber of nodes in ll: 8
       3
       1
       2
       4
       6
       8
       7
       33
output: 3->1->2->4->6->8->7->33->NULL
        Middle value of the linked list is 6

e.g-2
input: Enter nuber of nodes in ll: 5
       1
       2
       3
       4
       5
ouput: 1->2->3->4->5->NULL
       Middle value of the linked list is 3
 """      
 
