#Ques: Rotate linked list given numbers of times
#Language: Python3

#input:                                         ---->user will enter number of nodes
#                                                   --->in each n new line user will enter data for linked list
#output:                                           -->First line of output will give us actual linked list datas seperated by arrow
#input:                                                     -->Then user will be asked for number of rotation
#output:                                                ----->new rotated linked list seperated by arrow

class node:
    def __init__(self, data):
        self.data = data
        self.next = None


class linked_list:
    def __init__(self):
        self.head = None

    def insert_node(self, value):
        newnode = node(value)
        if self.head == None:
            self.head = newnode
        else:
            temp = self.head
            while temp.next != None:
                temp = temp.next
            temp.next = newnode
        return self.head

    def viewll(self):
        temp = self.head
        while temp != None:
            print(temp.data, end="->")
            temp = temp.next
        print("Null")

    def rotate_ll(self,times):
        temp=self.head
        if times==0:
            return
        cnt=1
        while(cnt<times and temp!=None):
            cnt+=1
            temp=temp.next
        if temp==None:
            return
        k=temp
        while temp.next!=None:
            temp=temp.next
        temp.next=self.head
        self.head=k.next
        k.next=None



if __name__=="__main__":
    n=int(input('Enter number of nodes:'))
    ll=linked_list()
    for i in range(n):
        x=int(input())
        root=ll.insert_node(x)
    ll.viewll()
    p=int(input('Number of times ll to be rotated: '))
    ll.rotate_ll(p)
    ll.viewll()


#time complexity: O(n)
#Space complexity: O(n)

#e.g-1)
#Enter number of nodes:6
#10
#20
#44
#5
#12
#1
#10->20->44->5->12->1->Null
#Number of times ll to be rotated: 2
#44->5->12->1->10->20->Null

#e.g-2)
#Enter number of nodes:5
#10
#20
#30
#40
#50
#10->20->30->40->50->Null
#Number of times ll to be rotated: 4
#50->10->20->30->40->Null