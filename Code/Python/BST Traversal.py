# Traversal is a process to visit all the nodes of a tree and may print their values too. Because all nodes are connected 
# via edges(links) we always start from the root(head) node. So, we cannot randomly access a node in a tree.
#
# There are three ways which we use to traverse a tree −
# Inorder Traversal:
# 1.Traverse the left subtree.
# 2.Visit the root.
# 3.Traverse the right subtree.
#
# Preorder Traversal:
# 1.Visit the root.
# 2.Traverse the left subtree.
# 3.Traverse the right subtree.
#
# Postorder Traversal:
# 1.Traverse the left subtree.
# 2.Traverse the right subtree.
# 3.Visit the root.

class Node:
    #Initialization of Node
    def __init__(self,key):
        self.left=None
        self.right=None
        self.val=key

def preOrder(root):
    if(root):
        print(root.val,end=' ')
        preOrder(root.left)
        preOrder(root.right)

def postOrder(root):
    if (root):
        postOrder(root.left)
        postOrder(root.right)
        print(root.val,end=' ')

def inOrder(root):
    if (root):
        inOrder(root.left)
        print(root.val,end=' ')
        inOrder(root.right)

root=Node(5)
root.left=Node(3)
root.right=Node(7)
root.left.left=Node(2)
root.left.right=Node(4)

print("PreOrder Traversal of the given tree: ")
preOrder(root)

print("\nInOrder Traversal of the given tree: ")
inOrder(root)

print("\nPostOrder Traversal of the given tree: ")
postOrder(root)

# Testcase 1:
# Output:
# PreOrder Traversal of the given tree:
# 5 3 2 4 7
# InOrder Traversal of the given tree:
# 2 3 4 5 7
# PostOrder Traversal of the given tree:
# 2 4 3 7 5
#
# Testcase 2:
# Output:
# PreOrder Traversal of the given tree:
# 1 2 4 5 3
# InOrder Traversal of the given tree:
# 4 2 5 1 3
# PostOrder Traversal of the given tree:
# 4 5 2 3 1

# Time Complexity=O(n)
# Space Complexity=If we don’t consider size of stack for function calls then O(1) otherwise O(n).