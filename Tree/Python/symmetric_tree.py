#Ques: Check weather a binary tree is symmetric or not
#language: Python

#Symmetric tree: When the coresponding values of node at same level is equal with respect to the root node than the tree is said to be #symmetric tree.
#For tree to be Symmetric,the following three conditions must hold
 #       1. The root node data must be same
 #      2. left subtree of left tree and right subtree of the right tree have to be mirror images
#       3. right subtree of left tree and left subtree of right tree have to be mirror images


class new_node:     #creates tree node
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

def inorder(root):      #prints data of tree in order like: left ,root then right.
    if root:
        inorder(root.left)
        print(root.data,end=" ")
        inorder(root.right)

def isSymmetric(rootl,rootr):   #this function checks weather the tree is symmetric or not
    if rootl==None and rootr==None:
        return True
    elif rootl.data==rootr.data:
        return isSymmetric(rootl.left,rootr.right) and isSymmetric(rootl.right,rootr.left)

def checkSymmetry(root):   
    return isSymmetric(root,root)


if __name__=='__main__':
    print("First Example: ")
    root=new_node(9)
    root.left=new_node(2)
    root.right = new_node(2)
    root.left.left = new_node(12)
    root.left.right = new_node(3)
    root.right.left = new_node(3)
    root.right.right = new_node(12)
    inorder(root)
    if checkSymmetry(root):
        print(" => Yes! it is symmetric.")
    else:
        print(" => Not symmetric!")

    print("\nSecond Example: ")
    root = new_node(19)
    root.left = new_node(2)
    root.right = new_node(20)
    root.left.left = new_node(1)
    root.left.right = new_node(3)
    root.right.left = new_node(31)
    root.right.right = new_node(12)

    inorder(root)
    if checkSymmetry(root):
        print(" => Yes! it is symmetric.")
    else:
        print(" => Not symmetric!")




#Time complexity: O(n)          
#output: 
#First Example: 
#12 2 3 9 3 2 12 => Yes! it is symmetric.

#Second Example: 
#1 2 3 19 31 20 12 => Not symmetric!