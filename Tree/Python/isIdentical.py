#Ques: Check if two trees are identical or not.
#Language: Python3

#input:                                 ----->first line will demand for number of nodes in first tree(n)
#                                         ---->then in each new line we need to provide data of tree node first we will give data of root node(root1)
#                                          ---->then in each new(n-1) line we need to provide data of tree node
#then again same inputs will be provided for second tree as well
#ouput: first two line will give us space seperated data of both trees
#then in last line we will get final result weather provided trees are identical or not

class Node:
    def __init__(self,data):
        self.left=None
        self.data=data
        self.right=None

    def insert_node(self,data):
        if self.data:
            if data<self.data:
                if self.left==None:
                    self.left=Node(data)
                else:
                    self.left.insert_node(data)
            elif data>self.data:
                if self.right==None:
                    self.right=Node(data)
                else:
                    self.right.insert_node(data)
        else:
            self.data=data

    def print_tree(self):
        if self.left:
            self.left.print_tree()
        print(self.data,end=" ")
        if self.right:
            self.right.print_tree()



def isIdentical(root1,root2):
    if root2==None and root1==None:
        return True
    if root1!=None and root2!=None:
        return root1.data==root2.data and isIdentical(root1.left,root2.left) and isIdentical(root1.right,root2.right)

    return False




if __name__=="__main__":
    n=int(input('Enter number of nodes in first tree: '))
    data=int(input('Root1 data:'))
    root1=Node(data)
    for i in range(n-1):
        data=int(input('Data: '))
        root1.insert_node(data)

    m = int(input('Enter number of nodes in second tree: '))
    data = int(input('Root2 data:'))
    root2 = Node(data)
    for i in range(m-1):
        data=int(input('Data: '))
        root2.insert_node(data)
    print("First tree: ")
    root1.print_tree()
    print("\nSecond tree: ")
    root2.print_tree()
    print()
    if(isIdentical(root1,root2)):
        print("Yup! both trees are identical")
    else:
        print("Nope! non-identical")


#Time Complexity: Complexity of the identicalTree() will be according to the tree with lesser number of nodes.

#e.g-1)
# Enter number of nodes in first tree: 5
#Root1 data:12
#Data: 3
#Data: 11
#Data: 9
#Data: 11
#Enter number of nodes in second tree: 4
#Root2 data:11
#Data: 4
#Data: 122
#Data: 4
#3 9 11 12
#4 11 122
#Nope! non-identical

#e.g-2)
#Enter number of nodes in first tree: 5
#Root1 data:12
#Data: 22
#Data: 1
#Data: 4
#Data: 5
#Enter number of nodes in second tree: 5
#Root2 data:1
#Data: 4
#Data: 5
#Data: 22
#Data: 12
#First tree:
#1 4 5 12 22
#Second tree:
#1 4 5 12 22
#Nope! non-identical


