'''
Check whether a given binary tree is a Binary Search Tree

Given a binary tree, determine whether it is BST or not.
Input is given in order of root node, left child then
right child(preorder).
For e.g. 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
Tree looks like
              1
          /      \
      2           3
    /     \       /
  4       5     6

Since the node '2' is greater than root node '1'
which voilate the rule of BST, hence it is not BST.
'''

# A class to create a node
class Node:
    # Constructor to initialize node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# A function to build the tree in preorder manner
def MakeTree():
    val = int(input())
    if val == -1:
        return None
    root = Node(val)
    root.left = MakeTree()
    root.right = MakeTree()
    return root


def isBST(root, lptr, rptr):
 
    # Base condition
    if (root == None):
        return True
 
    # left child's data should
    # be less than root's data in BST
    if (lptr != None and lptr.data >= root.data):
        return False
 
    # right child's data should
    # be greater than root's data in BST
    if (rptr != None and rptr.data <= root.data):
        return False
 
    # checking recursively for every node.
    return isBST(root.left, lptr, root) and isBST(root.right, root, rptr)


print("Enter values in a binary tree: ")
# A function call to build the tree and return root node
root = MakeTree()
# Function returns true if the binary tree is BST else false
print(isBST(root, None, None))


'''
Test Cases
1.
Input:
Enter values in a binary tree:
1
2
4
-1
-1
5
-1
-1
3
6
-1
-1
-1

Output:
False

2.
Input:
Enter values in a binary tree:
4 
2
1
-1
-1
3
-1
-1
6
5
-1 
-1 
-1

Output:
True

Time Complexity:  O(n), for traversing the 'n' nodes

Space Complexity: O(1), since no extra space is used
'''
