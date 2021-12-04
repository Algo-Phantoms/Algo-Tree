#Ques: Check weather tree is sum tree or not
#Language: Python3

#Sum-tree = When the sum of data of left subtree and right subtree is equal to data of root node, leaf node is also a sumtree


#output:                    ------->first line would give us space seperated integers in proper order
    #                           --->second line will print "true" if tree is sum-tree else "False"

class Node:
    def __init__(self,data):
        self.left=None
        self.data=data
        self.right=None


def insert_node(root,data):
    x=Node(data)
    if root==None:
        return Node(data)
    else:
        if root.data==data:
            return root
        elif root.data>data:
            root.right=insert_node(root.right,data)
        elif data>root.data:
            root.left=insert_node(root.left,data)
    return root

def inorder(root):
    if root!=None:
        inorder(root.left)
        print(root.data,end=" ")
        inorder(root.right)


def sum_subtree(root):
    if root==None:
        return 0
    return (root.data+sum_subtree(root.left)+sum_subtree(root.right))

def isSumtree(root):
    if root==None or (root.left==None and root.right==None):
        return True
    left=sum_subtree(root.left)
    right=sum_subtree(root.right)
    if(root.data==left+right and isSumtree(root.left) and isSumtree(root.right)):
        return True
    return False

if __name__=="__main__":
    root = Node(26)
    root.left = Node(10)
    root.right = Node(3)
    root.left.right = Node(4)
    root.left.left = Node(6)

    root.right.left = Node(3)
    inorder(root)
    print()
    print(isSumtree(root))


#6 10 4 26 3 3

#output: True
