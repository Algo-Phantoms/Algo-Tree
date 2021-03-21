#Ques: Construct a binary tree from its given preorder and inorder traversal
#language: Python 3


class new_node:                   #class to create a node which has three section 1.store data, 2.address of node left to this node, 3.address of node right to this node
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

index=0       #global variable which is use in create_tree function to fetch the value store at index in preorder
def create_tree(inorder,preorder,st,end): #recursive funtion to create tree using its preorder and inorder traversal where st and end is the starting and ending indexes and
                                        #between these indexes we have to arrange nodes everytime also intial values are 0 and len(inorder)-1 respectively
    global index
    if st>end:      #base case
        return None

    new_root=new_node(preorder[index])    #as preorder give us root value everytime 
    index+=1
    if st==end:   #if this node has no children then return
        return new_root
    find_ind=search(inorder,st,end,new_root.data)
    #otherwise create left and right subtree
    new_root.left=create_tree(inorder,preorder,st,find_ind-1)
    new_root.right=create_tree(inorder,preorder,find_ind+1,end)
    return new_root

def search(values,start,end,data):    #search for data in array btw provided indexes 
    for i in range(start,end+1):
        if values[i]==data:
            return i

def postorder(root):  #prints tree in order : left, right and root
    if root is None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.data, end=" ")

def Inorder(root):  #prints tree in order : left, root and right
    if root is None:
        return
    postorder(root.left)
    print(root.data, end=" ")
    postorder(root.right)

def Preorder(root):  #prints tree in order : root, left and right
    if root is None:
        return
    print(root.data, end=" ")
    postorder(root.left)
    postorder(root.right)

    
if __name__=='__main__':
    inOrder = [5 , 15 , 18 , 20 , 25 , 30 , 35 , 40 , 45 , 50 , 60]
    preOrder = [30 , 20 , 15 , 5 , 18 , 25 , 40 , 35 , 50 , 45 , 60]
    root=create_tree(inOrder,preOrder,0,len(inOrder)-1)     #output should be [5 18 15 25 20 35 45 60 50 40 30]
    postorder(root)
    print(" - Postorder traversal of a Binary tree using inorder and preorder traversal. ")